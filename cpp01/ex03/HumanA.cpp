# include "Zombie.hpp"

Zombie* newZombie(std::string name) //heap allocation
{
    Zombie *heapZombie;
    heapZombie = new Zombie(name);
    //heapZombie->name = name;
    return heapZombie;
}