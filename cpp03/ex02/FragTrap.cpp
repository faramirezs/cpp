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
