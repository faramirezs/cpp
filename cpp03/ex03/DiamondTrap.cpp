/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:42:57 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/05 15:32:16 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) 
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name) 
{
	hit = FragTrap::hit;
    energy = ScavTrap::energy;
    attack_damage = FragTrap::attack_damage;
	std::cout << "DiamondTrap constructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
};

void DiamondTrap::whoAmI()
{
	std::cout << "I'm " << name << " derived from " << ClapTrap::name << std::endl;
}

DiamondTrap::~DiamondTrap(void) 
{
	std::cout << "Diamond destructor called" << std::endl;
}