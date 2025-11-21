/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:44:19 by alramire          #+#    #+#             */
/*   Updated: 2025/07/05 13:50:31 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

enum inputType
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	STRING,
};

inputType detectType(const std::string &input)
{
	int int_var;
	float float_var;
	double double_var;

	if (input.length() == 1 && !isdigit(input[0]))
		return CHAR;
	if (sscanf(input.c_str(),"%d",&int_var))
		return INT;	
	if (sscanf(input.c_str(),"%d",&int_var))
		return FLOAT;	
	if (sscanf(input.c_str(),"%d",&int_var))
		return DOUBLE;	
	return STRING;


}


void ScalarConverter::convert(char *av)
{

}




struct formMaker
{
    std::string name;
    AForm * (*creator)(const std::string & target);
};

AForm * ScalarConverter::createShrubbery(const std::string & target)
{
  return(new ShrubberyCreationForm(target));
}

AForm * ScalarConverter::createRobotomy(const std::string & target)
{
    return(new RobotomyRequestForm(target));
}

AForm * ScalarConverter::createPresidential(const std::string & target)
{
    return(new PresidentialPardonForm(target));
}

AForm *ScalarConverter::makeForm(const std::string & form, const std::string & target)
{
    formMaker frmArray[3];
    
    frmArray[0].name = "shrubbery creation";
    frmArray[1].name = "robotomy request";
    frmArray[2].name = "presidential pardon"; 
    
    frmArray[0].creator = ScalarConverter::createShrubbery;
    frmArray[1].creator = ScalarConverter::createRobotomy;
    frmArray[2].creator = ScalarConverter::createPresidential;


    for (size_t i = 0; i < 3; i++)
    {
        if(frmArray[i].name==form)
        {
            std::cout << "ScalarConverter creates " << form << std::endl;
            return(frmArray[i].creator(target));
        }
    }

    std::cerr << "Form not found, try: shrubbery creation, robotomy request or presidential pardon" << std::endl;
    return NULL;
}

ScalarConverter & ScalarConverter::operator=( ScalarConverter const & rhs ) 
{
    (void)rhs;
    return *this;
}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
    (void)src;
}

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::~ScalarConverter()
{
    
}
