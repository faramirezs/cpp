/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 14:10:24 by alramire          #+#    #+#             */
/*   Updated: 2025/07/05 14:13:47 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Point.hpp"

int main()
{
    //inside
    /* Point a(3.0f,9.0f);
    Point b(4.0f,3.0f);
    Point c(10.0f,8.0f);
    Point pnt(6.0f,7.0f); */

    //outside
    /* Point a(3.0f,9.0f);
    Point b(4.0f,3.0f);
    Point c(10.0f,8.0f);
    Point pnt(11.0f,7.0f); */

    //outside vertex
    /* Point a(3.0f,9.0f);
    Point b(4.0f,3.0f);
    Point c(10.0f,8.0f);
    Point pnt(10.0f,8.0f); */

    //edge
    Point a(0.0f, 0.0f);
    Point b(4.0f, 0.0f);
    Point c(2.0f, 3.0f);
    Point pnt(2.0f, 0.0f);


    if(bsp( a, b, c, pnt))
        std::cout << "******Inside******" << std::endl;
    else
        std::cout << "******Outside******" << std::endl;
    return 0;
}
