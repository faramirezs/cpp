/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 10:07:10 by alramire          #+#    #+#             */
/*   Updated: 2025/07/05 10:09:57 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON_H__
#define __WEAPON_H__

# include <string>
# include <iostream>
# include <limits>
# include <iomanip>
# include <stdlib.h>
# include <stdio.h>
# include <cctype>

class Weapon
{
    private:
        std::string type;
    
    public:
        const std::string &getType(void) const;
        void setType(std::string tpe);
        Weapon(std::string tpe);
        ~Weapon(void);
};


#endif