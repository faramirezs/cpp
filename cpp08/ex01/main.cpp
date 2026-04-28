/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:30:03 by alramire          #+#    #+#             */
/*   Updated: 2026/02/17 17:59:19 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <vector>


int main(void) {

  // === Subject mandatory test ===
  std::cout << "=== Subject test ===" << std::endl;
  {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  }
  std::cout << std::endl;

    // === Subject mandatory test ===
  std::cout << "=== 0 test ===" << std::endl;
  {
    Span sp = Span(0);
    try {
      sp.addNumber(4);
    } catch (const std::out_of_range &e) {
      std::cout << "Exception caught: " << e.what() << std::endl;
    }
    try {
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    } catch (const std::out_of_range &e) {
      std::cout << "Exception caught: " << e.what() << std::endl;
    }

  }
  std::cout << std::endl;

  // === Overflow test ===
  std::cout << "=== Overflow test ===" << std::endl;
  {
    Span sp(3);
    sp.addNumber(1);
    sp.addNumber(2);
    sp.addNumber(3);
    try {
      sp.addNumber(4);
    } catch (const std::out_of_range &e) {
      std::cout << "Exception caught: " << e.what() << std::endl;
    }
  }
  std::cout << std::endl;

  // === Copy constructor ===
  std::cout << "=== Copy constructor ===" << std::endl;
  {
    Span original(5);
    original.addNumber(6);
    original.addNumber(3);
    original.addNumber(17);
    original.addNumber(9);
    original.addNumber(11);

    Span copy(original);
    std::cout << "Original shortest: " << original.shortestSpan() << std::endl;
    std::cout << "Copy shortest:     " << copy.shortestSpan() << std::endl;
    std::cout << "Original longest:  " << original.longestSpan() << std::endl;
    std::cout << "Copy longest:      " << copy.longestSpan() << std::endl;
  }
  std::cout << std::endl;

  // === Assignment operator ===
  std::cout << "=== Assignment operator ===" << std::endl;
  {
    Span a(5);
    a.addNumber(6);
    a.addNumber(3);
    a.addNumber(17);
    a.addNumber(9);
    a.addNumber(11);

    Span b(2);
    b = a;
    std::cout << "Assigned shortest: " << b.shortestSpan() << std::endl;
    std::cout << "Assigned longest:  " << b.longestSpan() << std::endl;
  }
  std::cout << std::endl;

  // === Range addNumber with iterators ===
  std::cout << "=== Range addNumber (iterator) ===" << std::endl;
  {
    int arr[] = {1, 5, 28, 90, -1, 10};
    Span sp(6);
    sp.addNumber(arr, arr + 6);
    std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest:  " << sp.longestSpan() << std::endl;
  }
  std::cout << std::endl;

  // === Range addNumber overflow ===
  std::cout << "=== Range addNumber overflow ===" << std::endl;
  {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Span sp(5);
    try {
      sp.addNumber(arr, arr + 10);
    } catch (const std::out_of_range &e) {
      std::cout << "Exception caught: " << e.what() << std::endl;
    }
  }
  std::cout << std::endl;

  // === Range addNumber from std::vector ===
  std::cout << "=== Range addNumber from vector ===" << std::endl;
  {
    std::vector<int> v;
    v.push_back(42);
    v.push_back(7);
    v.push_back(100);
    Span sp(3);
    sp.addNumber(v.begin(), v.end());
    std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest:  " << sp.longestSpan() << std::endl;
  }
  std::cout << std::endl;

  // === 10,000 elements ===
  std::cout << "=== 10,000 elements ===" << std::endl;
  {
    std::vector<int> v;
    for (int i = 0; i < 10000; ++i)
      v.push_back(i);
    Span big(10000);
    big.addNumber(v.begin(), v.end());
    std::cout << "Size: " << big.getSize() << std::endl;
    std::cout << "Shortest: " << big.shortestSpan() << std::endl;
    std::cout << "Longest:  " << big.longestSpan() << std::endl;
  }
  std::cout << std::endl;

  // === Edge: too few elements ===
  std::cout << "=== Edge: too few elements ===" << std::endl;
  {
    Span sp(1);
    sp.addNumber(42);
    try {
      std::cout << sp.shortestSpan() << std::endl;
    } catch (const std::out_of_range &e) {
      std::cout << "Exception caught: " << e.what() << std::endl;
    }
  }

  return 0;
}
