/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:46:25 by alramire          #+#    #+#             */
/*   Updated: 2025/11/19 15:06:25 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RFORM_H__
#define __RFORM_H__

# include <string>
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include <fstream>

class Bureaucrat;

class RobotomyRequestForm: public AForm
{

    public:
        void executeAction() const;
        
        RobotomyRequestForm& operator=(RobotomyRequestForm const & rhs);
        RobotomyRequestForm(RobotomyRequestForm const & rhs);
        RobotomyRequestForm(const std::string & target);
        RobotomyRequestForm();
        ~RobotomyRequestForm();

};

std::ostream & operator<<(std::ostream & ost, RobotomyRequestForm const & frm);

#endif