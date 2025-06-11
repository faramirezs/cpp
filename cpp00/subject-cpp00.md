
# C++ - Module 00 Summary

## Overview:

This module serves as an introduction to Object-Oriented Programming (OOP) in C++. It covers fundamental concepts such as namespaces, classes, member functions, I/O streams, initialization lists, and the `static` and `const` keywords. The exercises are designed to be completed following the **C++98 standard**.

## General Rules and Guidelines

A set of strict rules applies to all exercises in this module:

  * **Compilation:** All code must be compiled with `c++` using the `-Wall -Wextra -Werror` flags. It must also remain compatible with the `-std=c++98` flag.
  * **Formatting and Naming:**
      * Exercise directories must be named sequentially (e.g., `ex00`, `ex01`).
      * Class names must be in `UpperCamelCase`.
      * The filenames for classes must match the class name (e.g., a `BrickWall` class would be in `BrickWall.hpp` and `BrickWall.cpp`).
  * **Code Style:** While no specific coding style (like Norminette) is enforced, the code must be clean, readable, and understandable.
  * **Allowed/Forbidden Libraries and Functions:**
      * You are encouraged to use the C++ versions of standard C functions.
      * External libraries, including Boost and features from C++11 or later, are **forbidden**.
      * The C functions `printf()`, any `alloc` function, and `free()` are **forbidden**.
      * The use of `using namespace <ns_name>` and the `friend` keyword is **forbidden**.
      * The Standard Template Library (STL), including containers (`vector`, `list`, `map`, etc.) and algorithms, is **not allowed** until Module 08.
  * **Design and Memory:**
      * You must prevent memory leaks. Any memory allocated with `new` must be properly released.
      * Header files must be self-sufficient, including all necessary dependencies, and must use include guards to prevent multiple-inclusion errors.
      * Function implementations, except for templates, are not allowed in header files.

## Exercise 00: Megaphone

  * **Objective:** Create a program that converts command-line arguments to uppercase. This serves as a warm-up exercise.
  * **Functionality:**
      * If the program is run with no arguments, it must print the string: `* LOUD AND UNBEARABLE FEEDBACK NOISE *`
      * If run with arguments, it must concatenate them into a single string, convert all characters to uppercase, and print the result.
  * **Files to Submit:** `Makefile`, `megaphone.cpp`

## Exercise 01: My Awesome PhoneBook

  * **Objective:** Develop a basic but functional phonebook application that runs in the console.
  * **Core Components:** You must implement two classes:
    1.  **`Contact`:** Represents a single contact in the phonebook. It must store the following information:
          * First Name
          * Last Name
          * Nickname
          * Phone Number
          * Darkest Secret
          * All fields are required and cannot be empty.
    2.  **`PhoneBook`:** Manages the collection of contacts.
          * It stores a maximum of **8 contacts**.
          * **Dynamic allocation is forbidden.** The contacts must be stored in a static array.
          * If the user tries to add a 9th contact, the oldest existing contact is discarded and replaced by the new one.
  * **Program Commands:** The phonebook is controlled by three simple text commands:
      * **`ADD`:** Prompts the user to input the information for a new contact, one field at a time. The new contact is then added to the phonebook according to the rules above.
      * **`SEARCH`:**
        1.  Displays a summary list of all saved contacts. The list has 4 columns: `index`, `first name`, `last name`, and `nickname`.
        2.  Each column must be exactly **10 characters wide** and the text must be **right-aligned**.
        3.  If a text field is longer than 10 characters, it must be truncated, and the 10th character must be replaced with a dot (`.`).
        4.  After displaying the list, the program prompts the user for a contact's index to see more details. If the index is valid, it displays all the information for that contact, one field per line.
      * **`EXIT`:** The program terminates. All contacts are lost as they are not stored persistently.
  * **Files to Submit:** `Makefile`, all `*.cpp`, and all `*.hpp`/`*.h` source files.

## Exercise 02: The Job Of Your Dreams

  * **Objective:** Recreate the implementation file for a given class based on its header and test files.
  * **Scenario:** You are given the header file `Account.hpp`, a test file `tests.cpp`, and a log file showing the correct output from a successful test run. The source file `Account.cpp`, containing the implementation of the `Account` class, has been "lost".
  * **Task:** You must write the `Account.cpp` file from scratch. Your implementation must allow `tests.cpp` to compile and run, producing an output that perfectly matches the provided log file (with the exception of timestamps, which will naturally differ).
  * **Note:** This exercise is **not mandatory** to pass the module.
  * **Files to Submit:** `Makefile`, `Account.cpp`, `Account.hpp`, `tests.cpp`.
