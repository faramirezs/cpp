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

# include "Wanimal.hpp"

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

Wanimal::~Wanimal(void) 
{
	std::cout << "Wrong Animal destructor called" << std::endl;
}

std::string Wanimal::getType() const 
{
	return type;
}

void Wcat::makeSound() const
{
	std::cout << "wrong Miau... Wrong Miua.. Wrong mishuuuu... rrRRrrrrrRR" << std::endl;
}
		
Wcat::Wcat() 
	: Wanimal("WrongCat")
{
	std::cout << "Wrong Cat constructor called with type: "<< type << std::endl;
}

Wcat::~Wcat(void) 
{
	std::cout << "Wrong Cat destructor called" << std::endl;
}
