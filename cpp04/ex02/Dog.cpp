/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:42:57 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/08 11:02:18 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"

Dog::Dog() 
	: Animal("Dog") 
{
	brain = new Brain();
	std::cout << "Dog constructor called with type: "<< type << std::endl;
}

Dog::Dog(Dog const & src) : Animal(src)
{
	std::cout << "Dog copy constructor called." << std::endl;
	this->brain = new Brain(*src.brain);
}

Dog& Dog::operator=(Dog const & rhs)
{
	std::cout << "Dog assignment constructor called." << std::endl;
	if(this != &rhs)
	{
		if(this->brain)
			delete this->brain;
		this->brain = new Brain(*rhs.brain);
		Animal::operator=(rhs);
	}
	return(*this);
}

Dog::~Dog(void) 
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Guau...! Guuuuua!" << std::endl;
}

Brain &Dog::getBrain()
{
	return *brain;
}



