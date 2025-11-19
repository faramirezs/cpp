/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:44:19 by alramire          #+#    #+#             */
/*   Updated: 2025/11/19 09:16:37 by alramire         ###   ########.fr       */
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

// const std::string ShrubberyCreationForm::getTarget()
// {
//     return _target;
// }

void ShrubberyCreationForm::executeAction() 
{
    std::string filename = getTarget() + "_shrubbery";

    std::ofstream outfile (filename.c_str());
    if (!outfile)
        throw std::runtime_error("Failed to open file: " + filename);
    
    outfile <<
"            \\/ |    |/\n"
"         \\/ / \\||/  /_/___/_\n"
"          \\/   |/ \\/\n"
"     _\\__\\_\\   |  /_____/_\n"
"            \\  | /          /\n"
"   __ _-----`  |{,-----------~\n"
"             \\ }{\n"
"              }{{\n"
"              }}{\n"
"              {{ }\n"
"        , -=-~{ .-^- _\n"
"   ejm        `}\n"
"               {\n";
}   

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src)
    : AForm(src)
{

}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( const ShrubberyCreationForm & rhs ) 
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

ShrubberyCreationForm::ShrubberyCreationForm(const std::string & target)
    :AForm("ShrubberyCreationForm", false, 145, 137, target) 
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    
}