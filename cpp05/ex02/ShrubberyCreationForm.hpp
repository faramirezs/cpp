/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:46:25 by alramire          #+#    #+#             */
/*   Updated: 2025/11/19 09:10:35 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCFORM_H__
#define __SCAFORM_H__

# include <string>
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include <fstream>

class Bureaucrat;

class ShrubberyCreationForm: public AForm
{
    // private:
    //     const std::string _target;

    public:
        void executeAction();
        // const std::string getTarget();
        
        ShrubberyCreationForm& operator=(AForm const & rhs);
        ShrubberyCreationForm(const std::string & target);
        ShrubberyCreationForm();
        // ShrubberyCreationForm(const std::string, bool, const int, const int);
        ~ShrubberyCreationForm(void);

};

std::ostream & operator<<(std::ostream & ost, ShrubberyCreationForm const & frm);

#endif