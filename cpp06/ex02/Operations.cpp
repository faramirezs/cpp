/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operations.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroramirez <alejandroramirez@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 09:51:13 by alramire          #+#    #+#             */
/*   Updated: 2026/02/05 13:23:34 by alejandrora      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Operations.hpp"
#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>

Base *generate() {
static bool seeded = false;
  if (!seeded) {
    srand(time(NULL)); seeded = true;
  }
  int choice = rand() % 3;

  if (choice == 0)
    return new A();
  if (choice == 1)
    return new B();
  else
    return new C();
}

void identify(Base *p) {
  if (dynamic_cast<A*>(p)) std::cout << "A\n";
  else if (dynamic_cast<B*>(p)) std::cout << "B\n";
  else if (dynamic_cast<C*>(p)) std::cout << "C\n";
}

// dynamic_cast<A&>(p): Asks the runtime "Is the actual object behind this reference really an A?"
// If YES: Returns an A&, program continues to print "A"
// If NO: Throws std::bad_cast, jumps to first catch block

void identify(Base &p) {
  try {
      (void)dynamic_cast<A&>(p);
      std::cout << "A\n";
  } catch (std::bad_cast&) { // If it throws, not A
      try {
          (void)dynamic_cast<B&>(p);
          std::cout << "B\n";
      } catch (std::bad_cast&) {
          std::cout << "C\n";  // Must be C if not A or B
      }
  }
}
