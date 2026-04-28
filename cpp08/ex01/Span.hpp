/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:17:50 by alramire          #+#    #+#             */
/*   Updated: 2026/02/17 18:06:45 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <climits>

class Span {

private:
  std::vector<int> data;
  unsigned int len;

public:
  Span();
  Span(unsigned int);
  Span(const Span &);
  Span &operator=(const Span &);
  ~Span();

  void addNumber(int num);
  template <typename InputIterator>
  void addNumber(InputIterator first, InputIterator last) {
    if (data.size() + static_cast<unsigned int>(std::distance(first, last)) > len) {
      throw std::out_of_range("Out of bounds.");
    }
    data.insert(data.end(), first, last);
  }
  unsigned int shortestSpan() const;
  unsigned int longestSpan() const;
  unsigned int getSize() const;
  unsigned int getLen() const;
};