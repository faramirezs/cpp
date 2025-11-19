/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:44:19 by alramire          #+#    #+#             */
/*   Updated: 2025/11/19 09:04:39 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

const std::string & AForm::getFName() const
{
    return _fName;
}

int AForm::getSignGrade() const
{
    return _signGrade;
}

int AForm::getExecGrade() const
{
    return _execGrade;
}

bool AForm::getIsSigned() const
{
    return _isSigned;
}

const std::string & AForm::getTarget()
{
    return _target;
}

void AForm::beSigned(Bureaucrat const & bct)
{
    if (_signGrade < bct.getGrade())
        throw AForm::gradeTooHighException();
    else
        _isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) 
{
    if (!_isSigned)
        throw AForm::notSignedException();
    else if (executor.getGrade() > _execGrade)
        throw AForm::gradeTooHighException();
    else
        executeAction();
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

std::ostream & operator<<(std::ostream & ost, AForm const & frm)
{
    ost << frm.getFName() << ", AForm sign grade: " << frm.getSignGrade() << ", AForm exec grade: " << frm.getExecGrade() << ", AForm is signed: " << frm.getIsSigned() << "." <<std::endl;
    return (ost); 
}

AForm::AForm()
    :_fName("default AFormform"), _isSigned(false) ,_signGrade(150), _execGrade(150)
{

}

const char* AForm::gradeTooHighException::what() const throw() 
{
 return ("AForm grade too high.");   
}

const char* AForm::gradeTooLowException::what() const throw() 
{
 return ("AForm grade too low.");   
}

AForm::AForm(const std::string fName, bool isSigned, const int signGrade, const int execGrade, const std::string & target)
    :_fName(fName), _isSigned(isSigned) ,_signGrade(signGrade), _execGrade(execGrade), _target(target)
{
    if (signGrade < 1 || execGrade < 1)
        throw AForm::gradeTooHighException();
    else if (signGrade > 150 || execGrade > 150)
        throw AForm::gradeTooLowException();   
}

AForm::~AForm()
{
    
}