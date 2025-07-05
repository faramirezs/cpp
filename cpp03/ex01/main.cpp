/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:42:46 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/05 14:30:18 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"

int main(void)
{
	ClapTrap clap_peludo("peludo");
	clap_peludo.attack("calvo");
	clap_peludo.takeDamage(1);
	clap_peludo.beRepaired(1);

	//ScavTrap
	ScavTrap scav_dodo("dodo");
	scav_dodo.attack("calvo");
	scav_dodo.takeDamage(1);
	scav_dodo.beRepaired(1);
	scav_dodo.guardGate();


	return (0);
}


