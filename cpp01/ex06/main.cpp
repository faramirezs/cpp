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
# include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Wrong input. Use only: 'DEBUG', 'INFO', 'WARNING' or 'ERROR'. "<< '\n';
        return 1;
    }
    
    Harl myHarl;
    std::string *ptr = NULL;
    size_t i = -1;
    std::string lev[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    ptr = std::find(lev, lev+4, av[1]);
    if (ptr == lev+4)
    {
        std::cout << "Wrong input. Use only: 'DEBUG', 'INFO', 'WARNING' or 'ERROR'. "<< '\n';
        return 1;
    }
    i = ptr - lev;
    switch(i) {
    case 0:
        myHarl.complain("debug");
        myHarl.complain("info");
        myHarl.complain("warning");
        myHarl.complain("error");
        break;
    case 1:
        myHarl.complain("info");
        myHarl.complain("warning");
        myHarl.complain("error");
        break;
    case 2:
        myHarl.complain("warning");
        myHarl.complain("error");
        break;
    case 3:
        myHarl.complain("error");
        break;
    default:
        myHarl.complain("");
    }
    
    return 0;
}