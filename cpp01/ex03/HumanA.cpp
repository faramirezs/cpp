# include "HumanA.hpp"

void HumanA::attack(void)
{
    std::cout << name << " attacks with their " << HumanA::weaponHA.getType() << ".\n";

}
HumanA::HumanA(std::string nme, const Weapon &wponHA)
    :name(nme), weaponHA(wponHA)
{
    std::cout << name << " is ready with a weapon." << "\n";
}

HumanA::~HumanA(void)
{
    std::cout << name << " destroyed." << "\n";
}