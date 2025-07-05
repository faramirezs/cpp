/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 09:21:20 by alramire          #+#    #+#             */
/*   Updated: 2025/07/05 09:21:23 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

# include <string>
# include <iostream>
# include <limits>
# include <iomanip>
# include <stdlib.h>
# include <stdio.h>
# include <cctype>

class Zombie
{
    private:
        std::string name;
    
    public:
        void announce(void);
        Zombie(std::string name);
        ~Zombie(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif