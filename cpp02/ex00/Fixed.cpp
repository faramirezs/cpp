/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:42:28 by alramire          #+#    #+#             */
/*   Updated: 2025/07/05 13:42:54 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return(integer);
}

void Fixed::setRawBits( int const raw )
{
    integer = raw;
}

Fixed::Fixed(Fixed const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed & Fixed::operator=( Fixed const & rhs ) 
{
    
    std::cout << "Assignment operator called" << std::endl;
    if (this != &rhs) 
    {
        this->integer = rhs.getRawBits();
    }
    return *this;
}

Fixed::Fixed()
    :integer(0)
{
    std::cout << "Default constructor called" << "\n";
}

Fixed::~Fixed()
{
    std::cout <<"Destructor called" << "\n";
}