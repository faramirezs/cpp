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
        void addName(std::string name);
        Zombie(std::string name);
        Zombie(void);
        ~Zombie(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);
Zombie* zombieHorde( int N, std::string name );

#endif