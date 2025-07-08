/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:42:57 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/08 14:31:16 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AMateria.hpp"

AMateria::AMateria() 
{
	std::cout << "Default AMateria constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) 
	: type(type) 
{
	std::cout << "AMateria constructor called with type: "<< type << std::endl;
}

AMateria::AMateria(AMateria const & src) : type(src.type)
{
	std::cout << "AMateria copy constructor called." << std::endl;
}

AMateria& AMateria::operator=(AMateria const & rhs)
{
	std::cout << "AMateria assignment constructor called." << std::endl;
	if(this != &rhs)
	{
		this->type = rhs.type;
	}
	return(*this);
}

AMateria::~AMateria(void) 
{
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Materia use in " << target.getName() << std::endl;
}