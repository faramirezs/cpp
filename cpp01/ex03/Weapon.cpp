# include "Weapon.hpp"

const std::string &Weapon::getType(void) const
{
    //What is the difference between returning this->type or just type?
    //Which can match the return? why?
    //Which creates a copy, why?
    return(this->type);
}

void Weapon::setType(const std::string tpe)
{
    Weapon::type = tpe;//setType
    std::cout << Weapon::type << " weapon type set." << "\n";
}

Weapon::Weapon()
{
    //Do I always need a default constructor?
    std::cout << Weapon::type << " weapon created (default const)." << "\n";
}

Weapon::Weapon(std::string tpe)
    :type(tpe)
{
    //Here what would be the difference between using this->type Vs. Weapon::type ?
    //Weapon::type = tpe;
    std::cout << Weapon::type << " weapon created." << "\n";
}

Weapon::~Weapon()
{
    std::cout << Weapon::type << " destroyed." << "\n";
    //Why in this case I can access directly type, without using getType()
}