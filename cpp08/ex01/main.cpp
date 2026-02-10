/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:30:03 by alramire          #+#    #+#             */
/*   Updated: 2026/02/10 11:30:06 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <vector>


int main(void) {

  std::cout << "Default constructor (empty array)" << std::endl;
  Span empty;
  std::cout << "Size: " << empty.getsize() << std::endl;
  std::cout << std::endl;

  std::cout << "Constructor with size of 5"
            << std::endl;
  Span intArray(5);
  std::cout << "Size: " << intArray.getsize() << std::endl;
  std::cout << "Elements (should be initialized to 0): ";
  for (unsigned int i = 0; i < intArray.getlen(); ++i) {
    std::cout << intArray[i] << " ";
  }
  std::cout << std::endl << std::endl;

  std::cout << "Assigning values to array" << std::endl;
  intArray.addNumber(6);
  std::cout << "Elements after addNumber: ";
  for (unsigned int i = 0; i < intArray.getlen(); ++i) {
    std::cout << intArray[i] << " ";
  }
  std::cout << std::endl << std::endl;

  intArray.addNumber(3);
  std::cout << "Elements after addNumber: ";
  for (unsigned int i = 0; i < intArray.getlen(); ++i) {
    std::cout << intArray[i] << " ";
  }
  std::cout << std::endl << std::endl;

  intArray.addNumber(17);
  std::cout << "Elements after addNumber: ";
  for (unsigned int i = 0; i < intArray.getlen(); ++i) {
    std::cout << intArray[i] << " ";
  }
  std::cout << std::endl << std::endl;

  intArray.addNumber(9);
  std::cout << "Elements after addNumber: ";
  for (unsigned int i = 0; i < intArray.getlen(); ++i) {
    std::cout << intArray[i] << " ";
  }
  std::cout << std::endl << std::endl;

  intArray.addNumber(11);
  std::cout << "Elements after addNumber: ";
  for (unsigned int i = 0; i < intArray.getlen(); ++i) {
    std::cout << intArray[i] << " ";
  }
  std::cout << std::endl << std::endl;

  std::cout << "Out of bounds" << std::endl;
  try {
    intArray.addNumber(6); //This will throw
  } catch (const std::out_of_range &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }
  std::cout << std::endl;

  std::cout << "Shortest span: ";
  std::cout << intArray.shortestSpan() << " ";
  std::cout << std::endl << std::endl;

  std::cout << "Longest span: ";
  std::cout << intArray.longestSpan() << " ";
  std::cout << std::endl << std::endl;

  std::cout << "Copy constructor" << std::endl;
  Span intArrayCopy(intArray);
  std::cout << "Original array: ";
  for (unsigned int i = 0; i < intArray.getlen(); ++i) {
    std::cout << intArray[i] << " ";
  }
  std::cout << std::endl;
  std::cout << "Copied array:   ";
  for (unsigned int i = 0; i < intArrayCopy.getlen(); ++i) {
    std::cout << intArrayCopy[i] << " ";
  }
  std::cout << std::endl << std::endl;

  std::cout << "Assignment operator" << std::endl;
  Span intArrayAssigned(3);
  std::cout << "Before assignment - assigned array: ";
  for (unsigned int i = 0; i < intArrayAssigned.getlen(); ++i) {
    std::cout << intArrayAssigned[i] << " ";
  }
  std::cout << " (size: " << intArrayAssigned.getlen() << ")" << std::endl;

  intArrayAssigned = intArray;
  std::cout << "After assignment - assigned array:  ";
  for (unsigned int i = 0; i < intArrayAssigned.getlen(); ++i) {
    std::cout << intArrayAssigned[i] << " ";
  }
  std::cout << " (size: " << intArrayAssigned.getlen() << ")" << std::endl
            << std::endl;

  std::cout << "Add batch numbers" << std::endl;
  int fitArray[] = {1, 5, 28, 90, -1, 10};
  int noFitArray[] = {1, 5, 28, 90, -1, 10, 1, 5, 28, 90, -1, 10, 1, 5, 28, 90, -1, 10, 1, 5, 28, 90, -1, 10};
  std::cout << "New array which fits: ";
  Span fit(6);
  fit.addBatch(fitArray, fitArray + 6);
  for (unsigned int i = 0; i < fit.getlen(); ++i) {
    std::cout << fit[i] << " ";
  }
  std::cout << std::endl << std::endl;

  std::cout << "Out of bounds in add batch numbers" << std::endl;
  try {
    fit.addBatch(noFitArray, noFitArray + 24); //This will throw
  } catch (const std::out_of_range &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }
  std::cout << std::endl;

  std::cout << "10.000 elements" << std::endl;
  int bigArray[10000];
  for (unsigned int i = 0; i < 10000; ++i) {
    bigArray[i] = i;
  }
  Span big(10000);
  big.addBatch(bigArray, bigArray + 10000);
  std::cout << "Big array last 100: ";
  for (unsigned int i = 9900; i < big.getsize(); ++i) {
    std::cout << big[i] << " ";
  }
  std::cout << std::endl << std::endl;
  std::cout << "Size: " << big.getsize() << std::endl;

  std::cout << "Shortest span: ";
  std::cout << big.shortestSpan() << " ";
  std::cout << std::endl << std::endl;

  std::cout << "Longest span: ";
  std::cout << big.longestSpan() << " ";
  std::cout << std::endl << std::endl;

}
