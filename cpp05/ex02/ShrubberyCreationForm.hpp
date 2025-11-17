/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:46:25 by alramire          #+#    #+#             */
/*   Updated: 2025/11/17 12:32:47 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AFORM_H__
#define __AFORM_H__

# include <string>
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm: public AForm
{
    private:
        const std::string _fName;
        bool _isSigned;
        const int _signGrade;
        const int _execGrade;

    public:
        void execute(Bureaucrat const & src);
        
        AForm& operator=(AForm const & rhs);
        AForm(AForm const & src);
        AForm();
        AForm(const std::string, bool, const int, const int);
        ~ShrubberyCreationForm(void);

};

std::ostream & operator<<(std::ostream & ost, ShrubberyCreationForm const & frm);

#endif