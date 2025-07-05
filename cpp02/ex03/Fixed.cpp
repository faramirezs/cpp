/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 14:08:36 by alramire          #+#    #+#             */
/*   Updated: 2025/07/05 14:12:39 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

int Fixed::getRawBits( void ) const
{
    return(fxpnt);
}

void Fixed::setRawBits( int const raw )
{
    fxpnt = raw;
}

float Fixed::toFloat( void ) const
{
    return static_cast<float>(fxpnt) / (1 << frbts);
}

int Fixed::toInt( void ) const
{
    return fxpnt >> frbts;
}

Fixed::Fixed(Fixed const & src)
{
    *this = src;
}

Fixed & Fixed::operator=( Fixed const & rhs ) {
    
    if (this != &rhs) 
    {
        this->fxpnt = rhs.getRawBits();
    }
    return *this;
}

std::ostream & operator<<(std::ostream & ost, Fixed const & fxd)
{
    ost << fxd.toFloat();
    return (ost); 
}

Fixed::Fixed()
    :fxpnt(0)
{
}

Fixed::Fixed(const int i)
    :fxpnt(i << frbts)
{
}

Fixed::Fixed(const float f)
    :fxpnt(roundf(f*(1 << frbts)))
{
}

Fixed::~Fixed()
{
}

bool Fixed::operator==(const Fixed & rhs) const
{
    return(!(this->fxpnt < rhs.fxpnt) && !(this->fxpnt > rhs.fxpnt));
}

bool Fixed::operator!=(const Fixed & rhs) const
{
    return(!(*this == rhs));
}

bool Fixed::operator>(const Fixed & rhs) const 
{
    return(!(*this == rhs) && this->fxpnt > rhs.fxpnt);
}

bool Fixed::operator<(const Fixed & rhs) const 
{
    return(!(*this == rhs) && !(*this > rhs));
}

bool Fixed::operator>=(const Fixed & rhs) const
{
    return((*this == rhs) || (*this > rhs));
}

bool Fixed::operator<=(const Fixed & rhs) const
{
    return((*this == rhs) || (*this < rhs));
}

Fixed Fixed::operator+(const Fixed & rhs) const
{
    Fixed res;
    res.setRawBits(this->fxpnt + rhs.fxpnt);
    return(res);
}

Fixed Fixed::operator-(const Fixed & rhs) const
{
    Fixed res;
    res.setRawBits(this->fxpnt - rhs.fxpnt);
    return(res);
}

Fixed Fixed::operator*(const Fixed & rhs) const
{
    Fixed res;
    long long mult = (long long)this->fxpnt * rhs.fxpnt;
    res.setRawBits((int)(mult) >> frbts);
    return(res);
}

Fixed Fixed::operator/(const Fixed & rhs) const
{
    Fixed res;
    if (rhs.fxpnt == 0) {
        std::cerr << "Error: Division by zero" << std::endl;
        return res;
    }
    long long dividend = ((long long)this->fxpnt << frbts);
    res.setRawBits((int)(dividend / rhs.fxpnt));
    return (res);
}

Fixed& Fixed::operator++()
{
    this->fxpnt += 1; 
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    ++(*this);
    return (tmp);
}

Fixed& Fixed::operator--()
{
    this->fxpnt -= 1;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    --(*this);
    return (tmp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? const_cast<Fixed&>(a) : const_cast<Fixed&>(b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}

Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? const_cast<Fixed&>(a) : const_cast<Fixed&>(b);
}
