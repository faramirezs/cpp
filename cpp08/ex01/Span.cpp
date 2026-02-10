/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:17:50 by alramire          #+#    #+#             */
/*   Updated: 2026/02/10 10:40:54 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

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

Span::Span(const Span &other) : data(NULL), len(other.len), size(other.size) {
  if (len > 0)
    data = new int[len]();
  for (unsigned int i = 0; i < size; i++) {
    data[i] = other.data[i];
  }
}

Span &Span::operator=(const Span &other) {
  if (this == &other)
    return *this;
  int *tmp = new int[other.len]();

  for (unsigned int i = 0; i < other.size; i++) {
    tmp[i] = other.data[i];
  }

  delete[] data;
  data = tmp;
  len = other.len;
  size = other.size;
  return *this;
}

Span::~Span() {
  delete[] data;
  data = NULL;
}

void Span::addNumber(int num) {
  if (size + 1 > len){
    std::cout << "Size: " << getsize() << std::endl;
    std::cout << "Len: " << getlen() << std::endl;
    throw std::out_of_range("Out of bounds.");   
  }
  else {
    data[size++] = num;
  }
}

void Span::addBatch(int *start, int *end) {
  if (size + (end - start ) > len) {
    std::cout << "Size: " << getsize() << std::endl;
    std::cout << "Len: " << getlen() << std::endl;
    throw std::out_of_range("Out of bounds.");   
  }
  else {
    while(start < end){
      data[size++] = *start++;
    }
  }
}

int Span::longestSpan(){
  if (size < 2)
    throw std::out_of_range("Span need at least 2 elements.");
  int min;
  int max;
  min = data[0];
  max = data[0];
  for (size_t i = 0; i < size; i++)
  {
    if (min > data[i]){
      min = data[i];
    }
  }
  for (size_t i = 0; i < size; i++)
  {
    if (max < data[i])
      max = data[i];
  }
  return(max - min);
}

int Span::shortestSpan(){
  if (size < 2)
    throw std::out_of_range("Span need at least 2 elements.");
  int min;
  min = std::abs(data[0] - data[1]);
  for (size_t i = 0; i < size; i++)
  {
    for (size_t j = i + 1; j < size; j++)
    {
      if (min > std::abs(data[j]-data[i]))
        min = std::abs(data[j]-data[i]);
    }
  }
  return(min);
}

int &Span::operator[](unsigned int index) {
  if (index >= len)
    throw std::out_of_range("Out of bounds.");
  else
    return data[index];
}

unsigned int Span::getsize() { return size; }
unsigned int Span::getlen() { return len; }