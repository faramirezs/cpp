# include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
}
void Zombie::announce(void)
{
    std::cout << Zombie::name << ": BraiiiiiiinnnzzzZ..." << "\n";
}
Zombie::~Zombie(void)
{
    std::cout << Zombie::name << ": Bye bye..." << "\n";
}