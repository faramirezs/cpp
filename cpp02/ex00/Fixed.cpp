# include "Fixed.hpp"


int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return(integer);
}

void Fixed::setRawBits( int const raw )
{
    integer = raw;
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
        this->integer = rhs.getRawBits();
    }
    return *this;
}

Fixed::Fixed()
    :integer(0)
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