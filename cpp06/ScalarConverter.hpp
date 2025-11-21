/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:46:25 by alramire          #+#    #+#             */
/*   Updated: 2025/07/05 13:46:55 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCALARCONVERTER_H__
#define __SCALARCONVERTER_H__

# include <string>
# include <iostream>
# include <stdexcept>
# include <stdlib.h>
class AForm;

class ScalarConverter
{

public:
        static void convert(char * input);
        ScalarConverter& operator=(ScalarConverter const & rhs);
        ScalarConverter(ScalarConverter const & src);
        ScalarConverter();
        ~ScalarConverter(void);
};

#endif
