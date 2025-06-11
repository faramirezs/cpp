# include "Zombie.hpp"

int main(void)
{
    Zombie *zHorde;
    zHorde = zombieHorde(10, "Alejiri");
    delete[] zHorde;
    return 0;
}