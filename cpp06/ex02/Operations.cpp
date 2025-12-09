#include "Operations.hpp"
#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>

Base *generate() {

  int choice = rand() % 3;

  if (choice == 0)
    return new A();
  if (choice == 1)
    return new B();
  else
    return new C();
}

void identify(Base *p);

void identify(Base &p);
