/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:42:57 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/05 15:29:01 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap: High-fives?" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if(hit > 0 && energy > 0)
	{
		std::cout << "FragTrap "<< name << " attacks " << target << " causing " << attack_damage << " points of damage!" << std::endl;
		energy--;
	}
}

FragTrap::FragTrap(std::string name) 
	: ClapTrap(name, 100, 100, 30) 
{
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::~FragTrap(void) 
{
	std::cout << "FragTrap destructor called" << std::endl;
}