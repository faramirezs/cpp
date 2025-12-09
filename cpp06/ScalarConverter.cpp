/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                          :+:      :+:
 * :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:44:19 by alramire          #+#    #+#             */
/*   Updated: 2025/07/05 13:50:31 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

enum inputType {
  CHAR,
  INT,
  FLOAT,
  DOUBLE,
  STRING,
};

bool isPseudoLiteral(const std::string &literal) {
  return literal == "nan" || literal == "nanf" || literal == "+inf" ||
         literal == "+inff" || literal == "-inf" || literal == "-inff";
}

void ScalarConverter::convert(const std::string &input) {
  double dVal = 0.0;
  bool isValid = true;
  inputType type = STRING;

  // Case 1: Char literal
  // A single character that is NOT a digit is treated as a char literal.
  if (input.length() == 1 && !std::isdigit(input[0]) &&
      std::isprint(input[0])) {
    dVal = static_cast<double>(input[0]);
    type = CHAR;
  }
  // Case 2: Numeric or Pseudo-literal
  else {
    char *endptr;
    dVal = std::strtod(input.c_str(), &endptr);

    // Check if the conversion was successful
    if (*endptr != '\0') {
      // If not empty, it might be a float literal ending in 'f'
      if (std::string(endptr) == "f") {
        // It was a float (e.g. 12.34f), strtod handled the 12.34 part
        type = FLOAT;
      } else {
        // Garbage at the end means invalid input
        isValid = false;
      }
    }
  }

  if (!isValid) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
    return;
  }


  //CHAR
  std::cout << "char: ";
  if (dVal != dVal || dVal == std::numeric_limits<double>::infinity() ||
      dVal == -std::numeric_limits<double>::infinity()) {
    std::cout << "impossible";
  }
  // Check char overflow
  else if (dVal < std::numeric_limits<char>::min() ||
           dVal > std::numeric_limits<char>::max()) {
    std::cout << "impossible";
  }
  // Check printability
  else if (std::isprint(static_cast<char>(dVal))) {
    std::cout << "'" << static_cast<char>(dVal) << "'";
  } else {
    std::cout << "Non displayable";
  }
  std::cout << std::endl;

  //INT 
  std::cout << "int: ";
  if (dVal != dVal || dVal == std::numeric_limits<double>::infinity() ||
      dVal == -std::numeric_limits<double>::infinity()) {
    std::cout << "impossible";
  } else if (dVal < std::numeric_limits<int>::min() ||
             dVal > std::numeric_limits<int>::max()) {
    std::cout << "impossible";
  } else {
    std::cout << static_cast<int>(dVal);
    if (type == STRING)
      type = INT; 
  }
  std::cout << std::endl;

  //FLOAT
  std::cout << "float: ";
  float fVal = static_cast<float>(dVal);

  std::cout << std::fixed << std::setprecision(1) << fVal << "f" << std::endl;

  //DOUBLE
  if (type == STRING)
      type = DOUBLE; 
  std::cout << "double: ";
  std::cout << std::fixed << std::setprecision(1) << dVal << std::endl;
  //std::cout << "Initial type: " <<type << std::endl;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs) {
  (void)rhs;
  return *this;
}
ScalarConverter::ScalarConverter(ScalarConverter const &src) { (void)src; }
ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter(void) {}
