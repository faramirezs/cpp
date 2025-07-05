/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 10:06:31 by alramire          #+#    #+#             */
/*   Updated: 2025/07/05 10:06:33 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANA_H__
#define __HUMANA_H__

# include <string>
# include <iostream>
# include <limits>
# include <iomanip>
# include <stdlib.h>
# include <stdio.h>
# include "Weapon.hpp"

class HumanA
{
    private:
        std::string name;
        const Weapon &weaponHA;
    public:
        void attack(void);
        HumanA(std::string name, const Weapon &weaponHA);
        ~HumanA(void);
};


#endif