/* # include "Weapon.hpp"
# include "HumanA.hpp"
# include "HumanB.hpp" */

# include <string>
# include <iostream>
# include <limits>
# include <iomanip>
# include <stdlib.h>
# include <stdio.h>
# include <cctype>

int main(int ac, char **av)
{
    if(ac != 3)
        return 1;
    std::string s0 = av[0];
    std::string s1 = av[1];
    std::string s2 = av[2];
    
    std::cout << "Count: " << ac << "String0: " << s0 << "\n";
    std::cout << "Count: " << ac << "String1: " << s1 << "\n";
    std::cout << "Count: " << ac << "String2: " << s2 << "\n";
    /* {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.attack();
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    } */
    return 0;
}