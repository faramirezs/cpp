/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:46:46 by alramire          #+#    #+#             */
/*   Updated: 2025/11/20 11:15:50 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "Intern.hpp"


int main( void ) 
{   
    Intern someRandomIntern;
    
    AForm* shf;
    shf = someRandomIntern.makeForm("shrubbery creation", "inter_trees");
    
    AForm* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");

    AForm* ppf;
    ppf = someRandomIntern.makeForm("presidential pardon", "zulan Katu");

    std::cout << "====Sign & exec intern form.====" << std::endl;
    
    try
    {
        Bureaucrat mike(15, "Mike");
        std::cout << mike << std::endl;
        std::cout << *rrf << std::endl;
        mike.signForm(*rrf);
        std::cout << *rrf << std::endl;
        std::cout << mike << std::endl;
        mike.executeForm(*rrf);
        mike.executeForm(*rrf);
        mike.executeForm(*rrf);
        mike.executeForm(*rrf);
        mike.signForm(*shf);
        std::cout << *shf << std::endl;
        mike.executeForm(*shf);
        mike.signForm(*ppf);
        std::cout << *ppf << std::endl;
        mike.executeForm(*ppf);
        Bureaucrat Vito(1, "Vito");
        Vito.executeForm(*ppf);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}