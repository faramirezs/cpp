/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:42:57 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/08 08:06:40 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"

Animal::Animal() 
{
	type = "Unknown Animal";
	std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(std::string type) 
	: type(type) 
{
	std::cout << "Animal constructor called with type: "<< type << std::endl;
}

Animal::Animal(Animal const & src) : type(src.type)
{
	std::cout << "Copy constructor called." << std::endl;
}

Animal& Animal::operator=(Animal const & rhs)
{
	std::cout << "Assignment constructor called." << std::endl;
	if(this != &rhs)
	{
		this->type = rhs.type;
	}
	return(*this);
}

Animal::~Animal(void) 
{
	std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Animal sound....." << std::endl;
}
		
std::string Animal::getType() const 
{
	return type;
}
