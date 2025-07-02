#ifndef __POINT_H__
#define __POINT_H__

# include <string>
# include <iostream>
# include <limits>
# include <iomanip>
# include <stdlib.h>
# include <stdio.h>
# include <cctype>
# include <algorithm>
# include <cmath>
# include "Fixed.hpp"


class Point
{
    private:
        Fixed x;
        Fixed y;

    public:
        Point(Point const & src);
        Point(const float x, const float y): x(x), y(y) {};
        Point& operator=(Point const & rhs);
        bool operator==(const Point & rhs) const;
        Fixed get_x(void) const {return x;};
        Fixed get_y(void) const {return y;};
        Point(void): x(0), y(0) {};
        ~Point(void);
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
