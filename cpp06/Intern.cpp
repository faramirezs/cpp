/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:44:19 by alramire          #+#    #+#             */
/*   Updated: 2025/07/05 13:50:31 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

struct formMaker
{
    std::string name;
    AForm * (*creator)(const std::string & target);
};

AForm * Intern::createShrubbery(const std::string & target)
{
  return(new ShrubberyCreationForm(target));
}

AForm * Intern::createRobotomy(const std::string & target)
{
    return(new RobotomyRequestForm(target));
}

AForm * Intern::createPresidential(const std::string & target)
{
    return(new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string & form, const std::string & target)
{
    formMaker frmArray[3];
    
    frmArray[0].name = "shrubbery creation";
    frmArray[1].name = "robotomy request";
    frmArray[2].name = "presidential pardon"; 
    
    frmArray[0].creator = Intern::createShrubbery;
    frmArray[1].creator = Intern::createRobotomy;
    frmArray[2].creator = Intern::createPresidential;


    for (size_t i = 0; i < 3; i++)
    {
        if(frmArray[i].name==form)
        {
            std::cout << "Intern creates " << form << std::endl;
            return(frmArray[i].creator(target));
        }
    }

    std::cerr << "Form not found, try: shrubbery creation, robotomy request or presidential pardon" << std::endl;
    return NULL;
}

Intern & Intern::operator=( Intern const & rhs ) 
{
    (void)rhs;
    return *this;
}

Intern::Intern(Intern const & src)
{
    (void)src;
}

Intern::Intern()
{

}

Intern::~Intern()
{
    
}
