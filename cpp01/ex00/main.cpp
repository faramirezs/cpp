/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 09:14:39 by alramire          #+#    #+#             */
/*   Updated: 2025/07/05 09:19:56 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int main(void)
{
    Zombie *foo;
    foo = newZombie("foo");
    foo->announce();
    delete foo;
    randomChump("faa");
    return 0;
}