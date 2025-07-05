/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 09:20:58 by alramire          #+#    #+#             */
/*   Updated: 2025/07/05 11:17:29 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
    std::cout << Zombie::name << ": Knock KNOCK... (created)." << "\n";
}

void Zombie::announce(void)
{
    std::cout << Zombie::name << ": BraiiiiiiinnnzzzZ..." << "\n";
}

Zombie::~Zombie(void)
{
    std::cout << Zombie::name << ": Bye bye... (destroyed)." << "\n";
}