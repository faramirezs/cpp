/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:42:57 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/08 18:28:15 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: name(""), hit(0), energy(0), attack_damage(0) 
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) 
	: name(name), hit(10), energy(10), attack_damage(0) 
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src)
	: name(src.name), hit(src.hit), energy(src.energy), attack_damage(src.attack_damage) 
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const & rhs)
{
	if(this != &rhs)
	{
		this->name = rhs.name;
		this->hit = rhs.hit;
		this->energy = rhs.energy;
		this->attack_damage =  rhs.attack_damage;
	}
}

ClapTrap::~ClapTrap(void) 
{
	std::cout << "ClapTrap destructor called" << std::endl;
}



void ClapTrap::attack(const std::string& target)
{
	if(hit > 0 && energy > 0)
	{
		std::cout << "ClapTrap "<< name << " attacks " << target << " causing " << attack_damage << " points of damage!" << std::endl;
		energy--;
	}
	else
		std::cout << "ClapTrap "<< name << "run out of energy" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	hit = hit - amount;
	std::cout << "ClapTrap "<< name << " damaged by " << amount << " new hit points balance: " << hit << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(hit > 0 && energy > 0)
	{
		hit = hit + amount;
		std::cout << "ClapTrap "<< name << " repaired by " << amount << " new hit points balance: " << hit << std::endl;
		energy--;
	}
}

ClapTrap::ClapTrap(std::string name) 
	: name(name), hit(10), energy(10), attack_damage(0) 
{
	std::cout << "ClapTrap constructor called" << std::endl;
}


