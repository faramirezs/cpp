#ifndef __FIXED_H__
#define __FIXED_H__

# include <string>
# include <iostream>
# include <limits>
# include <iomanip>
# include <stdlib.h>
# include <stdio.h>
# include <cctype>
# include <algorithm>
# include <cmath>

class Fixed
{
    private:
        int fxpnt;
        static const int frbts = 8;

    public:
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
        Fixed(const int);
        Fixed(const float);
        Fixed& operator=(Fixed const & rhs);
        bool operator==(const Fixed & rhs) const;
        bool operator!=(const Fixed & rhs) const;
        bool operator>(const Fixed & rhs) const;
        bool operator<(const Fixed & rhs) const;
        bool operator>=(const Fixed & rhs) const;
        bool operator<=(const Fixed & rhs) const;
        Fixed operator+(const Fixed & rhs) const;
        Fixed operator-(const Fixed & rhs) const;
        Fixed operator*(const Fixed & rhs) const;
        Fixed operator/(const Fixed & rhs) const;
        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);
        Fixed(Fixed const & src);
        Fixed(void);
        ~Fixed(void);
};

std::ostream & operator<<(std::ostream & ost, Fixed const & fxd);

#endif
