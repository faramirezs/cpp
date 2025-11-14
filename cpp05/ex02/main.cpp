/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:46:46 by alramire          #+#    #+#             */
/*   Updated: 2025/11/14 08:34:18 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

int main( void ) 
{   
    
    // try
    // {
    //     Bureaucrat joe(0, "Joe");
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    // try
    // {
    //     Bureaucrat noa(151, "Noa");
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    // Bureaucrat bob;
    // std::cout << bob;
    
    // std::cout << "Try decrement" << std::endl;
    
    // try
    // {
    //     bob.decrementGrade();
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    // std::cout << bob;

    // Bureaucrat ali(1,"Ali");
    // std::cout << ali;
    
    // std::cout << "Try increment" << std::endl;
    
    // try
    // {
    //     ali.incrementGrade();
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    // std::cout << ali;

    // std::cout << bob;
    
    // std::cout << "Try increment" << std::endl;
    
    // try
    // {
    //     bob.incrementGrade();
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    // std::cout << bob;


    std::cout << "Sign a form." << std::endl;
    
    try
    {
        Bureaucrat mike(15, "Mike");
        Form form("B58", false, 20, 45);
        std::cout << mike << std::endl;
        std::cout << form << std::endl;
        mike.signForm(form);
        std::cout << form << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat kemi(21, "Kemi");
        Form forme("B57", false, 20, 45);
        std::cout << kemi << std::endl;
        std::cout << forme << std::endl;
        kemi.signForm(forme);
        std::cout << forme << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat kami(150, "Kami");
        Form formi("B56", false, 150, 45);
        std::cout << kami << std::endl;
        std::cout << formi << std::endl;
        kami.signForm(formi);
        std::cout << formi << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}