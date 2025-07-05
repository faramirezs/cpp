/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:44:19 by alramire          #+#    #+#             */
/*   Updated: 2025/07/05 13:50:31 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
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
    :fxpnt(i*(1 << frbts))
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