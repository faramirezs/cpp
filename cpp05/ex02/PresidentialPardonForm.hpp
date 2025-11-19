/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:46:25 by alramire          #+#    #+#             */
/*   Updated: 2025/11/19 15:06:25 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PPFORM_H__
#define __PPFORM_H__

# include <string>
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include <fstream>

class Bureaucrat;

class PresidentialPardonForm: public AForm
{

    public:
        void executeAction() const;
        
        PresidentialPardonForm& operator=(PresidentialPardonForm const & rhs);
        PresidentialPardonForm(PresidentialPardonForm const & rhs);
        PresidentialPardonForm(const std::string & target);
        PresidentialPardonForm();
        ~PresidentialPardonForm();

};

std::ostream & operator<<(std::ostream & ost, PresidentialPardonForm const & frm);

#endif