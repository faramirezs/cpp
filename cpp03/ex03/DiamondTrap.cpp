/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:42:57 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/09 08:22:35 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap() 
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) 
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name) 
{
	hit = FragTrap::hit;
    energy = ScavTrap::energy;
    attack_damage = FragTrap::attack_damage;
	std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src)
	: ClapTrap(src)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const & rhs)
{
	if(this != &rhs)
		ClapTrap::operator=(rhs);
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
