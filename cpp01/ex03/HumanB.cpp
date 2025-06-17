# include "HumanB.hpp"

void HumanB::setWeapon(Weapon &wponHB)
{
    weaponHB = &wponHB;
    std::cout << name << " takes a weapon." << "\n";
}

void HumanB::attack(void)
{
    if(weaponHB == NULL)
        std::cout << name << " has no weapon to attack." << "\n";
    else
        std::cout << name << " attacks with their " << weaponHB->getType() << ".\n";
}

HumanB::HumanB(std::string nme)
    :name(nme), weaponHB(NULL)
{
    std::cout << name << " is ready to run or take a weapon." << "\n";
}

HumanB::~HumanB(void)
{
    std::cout << name << " destroyed." << "\n";
}