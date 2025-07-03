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

# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) 
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name) 
{
	hit = FragTrap::hit;
    energy = ScavTrap::energy;
    attack_damage = FragTrap::attack_damage;
	std::cout << "DiamondTrap constructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "I'm DiamondTrap" << name << " derived from " << ClapTrap::name << std::endl;
}