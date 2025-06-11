# include "Zombie.hpp"

int main(void)
{
    Zombie *foo;
    foo = newZombie("foo");
    foo->announce();
    delete foo;
    randomChump("faa");
    zombieHorde(10, "Alejiri");
    return 0;
}