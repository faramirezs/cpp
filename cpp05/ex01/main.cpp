/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:46:46 by alramire          #+#    #+#             */
/*   Updated: 2025/11/11 13:38:52 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

int main( void ) 
{   
    
    try
    {
        Bureaucrat joe(0, "Joe");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat noa(151, "Noa");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    Bureaucrat bob;
    std::cout << bob;
    
    std::cout << "Try decrement" << std::endl;
    
    try
    {
        bob.decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << bob;

    Bureaucrat ali(1,"Ali");
    std::cout << ali;
    
    std::cout << "Try increment" << std::endl;
    
    try
    {
        ali.incrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << ali;

    std::cout << bob;
    
    std::cout << "Try increment" << std::endl;
    
    try
    {
        bob.incrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << bob;


    return 0;
}