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
        //const std::string &WeaponTypeRef;
        const Weapon &weaponHA;
    public:
        void attack(void);
        //HumanA(void);
        HumanA(std::string name, const Weapon &weaponHA);
        ~HumanA(void);
};


#endif