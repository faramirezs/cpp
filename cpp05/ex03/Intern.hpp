/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:46:25 by alramire          #+#    #+#             */
/*   Updated: 2025/07/05 13:46:55 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN_H__
#define __INTERN_H__

# include <string>
# include <iostream>
# include <stdexcept>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

class AForm;

class Intern
{
    private:
        static AForm * createShrubbery(const std::string & target);
        static AForm * createRobotomy(const std::string & target);
        static AForm * createPresidential(const std::string & target);

    public:
        AForm *makeForm(const std::string & form, const std::string & target);
        
        Intern& operator=(Intern const & rhs);
        Intern(Intern const & src);
        Intern();
        ~Intern(void);

        // class gradeTooHighException : public std::exception
        // {
        // public:
        //     const char* what() const throw();
        // };

        // class gradeTooLowException : public std::exception
        // {
        // public:
        //     const char* what() const throw();
        // };
};

// std::ostream & operator<<(std::ostream & ost, Intern const & bct);

#endif