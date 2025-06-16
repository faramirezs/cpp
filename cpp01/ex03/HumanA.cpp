# include "HumanA.hpp"

void HumanA::attack(void)
{
    std::cout << HumanA::name << " attacks with their " << HumanA::weaponHA.getType() << "\n";

}
HumanA::HumanA(std::string nme, const Weapon &wponHA)
    :name(nme), weaponHA(wponHA)
{
    
}

HumanA::~HumanA(void)
{
    std::cout << HumanA::name << " destroyed." << "\n";
}