/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:44:19 by alramire          #+#    #+#             */
/*   Updated: 2025/07/05 13:50:31 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Form.hpp"

const std::string & Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::incrementGrade()
{
    if (_grade == 1)
        throw Bureaucrat::gradeTooHighException();
    else
        _grade--;
}

void Bureaucrat::decrementGrade()
{
    if (_grade == 150)
        throw Bureaucrat::gradeTooLowException();
    else
        _grade++;
}

void Bureaucrat::signForm()
{
    Form::beSigned(this);
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
    : _name(src._name), _grade(src._grade)
{

}

Bureaucrat & Bureaucrat::operator=( Bureaucrat const & rhs ) 
{
    if (this != &rhs) 
        this->_grade = rhs.getGrade();
    return *this;
}

std::ostream & operator<<(std::ostream & ost, Bureaucrat const & bct)
{
    ost << bct.getName() << ", bureaucrat grade " << bct.getGrade() << "." <<std::endl;
    return (ost); 
}

Bureaucrat::Bureaucrat()
    :_name("default"), _grade(150)
{

}

const char* Bureaucrat::gradeTooHighException::what() const throw() 
{
 return ("Grade too high.");   
}

const char* Bureaucrat::gradeTooLowException::what() const throw() 
{
 return ("Grade too low.");   
}

Bureaucrat::Bureaucrat(int grade, const std::string name)
    :_name(name)
{
    if (grade < 1)
        throw Bureaucrat::gradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::gradeTooLowException();
    else
        _grade = grade;    
}

Bureaucrat::~Bureaucrat()
{
    
}