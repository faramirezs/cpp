/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:42:57 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/05 15:21:29 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

void ClapTrap::attack(const std::string& target)
{
	if(hit > 0 && energy > 0)
	{
		std::cout << "ClapTrap "<< name << " attacks " << target << " causing " << attack_damage << " points of damage!" << std::endl;
		energy--;
	}
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

ClapTrap::~ClapTrap(void) 
{
	std::cout << "ClapTrap destructor called" << std::endl;
}
