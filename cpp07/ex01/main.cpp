#include "iter.hpp"
#include <iostream>
#include <string>

// Functions for non-const references (can modify)
void incrementInt(int &x) { x++; }

// Functions for const references (can only read)
void printInt(const int &x) { std::cout << x << " "; }

// Generic print function that works with any type
template <typename T> void printElement(const T &element) {
  std::cout << element << " ";
}

// Generic increment function for numeric types
template <typename T> void increment(T &element) { element++; }

int main(void) {
  std::cout << "Non-const int array, increment each element" << std::endl;
  int arr1[5] = {1, 2, 3, 4, 5};
  std::cout << "Before: ";
  iter(arr1, 5, printInt);
  std::cout << std::endl;

  iter(arr1, 5, incrementInt);

  std::cout << "After:  ";
  iter(arr1, 5, printInt);
  std::cout << std::endl << std::endl;

  // ========== Const int array with read-only function ==========
  std::cout << "Const int array, print each element" << std::endl;
  const int arr3[5] = {10, 20, 30, 40, 50};
  std::cout << "Array: ";
  iter(arr3, 5, printInt);
  std::cout << std::endl << std::endl;

  // ========== Using template function (explicit instantiation) ==========
  std::cout << "Template function instantiation with integers" << std::endl;
  int arr7[3] = {100, 200, 300};
  std::cout << "Before: ";
  iter(arr7, 3, printElement<int>);
  std::cout << std::endl;

  iter(arr7, 3, increment<int>);

  std::cout << "After:  ";
  iter(arr7, 3, printElement<int>);
  std::cout << std::endl << std::endl;

  return 0;
}
