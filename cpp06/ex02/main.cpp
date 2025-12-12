/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 09:51:01 by alramire          #+#    #+#             */
/*   Updated: 2025/12/12 09:57:51 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Operations.hpp"
#include <iostream>
#include <ctime> 
#include <cstdlib>

int main(void) {
  srand(time(NULL));
  std::cout << "Generating 10 random objects:" << std::endl;
  for (int i = 0; i < 10; ++i) {
    Base *obj = generate();
    std::cout << "  Object " << (i + 1) << ": ";
    identify(obj);
    delete obj;
  }

  std::cout << "\nSame Object via Pointer and Reference" << std::endl;
  Base *ptr3 = generate();
  std::cout << "Via pointer:    ";
  identify(ptr3);
  std::cout << "Via reference:  ";
  identify(*ptr3);
  delete ptr3;

  return 0;
}
