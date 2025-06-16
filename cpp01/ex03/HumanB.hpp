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
        Weapon *ptrweaponHB;
        //Weapon &refweaponHB;
    public:
        void setWeapon(Weapon weaponHB);
        void attack(void);
        HumanB(void);
        HumanB(std::string name);
        ~HumanB(void);
};

#endif