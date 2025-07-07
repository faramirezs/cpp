/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wcat.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:42:57 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/07 17:08:33 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Wcat.hpp"

Wcat::Wcat() 
	: Wanimal("WrongCat")
{
	std::cout << "Wrong cat constructor called with type: "<< type << std::endl;
}

Wcat::Wcat(Wcat const & src) : Wanimal(src)
{
	std::cout << "Wrong cat Copy constructor called." << std::endl;
}

Wcat& Wcat::operator=(Wcat const & rhs)
{
	std::cout << "Wrong cat assignment constructor called." << std::endl;
	if(this != &rhs)
	{
		Wanimal::operator=(rhs);
	}
	return(*this);
}

Wcat::~Wcat(void) 
{
	std::cout << "Wrong cat destructor called" << std::endl;
}


void Wcat::makeSound() const
{
	std::cout << "wrong Miau... Wrong Miua.. Wrong mishuuuu... rrRRrrrrrRR" << std::endl;
}
		

