/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroramirez <alejandroramirez@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:43:01 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/02 17:45:48 by alejandrora      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP_H__
#define __CLAPTRAP_H__

# include <string>
# include <iostream>
# include <limits>
# include <iomanip>
# include <stdlib.h>
# include <stdio.h>
# include <cctype>
# include <algorithm>
# include <cmath>
# include "ClapTrap.hpp"


class ClapTrap
{
    public:
        std::string name;
		unsigned int hit;
		unsigned int energy;
		unsigned int attack_damage;

		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		ClapTrap(std::string name) : name(name), hit(10), energy(10), attack_damage(0) {std::cout << "Default ClapTrap constructor called" << std::endl;};
        ClapTrap(std::string name, unsigned int hit, unsigned int energy,  unsigned int attack_damage) : name(name), hit(hit), energy(energy), attack_damage(attack_damage) {std::cout << "ClapTrap constructor called by other Trap" << std::endl;};
		~ClapTrap(void) {std::cout << "ClapTrap destructor called" << std::endl;};
};

#endif
