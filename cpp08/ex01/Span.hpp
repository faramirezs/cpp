/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:17:50 by alramire          #+#    #+#             */
/*   Updated: 2026/02/10 10:40:21 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include <vector>
#include <cstdlib>

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
  void addBatch(int *start, int *end);
  int shortestSpan();
  int longestSpan();
  int &operator[](unsigned int);
  unsigned int getsize();
  unsigned int getlen();
};