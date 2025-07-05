/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:47:59 by alramire          #+#    #+#             */
/*   Updated: 2025/07/05 13:59:09 by alramire         ###   ########.fr       */
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
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed & Fixed::operator=( Fixed const & rhs ) {
    
    std::cout << "Assignment operator called" << std::endl;
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
    std::cout << "Default constructor called" << "\n";
}

Fixed::Fixed(const int i)
    :fxpnt(i << frbts)
{
    std::cout <<"constructor with int called"<<std::endl;
}

Fixed::Fixed(const float f)
    :fxpnt(roundf(f*(1 << frbts)))
{
    std::cout <<"constructor with float called"<<std::endl;
}

Fixed::~Fixed()
{
    std::cout <<"Destructor called" << "\n";
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