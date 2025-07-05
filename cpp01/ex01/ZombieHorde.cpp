/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 09:26:32 by alramire          #+#    #+#             */
/*   Updated: 2025/07/05 09:26:34 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    (void)name;
    Zombie *zombieHorde;
    zombieHorde = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        zombieHorde[i].addName(name);
        zombieHorde[i].announce();
    }
    
    return zombieHorde;
}