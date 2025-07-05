/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 10:06:47 by alramire          #+#    #+#             */
/*   Updated: 2025/07/05 10:06:49 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANB_H__
#define __HUMANB_H__

# include <string>
# include <iostream>
# include <limits>
# include <iomanip>
# include <stdlib.h>
# include <stdio.h>
# include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon *weaponHB;
    public:
        void setWeapon(Weapon &weaponHB);
        void attack(void);
        HumanB(void);
        HumanB(std::string name);
        ~HumanB(void);
};

#endif