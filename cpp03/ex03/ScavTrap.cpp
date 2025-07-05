/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:42:57 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/05 15:34:57 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if(hit > 0 && energy > 0)
	{
		std::cout << "ScavTrap "<< name << " attacks " << target << " causing " << attack_damage << " points of damage!" << std::endl;
		energy--;
	}
}

ScavTrap::ScavTrap(std::string name) 
	: ClapTrap(name, 100, 50, 20) 
{
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void) 
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

