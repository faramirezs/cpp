/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:46:46 by alramire          #+#    #+#             */
/*   Updated: 2025/11/20 11:35:55 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

int main( void ) 
{   
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