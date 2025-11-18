/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:44:19 by alramire          #+#    #+#             */
/*   Updated: 2025/11/18 09:49:47 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

// const std::string & AForm::getFName() const
// {
//     return _fName;
// }

// int AForm::getSignGrade() const
// {
//     return _signGrade;
// }

// int AForm::getExecGrade() const
// {
//     return _execGrade;
// }

// bool AForm::getIsSigned() const
// {
//     return _isSigned;
// }

const std::string ShrubberyCreationForm::getTarget()
{
    return _target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & src) 
{
    //Execute
}   

AForm::AForm(AForm const & src)
    : _fName(src._fName), _isSigned(src._isSigned) ,_signGrade(src._signGrade), _execGrade(src._execGrade)
{

}

AForm & AForm::operator=( const AForm & rhs ) 
{
    if (this != &rhs) 
    {
        this->_isSigned = rhs.getIsSigned();
    }
    return *this;
}

std::ostream & operator<<(std::ostream & ost, ShrubberyCreationForm const & frm)
{
    ost << frm.getFName() 
    << ", Shrubbery Form sign grade: " 
    << frm.getSignGrade() 
    << ", Shrubbery Form exec grade: " 
    << frm.getExecGrade() 
    << ", Shrubbery Form is signed: " 
    << frm.getIsSigned() 
    << "." <<std::endl;
    return (ost); 
}

const char* AForm::gradeTooHighException::what() const throw() 
{
 return ("AForm grade too high.");   
}

const char* AForm::gradeTooLowException::what() const throw() 
{
 return ("AForm grade too low.");   
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
    :AForm("ShrubberyCreationForm", false, 145, 137), _target(target) 
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    
}