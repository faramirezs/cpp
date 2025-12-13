#pragma once
#include <iostream>
#include <stdexcept>

template <typename T> class Array {

private:
  T *data;
  unsigned int len;

public:
  Array();
  Array(unsigned int);
  Array(const Array<T> &);
  Array<T> &operator=(const Array<T> &);
  ~Array();

  T &operator[](unsigned int);
  const T &operator[](unsigned int) const;
  unsigned int size() const;
};

template <typename T> Array<T>::Array() : data(NULL), len(0) {}

template <typename T> Array<T>::Array(unsigned int n) : data(NULL), len(n) {
  if (n > 0)
    data = new T[n]();
}

template <typename T>
Array<T>::Array(const Array<T> &other) : data(NULL), len(other.len) {
  if (len > 0)
    data = new T[len]();
  for (unsigned int i = 0; i < len; i++) {
    data[i] = other.data[i];
  }
}

template <typename T> Array<T> &Array<T>::operator=(const Array<T> &other) {
  if (this == &other)
    return *this;
  T *tmp = new T[other.len]();

  for (unsigned int i = 0; i < other.len; i++) {
    tmp[i] = other.data[i];
  }

  delete[] data;
  data = tmp;
  len = other.len;
  return *this;
}

template <typename T> Array<T>::~Array() {
  delete[] data;
  data = NULL;
}

template <typename T> const T &Array<T>::operator[](unsigned int index) const {
  if (index >= len)
    throw std::out_of_range("Out of bounds.");
  else
    return data[index];
}

template <typename T> T &Array<T>::operator[](unsigned int index) {
  if (index >= len)
    throw std::out_of_range("Out of bounds.");
  else
    return data[index];
}

template <typename T> unsigned int Array<T>::size() const { return len; }
