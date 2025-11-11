/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:46:25 by alramire          #+#    #+#             */
/*   Updated: 2025/07/05 13:46:55 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_H__
#define __BUREAUCRAT_H__

# include <string>
# include <iostream>
# include <stdexcept>

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;

    public:
        int getGrade() const;
        const std::string & getName() const;
        void incrementGrade();
        void decrementGrade();
        
        Bureaucrat& operator=(Bureaucrat const & rhs);
        Bureaucrat(Bureaucrat const & src);
        Bureaucrat();
        Bureaucrat(int, const std::string);
        ~Bureaucrat(void);

        class gradeTooHighException : public std::exception
        {
        public:
            const char* what() const throw();
        };

        class gradeTooLowException : public std::exception
        {
        public:
            const char* what() const throw();
        };
};

std::ostream & operator<<(std::ostream & ost, Bureaucrat const & bct);

#endif