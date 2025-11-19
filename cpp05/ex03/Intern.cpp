/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:44:19 by alramire          #+#    #+#             */
/*   Updated: 2025/07/05 13:50:31 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

AForm *Intern::makeForm(const std::string & form, const std::string & target)
{
    
    return(*(PresidentialPardonForm(target)));
}

Intern::Intern(Intern const & src)
    : _name(src._name), _grade(src._grade)
{

}

Intern & Intern::operator=( Intern const & rhs ) 
{
    (void)rhs;
    return *this;
}

// std::ostream & operator<<(std::ostream & ost, Intern const & bct)
// {
//     ost << bct.getName() << ", Intern grade " << bct.getGrade() << "." <<std::endl;
//     return (ost); 
// }

Intern::Intern()
{

}

Intern::~Intern()
{
    
}