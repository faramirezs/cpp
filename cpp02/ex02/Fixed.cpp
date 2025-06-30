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
    i = roundf(fxpnt / pow(2,frbts));
    return (i);
    //converts the fixed-point value to an integer value.
}

Fixed::Fixed(Fixed const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    std::cout << "Copy constructor: this=" << this << ", src=" << &src << std::endl;
    //std::cout << "NEW object fxpnt before assignment: " << this->fxpnt << std::endl;
    //*this = src;
    fxpnt = src.fxpnt;  // Direct assignment instead
}

Fixed & Fixed::operator=( Fixed const & rhs ) {
    
    std::cout << "Assignment operator called" << std::endl;
    //std::cout << "this: " << *this << std::endl;
    //std::cout << "rhs: " << rhs << std::endl;
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

Fixed::Fixed(const int i)
    :fxpnt(0)
{
    fxpnt = i*pow(2,frbts);
    std::cout <<"constructor with int called"<<std::endl;
    //It converts it to the corresponding fixed-point value. The fractional bits value
    //should be initialized to 8, like in exercise 00.
}

Fixed::Fixed(const float f)
    :fxpnt(0)
{
    fxpnt = roundf(f*pow(2,frbts));
    std::cout <<"constructor with float called"<<std::endl;

    /* std::cout <<"round: " << roundf(f*pow(2,frbts)) <<std::endl;
    std::cout <<"no round: " << f*pow(2,frbts) <<std::endl;

    float original = f;
    float multiplied = original * 256;
    std::cout << "3.7 * 256 = " << multiplied << std::endl; */
    //It converts it to the corresponding fixed-point value. The fractional bits value
    //should be initialized to 8, like in exercise 00
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

bool Fixed::operator==(const Fixed & rhs) const
{
    return(!(this->fxpnt < rhs.fxpnt) && !(this->fxpnt > rhs.fxpnt));
}

bool Fixed::operator!=(const Fixed & rhs) const
{
    return(!(*this == rhs));
}

bool Fixed::operator>(const Fixed & rhs) const 
{
    return(!(*this == rhs) && this->fxpnt > rhs.fxpnt);
}

bool Fixed::operator<(const Fixed & rhs) const 
{
    return(!(*this == rhs) && !(*this > rhs));
}

bool Fixed::operator>=(const Fixed & rhs) const
{
    return((*this == rhs) || (*this > rhs));
}

bool Fixed::operator<=(const Fixed & rhs) const
{
    return((*this == rhs) || (*this < rhs));
}

Fixed& Fixed::operator+(Fixed const & rhs)
{
    this->fxpnt = this->fxpnt + rhs.fxpnt;
    return(*this);
}

Fixed& Fixed::operator-(Fixed const & rhs)
{
    this->fxpnt = this->fxpnt - rhs.fxpnt;
    return(*this);
}

Fixed& Fixed::operator*(Fixed const & rhs)
{
    this->fxpnt = ((float)(this->fxpnt * (float)rhs.fxpnt) / pow(2,frbts));
    return(*this);
}

Fixed& Fixed::operator/(Fixed const & rhs)
{
    this->fxpnt = ((float)this->fxpnt / (float)rhs.fxpnt) * pow(2,frbts);
    return(*this);
}

Fixed& Fixed::operator++()
{
    this->fxpnt = (float)this->fxpnt +  (1 / pow(2,frbts));
    return (*this);
}

Fixed Fixed::operator++(int)
{
    std::cout << "Creating tmp copy..." << std::endl;
    Fixed tmp(*this);  // or
    //Fixed tmp = *this; // or  
    //tmp = *this;
    std::cout << "tmp created, now incrementing..." << std::endl;    
    //tmp = *this;
    this->fxpnt = (float)this->fxpnt +  (1 / pow(2,frbts));
    return (tmp);
}
/* Fixed& Fixed::operator--()
{}
Fixed& Fixed::operator--(int)
{} */
