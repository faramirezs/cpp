# include "HumanA.hpp"

void HumanA::attack(void)
{
    std::cout << HumanA::name << " attacks with their " << HumanA::weaponHA.getType() << "\n";

}
HumanA::HumanA(std::string nme, Weapon wponHA)
{
    //Why do I need a default constructor for weapon here?
    HumanA::name = nme;
    HumanA::weaponHA = wponHA;
    std::cout << HumanA::name << " ready with " << HumanA::weaponHA.getType() << "\n";
}

HumanA::~HumanA(void)
{
    std::cout << HumanA::name << " destroyed." << "\n";
}