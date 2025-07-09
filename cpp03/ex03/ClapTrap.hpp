/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:43:01 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/09 08:14:35 by alramire         ###   ########.fr       */
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
    protected:
	
        std::string name;
		unsigned int hit;
		unsigned int energy;
		unsigned int attack_damage;
    
	public:

		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(std::string name, unsigned int hit, unsigned int energy,  unsigned int attack_damage);
		ClapTrap(ClapTrap const & src);
		ClapTrap& operator=(ClapTrap const & rhs);
		~ClapTrap(void);

		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
