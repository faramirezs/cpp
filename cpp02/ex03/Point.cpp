/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 14:11:03 by alramire          #+#    #+#             */
/*   Updated: 2025/07/05 14:11:04 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Point.hpp"

Point::Point(Point const & src)
{
    *this = src;
}

Point & Point::operator=( Point const & rhs ) 
{
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

}

