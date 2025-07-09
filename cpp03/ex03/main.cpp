/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:42:46 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/09 09:03:56 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include "DiamondTrap.hpp"


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
	scav_dodo.guardGate();

	std::cout << "===FragTrap=== "<< std::endl;
	FragTrap frag_dada("dada");
	frag_dada.attack("calvo");
	frag_dada.takeDamage(1);
	frag_dada.beRepaired(1);
	frag_dada.highFivesGuys();

	std::cout << "===DiamondTrap=== "<< std::endl;
	DiamondTrap diam_dada("dudu");
	diam_dada.attack("calvo");
	diam_dada.takeDamage(1);
	diam_dada.beRepaired(1);
	diam_dada.whoAmI();

	std::cout << "===Destructors=== "<< std::endl; */

	std::cout << "=== DiamondTrap Constructor Test ===" << std::endl;
	DiamondTrap diam_dada("dudu");

	std::cout << "\n=== Attack Test ===" << std::endl;
	diam_dada.attack("calvo");

	std::cout << "\n=== Take Damage Test ===" << std::endl;
	diam_dada.takeDamage(1);

	std::cout << "\n=== Repair Test ===" << std::endl;
	diam_dada.beRepaired(1);

	std::cout << "\n=== Who Am I Test ===" << std::endl;
	diam_dada.whoAmI();

	std::cout << "\n=== Copy Constructor Test ===" << std::endl;
	DiamondTrap diam_copy(diam_dada);
	diam_copy.whoAmI();

	std::cout << "\n=== Assignment Operator Test ===" << std::endl;
	DiamondTrap diam_assigned;
	diam_assigned = diam_dada;
	diam_assigned.whoAmI();

	std::cout << "\n=== Energy Depletion Test ===" << std::endl;
	for (int i = 0; i < 55; ++i)
		diam_dada.attack("someone");

	std::cout << "\n=== Final whoAmI ===" << std::endl;
	diam_dada.whoAmI();

	std::cout << "\n=== DiamondTrap Destructor Test ===" << std::endl;
	return 0;

	return (0);
}


