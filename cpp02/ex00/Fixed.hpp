#ifndef __FIXED_H__
#define __FIXED_H__

# include <string>
# include <iostream>
# include <limits>
# include <iomanip>
# include <stdlib.h>
# include <stdio.h>
# include <cctype>
# include <algorithm>

class Fixed
{
    private:
        int integer;
        static const int scint = 8;
        
    public:
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        Fixed& operator=(Fixed const & rhs);
        Fixed(Fixed const & src);
        Fixed(void);
        ~Fixed(void);
};


#endif