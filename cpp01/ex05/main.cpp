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
    (void)ac;
    (void)av;

    Harl myHarl;
    myHarl.complain("debug");
    myHarl.complain("info");
    myHarl.complain("warning");
    myHarl.complain("error");
    myHarl.complain("");

    return 0;
}