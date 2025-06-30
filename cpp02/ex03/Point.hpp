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
        point(Point p);
        Point(const float x, const float y);
        Point& operator=(Fixed const & rhs);
        Point(Fixed const & src);
        Point(void) {x = 0, y=0};
        ~Point(void);
};

std::ostream & operator<<(std::ostream & ost, Fixed const & fxd);

#endif