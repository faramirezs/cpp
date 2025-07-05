/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 10:06:05 by alramire          #+#    #+#             */
/*   Updated: 2025/07/05 10:06:07 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanA.hpp"

void HumanA::attack(void)
{
    std::cout << name << " attacks with their " << HumanA::weaponHA.getType() << ".\n";

}
HumanA::HumanA(std::string nme, const Weapon &wponHA)
    :name(nme), weaponHA(wponHA)
{
    std::cout << name << " is ready with a weapon." << "\n";
}

HumanA::~HumanA(void)
{
    std::cout << name << " destroyed." << "\n";
}