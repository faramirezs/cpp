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
/* 
Add the following public constructors and public member functions to your class:
• A constructor that takes a constant integer as a parameter.
It converts it to the corresponding fixed-point value. The fractional bits value
should be initialized to 8, like in exercise 00.
• A constructor that takes a constant floating-point number as a parameter.
It converts it to the corresponding fixed-point value. The fractional bits value
should be initialized to 8, like in exercise 00.
• A member function float toFloat( void ) const;
that converts the fixed-point value to a floating-point value.
• A member function int toInt( void ) const;
that converts the fixed-point value to an integer value.

And add the following function to the Fixed class files:
• An overload of the insertion («) operator that inserts a floating-point representation
of the fixed-point number into the output stream object passed as a parameter.

*/



#endif