# include <string>
# include <iostream>
# include <limits>
# include <iomanip>
# include <stdlib.h>
# include <stdio.h>
# include <cctype>
# include "Fixed.hpp"

int main( void ) 
{
    std::cout << "3 is " << Fixed(3).toInt() << " as integer" << std::endl;
    /* Fixed a(42);
    Fixed b(3.7f);
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "a is " << a.toFloat() << " as float" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toFloat() << " as float" << std::endl;
     */
    
    /* Fixed f1(3.7f);
    std::cout << "toFloat: " << f1.toFloat() << std::endl;
    std::cout << "roundf: " << roundf(f1.toFloat()) << std::endl;  // What do you expect vs what do you get? */
    
    /* Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );

    a = Fixed( 1234.4321f );

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    std::cout << "a is " << a.toFloat() << " as float" << std::endl;
    std::cout << "b is " << b.toFloat() << " as float" << std::endl;
    std::cout << "c is " << c.toFloat() << " as float" << std::endl;
    std::cout << "d is " << d.toFloat() << " as float" << std::endl;
     */
    return 0;
}