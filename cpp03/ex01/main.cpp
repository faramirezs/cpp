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

# include "ClapTrap.hpp"

int main(void)
{
	ClapTrap peludo("peludo");
	peludo.attack("calvo");
	peludo.takeDamage(1);
	peludo.beRepaired(1);
	return (0);
}


