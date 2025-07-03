/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroramirez <alejandroramirez@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:42:57 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/02 17:45:27 by alejandrora      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"

void Animal::makeSound() const
{
	std::cout << "Animal sound....." << std::endl;
}
		
Animal::Animal(std::string type) 
	: type(type) 
{
	std::cout << "Animal constructor called with type: "<< type << std::endl;
}

Animal::Animal() 
{
	type = "Unknown Animal";
	std::cout << "Default Animal constructor called" << std::endl;
}

Animal::~Animal(void) 
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const 
{
	return type;
}
