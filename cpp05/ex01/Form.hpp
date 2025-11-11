/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:46:25 by alramire          #+#    #+#             */
/*   Updated: 2025/07/05 13:46:55 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_H__
#define __FORM_H__

# include <string>
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string _fName;
        bool _isSigned;
        const int _signGrade;
        const int _execGrade;

    public:
        const int getSignGrade() const;
        const int getExecGrade() const;
        const std::string & getFName() const;
        bool getIsSigned();
        void beSigned(Bureaucrat const & src);
        
        Form& operator=(Form const & rhs);
        Form(Form const & src);
        Form();
        Form(int, const std::string);
        ~Form(void);

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

std::ostream & operator<<(std::ostream & ost, Form const & bct);

#endif