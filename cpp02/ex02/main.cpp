# include <string>
# include <iostream>
# include <limits>
# include <iomanip>
# include <stdlib.h>
# include <stdio.h>
# include <cctype>
# include <typeinfo>
# include "Fixed.hpp"

int main( void ) 
{        
    Fixed x(5);
    std::cout << "Before: " << x << std::endl;
    x++;
    std::cout << "After: " << x << std::endl;
    
    /* Fixed x(8.5f);  // float constructor
    Fixed y(2.1f);  // float constructor
    Fixed result = x * y;
    std::cout << "8.5 * 2.1 = " << result << std::endl;
    std::cout << "Result(int): " << result.toInt() << std::endl;
    std::cout << "Result(float): " << result.toFloat() << std::endl;
 */
    /* Fixed x(8.0f);
    Fixed y(2.0f);
    Fixed result = x / y;
    std::cout << "8 / 2 = " << result << std::endl; */
    
    /* Fixed x(2.11f);
    Fixed y(3.56f);
    Fixed result = x * y;
    std::cout << "Result: " << result << std::endl;
    std::cout << "Result(int): " << result.toInt() << std::endl;
    std::cout << "Result(float): " << result.toFloat() << std::endl; */
    //Fixed a;


    /* Fixed x(5);
    Fixed y(10);
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout <<"Fixed( 5.05f ) * Fixed( 2 ) raw: "<< b << std::endl;
    std::cout <<"Fixed( 5.05f ) * Fixed( 2 ) int: "<< b.toInt() << std::endl;
    std::cout <<"Fixed( 5.05f ) * Fixed( 2 ) float: "<< b.toFloat() << std::endl;
    std::cout <<"x = x(5) + y(10): "<< x + y << std::endl;
    std::cout <<"x = x(15) - y(10): "<< x - y << std::endl;
    x * y;
    std::cout <<"x = x(5) * y(10): "<< x.toInt() << std::endl;
    x / y;
    std::cout <<"x(50) / y(10): "<< x.toInt() << std::endl;
    if(x == y)
        std::cout <<"x == y" << std::endl;
    if(x != y)
        std::cout <<"x != y" << std::endl;
    if(x > y)
        std::cout <<"x > y" << std::endl;
    if(x < y)
        std::cout <<"x < y" << std::endl;
    if(x >= y)
        std::cout <<"x >= y" << std::endl;
    if(x <= y)
        std::cout <<"x <= y" << std::endl; */

    
    //std::cout << a << std::endl;
    //std::cout << ++a << std::endl;
    //std::cout << a << std::endl;
    //std::cout << a++ << std::endl;
    //std::cout << a << std::endl;
    
    //std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}