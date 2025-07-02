# include "Point.hpp"

Point::Point(Point const & src)
{
    //std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Point & Point::operator=( Point const & rhs ) {

    //std::cout << "Assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->x = rhs.x;
		this->y = rhs.y;
    }
    return *this;
}

bool Point::operator==(const Point & rhs) const
{
	return (this->x == rhs.x && this->y ==rhs.y);
}

Point::~Point()
{
    //std::cout <<"Destructor called" << "\n";
}

