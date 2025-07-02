# include "Point.hpp"

Fixed area(Point const c, Point const d, Point const e)
{
	Fixed x1 = c.get_x();
    Fixed y1 = c.get_y();
    Fixed x2 = d.get_x();
    Fixed y2 = d.get_y();
    Fixed x3 = e.get_x();
    Fixed y3 = e.get_y();
	Fixed area = (x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));
	if (area < 0)
		area = area * Fixed(-1);
	area = area/2;
	return (area);
}

bool bsp( Point const a, Point const b, Point const c, Point const p)
{
	if(p == a || p == b || p == c )
		return (false);
	Fixed abc = area(a, b ,c);
	Fixed abp = area(a, b ,p);
	Fixed bpc = area(b, p ,c);
	Fixed apc = area(a, p ,c);
	if(abc == 0 || abp == 0 || bpc == 0 || apc == 0)
		return (false);
	Fixed cmp = abc - abp - bpc - apc;
	if (cmp == 0)
		return(true);
	return(false);
}
