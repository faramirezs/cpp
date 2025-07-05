/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 14:08:52 by alramire          #+#    #+#             */
/*   Updated: 2025/07/05 14:09:11 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        static Fixed& min(Fixed& a, Fixed& b);
        static Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static Fixed& max(const Fixed& a, const Fixed& b);
        Fixed(Fixed const & src);
        Fixed(void);
        ~Fixed(void);
};

std::ostream & operator<<(std::ostream & ost, Fixed const & fxd);

#endif