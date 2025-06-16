# include "HumanB.hpp"

void HumanB::setWeapon(Weapon wponHB)
{
    HumanB::ptrweaponHB = &wponHB;
    //HumanB::refweaponHB = wponHB;
}

void HumanB::attack(void)
{
    std::cout << HumanB::name << " attacks with their ptr " << HumanB::ptrweaponHB->getType() << "\n";
    //std::cout << HumanB::name << " attacks with their ref " << HumanB::refweaponHB.getType() << "\n";
}

HumanB::HumanB(std::string nme)
{
    HumanB::name = nme;
    std::cout << HumanB::name << " No ready with no weapon" << "\n";
    //It seems like the constructor needs to initialize a ref if its declared as class member
    //While if it is just a pointer as class member it does not need it.
}

HumanB::~HumanB(void)
{
    std::cout << HumanB::name << " destroyed." << "\n";
}