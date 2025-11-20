/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:46:46 by alramire          #+#    #+#             */
/*   Updated: 2025/11/20 11:04:27 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"


int main( void ) 
{   
    std::cout << "====Sign & exec sh form.====" << std::endl;
    
    try
    {
        Bureaucrat mike(15, "Mike");
        ShrubberyCreationForm shform("shtarget");
        std::cout << mike << std::endl;
        std::cout << shform << std::endl;
        mike.signForm(shform);
        std::cout << shform << std::endl;
        std::cout << mike << std::endl;
        mike.executeForm(shform);
        std::cout << shform << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "====Sign & exec sh form.(exec low grade)====" << std::endl;

    try
    {
        Bureaucrat mike(15, "Mike");
        Bureaucrat make(138, "Make");
        ShrubberyCreationForm shform("shtarget");
        std::cout << mike << std::endl;
        std::cout << shform << std::endl;
        mike.signForm(shform);
        std::cout << shform << std::endl;
        std::cout << make << std::endl;
        make.executeForm(shform);
        std::cout << shform << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "====Sign & exec sh form.(sign/exec low grade)====" << std::endl;

    try
    {
        Bureaucrat mike(146, "Mike");
        Bureaucrat make(138, "Make");
        ShrubberyCreationForm shform("shtarget");
        std::cout << mike << std::endl;
        std::cout << shform << std::endl;
        mike.signForm(shform);
        std::cout << shform << std::endl;
        std::cout << make << std::endl;
        make.executeForm(shform);
        std::cout << shform << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }


    std::cout << "====Sign & exec R form.====" << std::endl;
    
    try
    {
        Bureaucrat mike(15, "Mike");
        RobotomyRequestForm rform("Rob");
        std::cout << mike << std::endl;
        std::cout << rform << std::endl;
        mike.signForm(rform);
        std::cout << rform << std::endl;
        std::cout << mike << std::endl;
        mike.executeForm(rform);
        mike.executeForm(rform);
        mike.executeForm(rform);
        mike.executeForm(rform);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "====Sign & exec R form.(exec low grade)====" << std::endl;

    try
    {
        Bureaucrat mike(70, "Mike");
        Bureaucrat make(46, "Make");
        RobotomyRequestForm rform("Rob");
        std::cout << mike << std::endl;
        std::cout << rform << std::endl;
        mike.signForm(rform);
        std::cout << rform << std::endl;
        std::cout << make << std::endl;
        make.executeForm(rform);
        std::cout << rform << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "====Sign & exec R form.(sign/exec low grade)====" << std::endl;

    try
    {
        Bureaucrat mike(146, "Mike");
        Bureaucrat make(138, "Make");
        RobotomyRequestForm rform("Rob");
        std::cout << mike << std::endl;
        std::cout << rform << std::endl;
        mike.signForm(rform);
        std::cout << rform << std::endl;
        std::cout << make << std::endl;
        make.executeForm(rform);
        std::cout << rform << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "====Sign & exec PP form.====" << std::endl;
    
    try
    {
        Bureaucrat mike(5, "Mike");
        PresidentialPardonForm ppform("Blad_Blad");
        std::cout << mike << std::endl;
        std::cout << ppform << std::endl;
        mike.signForm(ppform);
        std::cout << ppform << std::endl;
        std::cout << mike << std::endl;
        mike.executeForm(ppform);
        std::cout << ppform << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "====Sign & exec PP form.(exec low grade)====" << std::endl;

    try
    {
        Bureaucrat mike(25, "Mike");
        Bureaucrat make(6, "Make");
        PresidentialPardonForm ppform("Blad_Blad");
        std::cout << mike << std::endl;
        std::cout << ppform << std::endl;
        mike.signForm(ppform);
        std::cout << ppform << std::endl;
        std::cout << make << std::endl;
        make.executeForm(ppform);
        std::cout << ppform << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "====Sign & exec PP form.(sign/exec low grade)====" << std::endl;

    try
    {
        Bureaucrat mike(26, "Mike");
        Bureaucrat make(6, "Make");
        PresidentialPardonForm ppform("Blad_Blad");
        std::cout << mike << std::endl;
        std::cout << ppform << std::endl;
        mike.signForm(ppform);
        std::cout << ppform << std::endl;
        std::cout << make << std::endl;
        make.executeForm(ppform);
        std::cout << ppform << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}