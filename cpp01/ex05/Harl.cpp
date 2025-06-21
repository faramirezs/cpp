# include "Harl.hpp"

std::string * Harl::


Harl::complain()
{

}

void debug( void );
void info( void );
void warning( void );
void error( void );
void complain( std::string level );


Harl::Harl()
{
    std::cout << "Created." << "\n";
}

Harl::~Harl()
{
    std::cout <<"Destroyed." << "\n";
}