/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:44:19 by alramire          #+#    #+#             */
/*   Updated: 2025/11/19 15:24:10 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"

static int robot = 0;

void RobotomyRequestForm::executeAction() const
{
    if (robot++ % 2)
    {
        std::cout << "RRRRRrrrrrrRRRrrrRRRRrrr!"<< getTarget() <<" has been robotomized." <<std::endl;
    }
    else
    {
        throw std::runtime_error("Robotomy failed");
    }
}   

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
    : AForm(src)
{

}

RobotomyRequestForm & RobotomyRequestForm::operator=( const RobotomyRequestForm & rhs ) 
{
    (void)rhs;
    return *this;
}

std::ostream & operator<<(std::ostream & ost, RobotomyRequestForm const & frm)
{
    ost << frm.getFName() 
    << ", R. Form sign grade: " 
    << frm.getSignGrade() 
    << ", R. Form exec grade: " 
    << frm.getExecGrade() 
    << ", R. Form is signed: " 
    << frm.getIsSigned() 
    << "." <<std::endl;
    return (ost); 
}

RobotomyRequestForm::RobotomyRequestForm(const std::string & target)
    :AForm("RobotomyRequestForm", false, 72, 45, target) 
{

}

RobotomyRequestForm::RobotomyRequestForm()
    :AForm("RobotomyRequestForm", false, 72, 45, "default_target") 
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{
    
}