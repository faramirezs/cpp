/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:42:57 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/08 11:59:08 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cure.hpp"

Cure::Cure()
	: AMateria("Cure")
{
	std::cout << "Default Cure constructor called" << std::endl;
}

// Cure::Cure(std::string type) 
// 	: type(type) 
// {
// 	std::cout << "Cure constructor called with type: "<< type << std::endl;
// }

Cure::Cure(Cure const & src) 
	: AMateria(src)
{
	std::cout << "Cure copy constructor called." << std::endl;
}

Cure& Cure::operator=(Cure const & rhs)
{
	std::cout << "Cure assignment constructor called." << std::endl;
	if(this != &rhs)
	{
		AMateria::operator=(rhs);
	}
	return(*this);
}

Cure::~Cure(void) 
{
	std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone() const
{
	AMateria * twin;
	twin = new Cure(*this);
	return twin;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds * " << std::endl; 
}