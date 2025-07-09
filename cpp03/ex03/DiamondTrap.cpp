/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:42:57 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/09 09:02:31 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap() 
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) 
	: ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), name(name) 
{
	hit = FragTrap::default_hit;
    energy = ScavTrap::default_energy;
    attack_damage = FragTrap::default_attack;
	std::cout << "DiamondTrap constructor called" << std::endl;
	std::cout << "Hit points from Frag: " << hit << std::endl;
	std::cout << "Energy points from Scav: " << energy << std::endl;
	std::cout << "attack_damage points from Frag: " << attack_damage << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src)
	: ClapTrap(src), ScavTrap(src), FragTrap(src), name(src.name)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const & rhs)
{
	if(this != &rhs)
	{
		ClapTrap::operator=(rhs);
		ScavTrap::operator=(rhs);
		FragTrap::operator=(rhs);
		name = rhs.name;
	}
		
	return (*this);
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
};

DiamondTrap::~DiamondTrap(void) 
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "I'm DiamondTrap name:" << name << " derived from ClapTrap Name: " << ClapTrap::name << std::endl;
}
