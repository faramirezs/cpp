/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                          :+:      :+:
 * :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:46:25 by alramire          #+#    #+#             */
/*   Updated: 2025/07/05 13:46:55 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCALARCONVERTER_H__
#define __SCALARCONVERTER_H__

#include <cerrno> // for errno
#include <cmath>  // for fabs
#include <cstdio>
#include <cstdlib> // for strtod
#include <iomanip>
#include <iostream>
#include <limits> // for numeric_limits
#include <stdexcept>
#include <stdlib.h>
#include <string>

class AForm;

class ScalarConverter {
private:
  ScalarConverter &operator=(ScalarConverter const &rhs);
  ScalarConverter(ScalarConverter const &src);
  ScalarConverter();

public:
  static void convert(const std::string &input);
  ~ScalarConverter(void);
};

#endif
