# include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
}
Zombie::Zombie(void)
{
}
void Zombie::announce(void)
{
    std::cout << Zombie::name << ": BraiiiiiiinnnzzzZ..." << "\n";
}
Zombie::~Zombie(void)
{
    std::cout << Zombie::name << ": Bye bye..." << "\n";
}
void Zombie::addName(std::string name)
{
    this->name = name;
}