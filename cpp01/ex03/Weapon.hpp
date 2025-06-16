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
        const std::string &getType(void);
        void setType(std::string tpe);
        Weapon(std::string tpe);
        Weapon(void);
        ~Weapon(void);
};


#endif