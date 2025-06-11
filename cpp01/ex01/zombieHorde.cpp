# include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    (void)name;
    Zombie *zombieHorde;
    zombieHorde = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        zombieHorde[i].addName(name);
        zombieHorde[i].announce();
    }
    
    return zombieHorde;
}