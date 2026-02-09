/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:17:50 by alramire          #+#    #+#             */
/*   Updated: 2026/02/09 11:03:48 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T> typename T::iterator easyfind(T &container, int value) {
  for (typename T::iterator it = container.begin(); it != container.end();
       it++) {
    if (*it == value)
      return it;
  }
  throw std::runtime_error("Not found");
}

class Span {

private:
  int *data;
  unsigned int len;
  unsigned int size;

public:
  Span();
  Span(unsigned int);
  Span(const Span &);
  Span &operator=(const Span &);
  ~Span();

  void addNumber(int num);
  // shortestSpan()
  // longestSpan()
  int &operator[](unsigned int);
  // const T &operator[](unsigned int) const;
  unsigned int getsize();
  unsigned int getlen();
};

Span::Span() : data(NULL), len(0), size(0) {}

Span::Span(unsigned int n) : data(NULL), len(n) {
  if (n > 0) {
    size = 0;
    data = new int[n]();
    for (unsigned int i = 0; i < len; i++) {
      data[i] = 0;
    }
  }
  else
    throw std::out_of_range("Out of bounds.");
}

Span::Span(const Span &other) : data(NULL), len(other.len) {
  if (len > 0)
    data = new int[len]();
  for (unsigned int i = 0; i < len; i++) {
    data[i] = other.data[i];
  }
}

Span &Span::operator=(const Span &other) {
  if (this == &other)
    return *this;
  int *tmp = new int[other.len]();

  for (unsigned int i = 0; i < other.len; i++) {
    tmp[i] = other.data[i];
  }

  delete[] data;
  data = tmp;
  len = other.len;
  return *this;
}

Span::~Span() {
  delete[] data;
  data = NULL;
}

void Span::addNumber(int num) {
  if (size + 1 >= len)
     throw std::out_of_range("Out of bounds.");   
  else {
    data[size] = num;
    size++;
  }
}

int &Span::operator[](unsigned int index) {
  if (index >= len)
    throw std::out_of_range("Out of bounds.");
  else
    return data[index];
}

// template <typename T> T &Span<T>::operator[](unsigned int index) {
//   if (index >= len)
//     throw std::out_of_range("Out of bounds.");
//   else
//     return data[index];
// }

unsigned int Span::getsize() { return size; }
unsigned int Span::getlen() { return len; }