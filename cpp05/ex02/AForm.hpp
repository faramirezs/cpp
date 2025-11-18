/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:46:25 by alramire          #+#    #+#             */
/*   Updated: 2025/11/18 09:38:28 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AFORM_H__
#define __AFORM_H__

# include <string>
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string _fName;
        bool _isSigned;
        const int _signGrade;
        const int _execGrade;

    public:
        int getSignGrade() const;
        int getExecGrade() const;
        const std::string & getFName() const;
        bool getIsSigned() const;
        void beSigned(Bureaucrat const & src);
        void execute(Bureaucrat const & src);
        virtual void executeAction(Bureaucrat const & src) const = 0;
        
        AForm& operator=(AForm const & rhs);
        AForm(AForm const & src);
        AForm();
        AForm(const std::string, bool, const int, const int);
        virtual ~AForm(void);

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

        class notSignedException : public std::exception
        {
        public:
            const char* what() const throw();
        };
};

std::ostream & operator<<(std::ostream & ost, AForm const & bct);

#endif