/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 09:26:17 by alramire          #+#    #+#             */
/*   Updated: 2025/07/05 09:26:19 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
}
Zombie::Zombie(void)
{
}
void Zombie::announce(void)
{
    std::cout << Zombie::name << ": BraiiiiiiinnnzzzZ..." << "\n";
}
Zombie::~Zombie(void)
{
    std::cout << Zombie::name << ": Bye bye..." << "\n";
}
void Zombie::addName(std::string name)
{
    this->name = name;
}