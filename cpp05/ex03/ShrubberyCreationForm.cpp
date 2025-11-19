/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:44:19 by alramire          #+#    #+#             */
/*   Updated: 2025/11/19 15:24:10 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

void ShrubberyCreationForm::executeAction() const
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
    (void)rhs;
    return *this;
}

std::ostream & operator<<(std::ostream & ost, ShrubberyCreationForm const & frm)
{
    ost << frm.getFName() 
    << ", S. Form sign grade: " 
    << frm.getSignGrade() 
    << ", S. Form exec grade: " 
    << frm.getExecGrade() 
    << ", S. Form is signed: " 
    << frm.getIsSigned() 
    << "." <<std::endl;
    return (ost); 
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string & target)
    :AForm("ShrubberyCreationForm", false, 145, 137, target) 
{

}

ShrubberyCreationForm::ShrubberyCreationForm()
    :AForm("ShrubberyCreationForm", false, 145, 137, "default_target") 
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    
}