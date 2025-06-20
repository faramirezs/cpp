# include "Weapon.hpp"

const std::string &Weapon::getType(void) const
{
    return(type);
}

void Weapon::setType(const std::string tpe)
{
    type = tpe;
    std::cout << Weapon::type << " weapon type set." << "\n";
}

Weapon::Weapon()
{
    //std::cout << Weapon::type << " weapon created (default const)." << "\n";
}

Weapon::Weapon(std::string tpe)
    :type(tpe)
{
    std::cout << type << " weapon created." << "\n";
}

Weapon::~Weapon()
{
    std::cout << type << " destroyed." << "\n";
}