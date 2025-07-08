/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:42:57 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/08 11:04:49 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"

Cat::Cat() 
	: Animal("Cat")
{
	brain = new Brain();
	std::cout << "Cat constructor called with type: "<< type << std::endl;
}

Cat::Cat(Cat const & src) : Animal(src)
{
	std::cout << "Cat copy constructor called." << std::endl;
	this->brain = new Brain(*src.brain);
}

Cat& Cat::operator=(Cat const & rhs)
{
	std::cout << "Cat assignment constructor called." << std::endl;
	if(this != &rhs)
	{
		if(this->brain)
			delete this->brain;
		this->brain = new Brain(*rhs.brain);
		Animal::operator=(rhs);
	}
	return(*this);
}

Cat::~Cat(void) 
{
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miau... Miua.. mishuuuu... rrRRrrrrrRR" << std::endl;
}

Brain &Cat::getBrain()
{
	return *brain;
}