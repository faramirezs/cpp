/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:42:57 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/09 12:08:48 by alramire         ###   ########.fr       */
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
	if(this != &rhs)
	{
		for (size_t i = 0; i < 4; i++)
		{
			if(slot[i])
			delete slot[i];
			if(rhs.slot[i])
			slot[i] = rhs.slot[i]->clone();
			else
			slot[i] = NULL;
		}
	}
	std::cout << "Character assignment constructor called." << std::endl;
	return(*this);
}

std::string const & Character::getName() const
{
	return name;
}

Character::~Character()
{
	for (size_t i = 0; i < 4; i++)
	{
		if(slot[i])
		{
			delete slot[i];
		}
	}
	std::cout << "Character destructor called." << std::endl;
}

void Character::equip(AMateria* m)
{
	if(!m)
	{
		std::cout <<"Non existant amateria" << std::endl;
		return;
	}
	for (size_t i = 0; i < 4; i++)
	{
		if(!slot[i])
		{
			slot[i] = m;
			return;
		}
	}
	return;
}

void Character::unequip(int idx)
{
	std::cout << "Unequip: " << slot[idx]->getType() << std::endl;
	slot[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	slot[idx]->use(target);
}