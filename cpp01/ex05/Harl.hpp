#ifndef __HARL_H__
#define __HARL_H__

# include <string>
# include <iostream>
# include <limits>
# include <iomanip>
# include <stdlib.h>
# include <stdio.h>
# include <cctype>

class Harl
{
    private:
        std::string type;
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
    
    public:
        void complain( std::string level );
        //Weapon(std::string tpe);
        Harl(void);
        ~Harl(void);
};


#endif