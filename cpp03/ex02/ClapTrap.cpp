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

# include "ClapTrap.hpp"

void ClapTrap::attack(const std::string& target)
{
	if(hit > 0 && energy > 0)
	{
		std::cout << "ClapTrap "<< name << " attacks " << target << " causing " << "any " << "points of damage!" << std::endl;
		attack_damage++;
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
