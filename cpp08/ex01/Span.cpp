/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:17:50 by alramire          #+#    #+#             */
/*   Updated: 2026/02/17 18:04:58 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : len(0) {}

Span::Span(unsigned int n) : len(n) {}

Span::Span(const Span &other) : data(other.data), len(other.len) {}

Span &Span::operator=(const Span &other) {
  if (this == &other)
    return *this;
  data = other.data;
  len = other.len;
  return *this;
}

Span::~Span() {}

void Span::addNumber(int num) {
  if (data.size() >= len)
    throw std::out_of_range("Out of bounds.");
  data.push_back(num);
}

unsigned int Span::longestSpan() const {
  if (data.size() < 2)
    throw std::out_of_range("Span need at least 2 elements.");

  int min = *std::min_element(data.begin(), data.end());
  int max = *std::max_element(data.begin(), data.end());
  unsigned int longest = static_cast<unsigned int>(max) - static_cast<unsigned int>(min);
  return (longest);
}

unsigned int Span::shortestSpan() const {
  if (data.size() < 2)
    throw std::out_of_range("Span need at least 2 elements.");
  std::vector<int> sorted = data;
  std::sort(sorted.begin(), sorted.end());
  unsigned int shortest = UINT_MAX;
  for (size_t i = 1; i < sorted.size(); ++i) {
        unsigned int span = static_cast<unsigned int>(sorted[i] - sorted[i-1]);
        if (span < shortest)
            shortest = span;
    }
    return shortest;
}

unsigned int Span::getSize() const { return data.size(); }
unsigned int Span::getLen() const { return len; }