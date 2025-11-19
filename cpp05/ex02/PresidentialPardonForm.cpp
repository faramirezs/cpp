/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:44:19 by alramire          #+#    #+#             */
/*   Updated: 2025/11/19 15:24:10 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

void PresidentialPardonForm::executeAction() const
{
    std::cout << getTarget() <<" has been pardoned by Zaphod Beeblebrox."<<std::endl;
}   

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
    : AForm(src)
{

}

PresidentialPardonForm & PresidentialPardonForm::operator=( const PresidentialPardonForm & rhs ) 
{
    (void)rhs;
    return *this;
}

std::ostream & operator<<(std::ostream & ost, PresidentialPardonForm const & frm)
{
    ost << frm.getFName() 
    << ", PP. Form sign grade: " 
    << frm.getSignGrade() 
    << ", PP. Form exec grade: " 
    << frm.getExecGrade() 
    << ", PP. Form is signed: " 
    << frm.getIsSigned() 
    << "." <<std::endl;
    return (ost); 
}

PresidentialPardonForm::PresidentialPardonForm(const std::string & target)
    :AForm("PresidentialPardonForm", false, 25, 5, target) 
{

}

PresidentialPardonForm::PresidentialPardonForm()
    :AForm("PresidentialPardonForm", false, 25, 5, "default_target") 
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{
    
}