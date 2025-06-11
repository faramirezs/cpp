
# C++ - Module 01 Summary

## Overview

Module 01 introduces memory allocation, pointers to members, references, and switch statements in C++. This document summarizes the requirements and tasks for each exercise in the module, emphasizing proper memory management, coding style, and correct use of language features.

---

## General Rules

- **Compilation:** Use `c++` with `-Wall -Wextra -Werror`, and optionally `-std=c++98`.
- **Formatting:** Follow naming conventions:
  - UpperCamelCase for classes
  - Class files named after the class: `ClassName.hpp`, `ClassName.cpp`, etc.
- **Coding Style:** No enforced style, but readability is essential.
- **Restrictions:** No `*printf()`, `*alloc()`, `free()`, or modern C++ (C++11+) features. No use of `<algorithm>` or STL until Module 08/09.
- **Design:** Avoid memory leaks; implement Orthodox Canonical Form from Module 02 onward; use include guards.
- **Makefile:** Required with standard rules.
- **Hint:** Read the entire module before starting; you can create extra files.

---

## Exercise 00: BraiiiiiiinnnzzzZ

**Directory:** `ex00/`  
**Files:** `Makefile`, `main.cpp`, `Zombie.{h, hpp}`, `Zombie.cpp`, `newZombie.cpp`, `randomChump.cpp`

- Create a `Zombie` class with `std::string name` and a `void announce(void)` method.
- Create functions:
  - `Zombie* newZombie(std::string name)` – heap allocation
  - `void randomChump(std::string name)` – stack allocation and auto-announcement
- Destructor must announce when the zombie is destroyed.
- Determine when to use stack vs. heap allocation.

---

## Exercise 01: Moar brainz!

**Directory:** `ex01/`  
**Files:** `Makefile`, `main.cpp`, `Zombie.{h, hpp}`, `Zombie.cpp`, `zombieHorde.cpp`

- Function: `Zombie* zombieHorde(int N, std::string name)`
- Allocate an array of `N` zombies and initialize them with the given name.
- Loop through them and call `announce()`.
- Remember to deallocate with `delete[]`.

---

## Exercise 02: HI THIS IS BRAIN

**Directory:** `ex02/`  
**Files:** `Makefile`, `main.cpp`

- Declare a string with the value `"HI THIS IS BRAIN"`.
- Create:
  - `stringPTR`: pointer to the string
  - `stringREF`: reference to the string
- Print:
  - Memory addresses of the string, `stringPTR`, and `stringREF`
  - Values of the string, `*stringPTR`, and `stringREF`

---

## Exercise 03: Unnecessary violence

**Directory:** `ex03/`  
**Files:** `Makefile`, `main.cpp`, `Weapon.{h, hpp}`, `Weapon.cpp`, `HumanA.{h, hpp}`, `HumanA.cpp`, `HumanB.{h, hpp}`, `HumanB.cpp`

- Class `Weapon`:
  - `std::string type`
  - `getType()` – returns `const std::string&`
  - `setType(std::string)` – updates `type`
- Classes:
  - `HumanA`: takes weapon by reference in constructor
  - `HumanB`: can set weapon later using `setWeapon()`
- Function `attack()` prints: `<name> attacks with their <weapon type>`
- Demonstrate behavior when weapon changes.

---

## Exercise 04: Sed is for losers

**Directory:** `ex04/`  
**Files:** `Makefile`, `main.cpp`, `*.cpp`, `*.{h, hpp}`

- Takes 3 arguments: `<filename> <s1> <s2>`
- Replaces all occurrences of `s1` with `s2` in the file and writes to `<filename>.replace`
- Do not use `std::string::replace()` or C file APIs.
- Handle errors and invalid input gracefully.

---

## Exercise 05: Harl 2.0

**Directory:** `ex05/`  
**Files:** `Makefile`, `main.cpp`, `Harl.{h, hpp}`, `Harl.cpp`

- Create class `Harl` with private methods:
  - `debug()`, `info()`, `warning()`, `error()`
- Public method:
  - `void complain(std::string level)` – calls the appropriate private method
- Use pointers to member functions (not `if/else` chains).
- Test Harl's complaints using sample messages.

---

## Exercise 06: Harl filter

**Directory:** `ex06/`  
**Files:** `Makefile`, `main.cpp`, `Harl.{h, hpp}`, `Harl.cpp`

- Extend `Harl` to filter messages by log level.
- Program takes one level as input and prints messages from that level and more critical.
- Use `switch` statements for implementation.
- Optional: This exercise is not mandatory for passing the module.

---

## Submission

- Push your code to your Git repository.
- Only committed code will be evaluated.
- Ensure all filenames and directories are correctly named.
