# include "Weapon.hpp"
# include "HumanA.hpp"
# include "HumanB.hpp"


/*
In which case do you think it would be best to use a pointer to
Weapon? And a reference to Weapon? Why? Think about it before
starting this exercise.
*/


int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        std::cout << "Club address in main: " << &club << "\n";
        HumanA bob("Bob", club);
        //print the address of club in main and inside humana to see the difference.
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;
}


/* int main(void)
{
    Zombie *zHorde;
    zHorde = zombieHorde(10, "Alejiri");
    delete[] zHorde;
    return 0;
} */

/*Makefile, main.cpp, Weapon.{h, hpp}, Weapon.cpp, HumanA.{h,
hpp}, HumanA.cpp, HumanB.{h, hpp}, HumanB.cpp*/