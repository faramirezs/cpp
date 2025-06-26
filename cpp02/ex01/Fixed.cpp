# include "Fixed.hpp"


int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return(fxpnt);
}

void Fixed::setRawBits( int const raw )
{
    fxpnt = raw;
}

float Fixed::toFloat( void ) const
{
    float f;
    f = fxpnt / pow(2,frbts);
    return(f);
}

int Fixed::toInt( void ) const
{
    int i;
    i = fxpnt / pow(2,frbts);
    return (i);
    //converts the fixed-point value to an integer value.
}

Fixed::Fixed(Fixed const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed & Fixed::operator=( Fixed const & rhs ) {
    
    std::cout << "Assignment operator called" << std::endl;
    if (this != &rhs) 
    {
        this->fxpnt = rhs.getRawBits();
    }
    return *this;
}

std::ostream & operator<<(std::ostream & ost, Fixed const & fxd)
{
    //std::cout << "<< operator called" << std::endl;
    ost << fxd.toFloat();
    return (ost); 
}


Fixed::Fixed()
    :fxpnt(0)
{
    std::cout << "Default constructor called" << "\n";
}

Fixed::~Fixed()
{
    std::cout <<"Destructor called" << "\n";
}

//Copy operator with init list
/* Fixed::Fixed(Fixed const & src)
    :integer(src.getRawBits())
{
    std::cout << "Copy constructor called" << std::endl;
} */

//float       roundf( float num );




Fixed::Fixed(const int i)
{
    fxpnt = i*pow(2,frbts);
    //It converts it to the corresponding fixed-point value. The fractional bits value
    //should be initialized to 8, like in exercise 00.
}

Fixed::Fixed(const float f)
{
    fxpnt = f*pow(2,frbts);
    //It converts it to the corresponding fixed-point value. The fractional bits value
    //should be initialized to 8, like in exercise 00
}
