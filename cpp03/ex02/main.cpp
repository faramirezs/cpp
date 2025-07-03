/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroramirez <alejandroramirez@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:42:46 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/02 16:42:17 by alejandrora      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

int main(void)
{
	/* std::cout << "===ClaTrap=== "<< std::endl;
	ClapTrap clap_peludo("peludo");
	clap_peludo.attack("calvo");
	clap_peludo.takeDamage(1);
	clap_peludo.beRepaired(1);

	std::cout << "===ScavTrap=== "<< std::endl;
	ScavTrap scav_dodo("dodo");
	scav_dodo.attack("calvo");
	scav_dodo.takeDamage(1);
	scav_dodo.beRepaired(1);
	scav_dodo.guardGate(); */

	std::cout << "===FragTrap=== "<< std::endl;
	FragTrap scav_dada("dada");
	scav_dada.attack("calvo");
	scav_dada.takeDamage(1);
	scav_dada.beRepaired(1);
	scav_dada.highFivesGuys();


	return (0);
}


