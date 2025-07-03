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

# include "Dog.hpp"

void Dog::makeSound() const
{
	std::cout << "Guau...! Guuuuua!" << std::endl;
}
		
Dog::Dog() 
	: Animal("Dog") 
{
	std::cout << "Dog constructor called with type: "<< type << std::endl;
}

Dog::~Dog(void) 
{
	std::cout << "Dog destructor called" << std::endl;
}


