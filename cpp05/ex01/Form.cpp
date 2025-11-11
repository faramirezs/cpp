/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:44:19 by alramire          #+#    #+#             */
/*   Updated: 2025/07/05 13:50:31 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

const std::string & Form::getFName() const
{
    return _fName;
}

const int Form::getSignGrade() const
{
    return _signGrade;
}

const int Form::getExecGrade() const
{
    return _execGrade;
}

bool Form::getIsSigned() const
{
    return _isSigned;
}

void Form::beSigned(Bureaucrat const & bct)
{
    if (_signGrade < bct.getGrade())
        throw Form::gradeTooLowException();
    else
        _isSigned = true;
}

// void Form::incrementGrade()
// {
//     if (_grade == 1)
//         throw Form::gradeTooHighException();
//     else
//         _grade--;
// }

// void Form::decrementGrade()
// {
//     if (_grade == 150)
//         throw Form::gradeTooLowException();
//     else
//         _grade++;
// }

Form::Form(Form const & src)
    : _fName(src._fName), _isSigned(src._isSigned) ,_signGrade(src._signGrade), _execGrade(src._execGrade)
{

}

Form & Form::operator=( const Form & rhs ) 
{
    if (this != &rhs) 
    {
        this->_isSigned = rhs.getIsSigned();
    }
    return *this;
}

std::ostream & operator<<(std::ostream & ost, Form const & frm)
{
    ost << frm.getFName() << ", Form sign grade: " << frm.getSignGrade() << ", Form exec grade: " << frm.getExecGrade() << ", Form is signed: " << frm.getSignGrade() << "." <<std::endl;
    return (ost); 
}

Form::Form()
    :_fName("default form"), _isSigned(false) ,_signGrade(150), _execGrade(150)
{

}

const char* Form::gradeTooHighException::what() const throw() 
{
 return ("Grade too high.");   
}

const char* Form::gradeTooLowException::what() const throw() 
{
 return ("Grade too low.");   
}

Form::Form(const std::string fName, bool isSigned, const int signGrade, const int execGrade)
    :_fName(fName), _isSigned(isSigned) ,_signGrade(signGrade), _execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw Form::gradeTooHighException();
    else if (signGrade > 150 || execGrade > 150)
        throw Form::gradeTooLowException();   
}

Form::~Form()
{
    
}