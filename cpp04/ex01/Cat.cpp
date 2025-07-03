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

# include "Cat.hpp"

void Cat::makeSound() const
{
	std::cout << "Miau... Miua.. mishuuuu... rrRRrrrrrRR" << std::endl;
}
		
Cat::Cat() 
	: Animal("Cat")
{
	brain = new Brain();
	std::cout << "Cat constructor called with type: "<< type << std::endl;
}

Cat::~Cat(void) 
{
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}
