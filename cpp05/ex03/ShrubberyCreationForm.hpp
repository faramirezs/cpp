/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:46:25 by alramire          #+#    #+#             */
/*   Updated: 2025/11/19 15:06:25 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCFORM_H__
#define __SCFORM_H__

# include <string>
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include <fstream>

class Bureaucrat;

class ShrubberyCreationForm: public AForm
{

    public:
        void executeAction() const;
        
        ShrubberyCreationForm& operator=(ShrubberyCreationForm const & rhs);
        ShrubberyCreationForm(ShrubberyCreationForm const & rhs);
        ShrubberyCreationForm(const std::string & target);
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();

};

std::ostream & operator<<(std::ostream & ost, ShrubberyCreationForm const & frm);

#endif