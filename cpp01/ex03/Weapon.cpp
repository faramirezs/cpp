/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 10:07:06 by alramire          #+#    #+#             */
/*   Updated: 2025/07/05 10:09:46 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"

const std::string &Weapon::getType(void) const
{
    return(type);
}

void Weapon::setType(const std::string tpe)
{
    type = tpe;
    std::cout << Weapon::type << " weapon type set." << "\n";
}

Weapon::Weapon(std::string tpe)
    :type(tpe)
{
    std::cout << type << " weapon created." << "\n";
}

Weapon::~Weapon()
{
    std::cout << type << " destroyed." << "\n";
}