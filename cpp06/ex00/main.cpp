/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:46:46 by alramire          #+#    #+#             */
/*   Updated: 2025/11/11 13:38:52 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char **av) {
  if (ac != 2) {
    std::cerr << "Error" << '\n';
    return 1;
  }
  std::string input;
  input = av[1];
  ScalarConverter::convert(input);
  return 0;
}
