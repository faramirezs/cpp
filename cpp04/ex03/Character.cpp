/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:42:57 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/08 15:59:11 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Character.hpp"
#include "AMateria.hpp"

Character::Character() 
{
	std::cout << "Default Character constructor called" << std::endl;
	for (int i = 0; i < 4; i++) 
	{
        slot[i] = NULL;
    }
}

Character::Character(std::string const & name) 
	: name(name) 
{
	std::cout << "Character constructor called with name: "<< name << std::endl;
	for (int i = 0; i < 4; i++) 
	{
        slot[i] = NULL;
    }
}

Character::Character(Character const & src) 
	: name(src.name)
{
	std::cout << "Character copy constructor called." << std::endl;
	for (size_t i = 0; i < 4; i++)
	{
		slot[i] = src.slot[i]->clone();
	}
	
}

Character& Character::operator=(Character const & rhs)
{
	std::cout << "Character assignment constructor called." << std::endl;
	if(this != &rhs)
	{
		for (size_t i = 0; i < 4; i++)
		{
			slot[i] = rhs.slot[i];
		}
	}
	return(*this);
}

std::string const & Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	for (size_t i = 0; i < 4; i++)
	{
		if(!slot[i])
		{
			slot[i] = m->clone();
			return;
		}
	}
	return;
}

void Character::unequip(int idx)
{
	(void)idx;
}

void Character::use(int idx, ICharacter& target)
{
	(void)idx;
	(void)target;
}