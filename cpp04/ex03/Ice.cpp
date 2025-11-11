/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:42:57 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/09 11:16:40 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Ice.hpp"

Ice::Ice()
	: AMateria("ice")
{
	std::cout << "Default Ice constructor called" << std::endl;
}

Ice::Ice(Ice const & src) 
	: AMateria(src)
{
	std::cout << "Ice copy constructor called." << std::endl;
}

Ice& Ice::operator=(Ice const & rhs)
{
	std::cout << "Ice assignment constructor called." << std::endl;
	if(this != &rhs)
	{
		AMateria::operator=(rhs);
	}
	return(*this);
}

Ice::~Ice(void) 
{
	std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone() const
{
	AMateria * twin;
	twin = new Ice(*this);
	return twin;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" <<std::endl; 
}