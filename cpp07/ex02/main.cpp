#include "Array.hpp"
#include <iostream>
#include <string>

int main(void) {

  std::cout << "Default constructor (empty array)" << std::endl;
  Array<int> empty;
  std::cout << "Size: " << empty.size() << std::endl;
  std::cout << std::endl;

  std::cout << "Constructor with size (Array<int> of 5 elements)"
            << std::endl;
  Array<int> intArray(5);
  std::cout << "Size: " << intArray.size() << std::endl;
  std::cout << "Elements (should be initialized to 0): ";
  for (unsigned int i = 0; i < intArray.size(); ++i) {
    std::cout << intArray[i] << " ";
  }
  std::cout << std::endl << std::endl;

  std::cout << "Assigning values to array" << std::endl;
  for (unsigned int i = 0; i < intArray.size(); ++i) {
    intArray[i] = i * 10;
  }
  std::cout << "Elements after assignment: ";
  for (unsigned int i = 0; i < intArray.size(); ++i) {
    std::cout << intArray[i] << " ";
  }
  std::cout << std::endl << std::endl;

  std::cout << "Copy constructor" << std::endl;
  Array<int> intArrayCopy(intArray);
  std::cout << "Original array: ";
  for (unsigned int i = 0; i < intArray.size(); ++i) {
    std::cout << intArray[i] << " ";
  }
  std::cout << std::endl;
  std::cout << "Copied array:   ";
  for (unsigned int i = 0; i < intArrayCopy.size(); ++i) {
    std::cout << intArrayCopy[i] << " ";
  }
  std::cout << std::endl << std::endl;

  std::cout << "Assignment operator" << std::endl;
  Array<int> intArrayAssigned(3);
  std::cout << "Before assignment - assigned array: ";
  for (unsigned int i = 0; i < intArrayAssigned.size(); ++i) {
    std::cout << intArrayAssigned[i] << " ";
  }
  std::cout << " (size: " << intArrayAssigned.size() << ")" << std::endl;

  intArrayAssigned = intArray;
  std::cout << "After assignment - assigned array:  ";
  for (unsigned int i = 0; i < intArrayAssigned.size(); ++i) {
    std::cout << intArrayAssigned[i] << " ";
  }
  std::cout << " (size: " << intArrayAssigned.size() << ")" << std::endl
            << std::endl;

  std::cout << "Out of bounds" << std::endl;
  try {
    std::cout << "Accessing valid index (2): " << intArray[2] << std::endl;
    std::cout << "Attempting to access invalid index (10)..." << std::endl;
    std::cout << intArray[10] << std::endl; // This will throw
  } catch (const std::out_of_range &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }
  std::cout << std::endl;

  std::cout << "Array of strings" << std::endl;
  Array<std::string> stringArray(3);
  stringArray[0] = "hello";
  stringArray[1] = "world";
  stringArray[2] = "cpp";
  std::cout << "String array: ";
  for (unsigned int i = 0; i < stringArray.size(); ++i) {
    std::cout << "[" << stringArray[i] << "] ";
  }
  std::cout << std::endl << std::endl;

  std::cout << "Copy of string array" << std::endl;
  Array<std::string> stringArrayCopy = stringArray;
  stringArrayCopy[0] = "goodbye";
  std::cout << "Original first element: " << stringArray[0] << std::endl;
  std::cout << "Copied first element:   " << stringArrayCopy[0] << std::endl;
  std::cout << std::endl;

  std::cout << "Array of doubles" << std::endl;
  Array<double> doubleArray(4);
  for (unsigned int i = 0; i < doubleArray.size(); ++i) {
    doubleArray[i] = i + 0.5;
  }
  std::cout << "Double array: ";
  for (unsigned int i = 0; i < doubleArray.size(); ++i) {
    std::cout << doubleArray[i] << " ";
  }
  std::cout << std::endl << std::endl;

  // ========== Test 12: Empty Array Operations ==========
  std::cout << "Test 12: Empty array operations" << std::endl;
  Array<int> emptyArray(0);
  std::cout << "Empty array size: " << emptyArray.size() << std::endl;
  try {
    emptyArray[0]; // Even index 0 is out of bounds for empty array
  } catch (const std::out_of_range &e) {
    std::cout << "Exception for empty array access: " << e.what() << std::endl;
  }
  std::cout << std::endl;
  
  std::cout << "Chained assignment" << std::endl;
  Array<int> a(3), b(2), c(1);
  a[0] = 1;
  a[1] = 2;
  a[2] = 3;
  b[0] = 4;
  b[1] = 5;
  c[0] = 6;

  std::cout << "Before: " << std::endl;
std::cout << "a: ";
  for (unsigned int i = 0; i < a.size(); ++i)
    std::cout << a[i] << " ";
  std::cout << std::endl;
  std::cout << "b: ";
  for (unsigned int i = 0; i < b.size(); ++i)
    std::cout << b[i] << " ";
  std::cout << std::endl;
  std::cout << "c: ";
  for (unsigned int i = 0; i < c.size(); ++i)
    std::cout << c[i] << " ";
  std::cout << std::endl << std::endl;

  std::cout << "After c = b = a:" << std::endl;

  c = b = a; // Chained assignment
  
std::cout << "a: ";
  for (unsigned int i = 0; i < a.size(); ++i)
    std::cout << a[i] << " ";
  std::cout << std::endl;
  std::cout << "b: ";
  for (unsigned int i = 0; i < b.size(); ++i)
    std::cout << b[i] << " ";
  std::cout << std::endl;
  std::cout << "c: ";
  for (unsigned int i = 0; i < c.size(); ++i)
    std::cout << c[i] << " ";
  std::cout << std::endl << std::endl;
  return 0;
}
