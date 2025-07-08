/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:42:57 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/08 08:07:04 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"

Cat::Cat() 
	: Animal("Cat")
{
	std::cout << "Cat constructor called with type: "<< type << std::endl;
}

Cat::Cat(Cat const & src) : Animal(src)
{
	std::cout << "Cat copy constructor called." << std::endl;
}

Cat& Cat::operator=(Cat const & rhs)
{
	std::cout << "Cat assignment constructor called." << std::endl;
	if(this != &rhs)
	{
		Animal::operator=(rhs);
	}
	return(*this);
}

Cat::~Cat(void) 
{
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miau... Miua.. mishuuuu... rrRRrrrrrRR" << std::endl;
}