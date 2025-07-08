/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:42:57 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/08 11:20:15 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Default Brain constructor called" << std::endl;
}

Brain::Brain(Brain const & src)
{
	std::cout << "Brain copy constructor called." << std::endl;
	for (int i = 0; i < 100; ++i)
		this->ideas[i] = src.ideas[i];
}

Brain& Brain::operator=(Brain const & rhs)
{
	std::cout << "Brain assignment constructor called." << std::endl;
	if(this != &rhs)
    {
        for(int i = 0; i < 100; i++)
        {
            this->ideas[i] = rhs.ideas[i];
        }
    }
	return(*this);
}

Brain::~Brain(void)	
{
	std::cout << "Brain destructor called" << std::endl;
}
