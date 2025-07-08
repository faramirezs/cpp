/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wanimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:42:57 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/07 17:13:24 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Wanimal.hpp"

Wanimal& Wanimal::operator=(Wanimal const & rhs)
{
	std::cout << "Assignment constructor called." << std::endl;
	if(this != &rhs)
	{
		this->type = rhs.type;
	}
	return(*this);
}

Wanimal::Wanimal(Wanimal const & src) : type(src.type)
{
	std::cout << "Copy constructor called." << std::endl;
}

Wanimal::~Wanimal(void) 
{
	std::cout << "Wrong Animal destructor called" << std::endl;
}

void Wanimal::makeSound() const
{
	std::cout << "Wrong Animal sound....." << std::endl;
}
		
Wanimal::Wanimal(std::string type) 
	: type(type) 
{
	std::cout << "Wrong Animal constructor called with type: "<< type << std::endl;
}

Wanimal::Wanimal() 
{
	type = "Unknown Animal";
	std::cout << "Default Wrong Animal constructor called" << std::endl;
}

std::string Wanimal::getType() const 
{
	return type;
}
