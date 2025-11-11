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



        void beSigned(Bureaucrat const & src);

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

bool Form::getIsSigned()
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

void Form::incrementGrade()
{
    if (_grade == 1)
        throw Form::gradeTooHighException();
    else
        _grade--;
}

void Form::decrementGrade()
{
    if (_grade == 150)
        throw Form::gradeTooLowException();
    else
        _grade++;
}

Form::Form(Form const & src)
    : _name(src._name), _grade(src._grade)
{

}

Form & Form::operator=( Form const & rhs ) 
{
    if (this != &rhs) 
        this->_grade = rhs.getGrade();
    return *this;
}

std::ostream & operator<<(std::ostream & ost, Form const & bct)
{
    ost << bct.getName() << ", Form grade " << bct.getGrade() << "." <<std::endl;
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

Form::Form(int grade, const std::string name)
    :_name(name)
{
    if (grade < 1)
        throw Form::gradeTooHighException();
    else if (grade > 150)
        throw Form::gradeTooLowException();
    else
        _grade = grade;    
}

Form::~Form()
{
    
}