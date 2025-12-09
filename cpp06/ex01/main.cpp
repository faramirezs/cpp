/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:46:46 by alramire          #+#    #+#             */
/*   Updated: 2025/11/11 13:38:52 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main() {
  // Create a Data object on the stack
  Data original;
  original.value = 42;
  original.name = "Berlin";

  // Get the original pointer
  Data *original_ptr = &original;

  std::cout << "=== Serialization Test ===" << std::endl;
  std::cout << "Original pointer address: " << original_ptr << std::endl;
  std::cout << "Original pointer value: " << original.value << std::endl;
  std::cout << "Original pointer name: " << original.name << std::endl;

  // Serialize the pointer
  uintptr_t serialized = Serializer::serialize(original_ptr);
  std::cout << "\nSerialized to integer: " << serialized << std::endl;

  // Deserialize back to pointer
  Data *deserialized_ptr = Serializer::deserialize(serialized);
  std::cout << "\nDeserialized pointer address: " << deserialized_ptr
            << std::endl;
  std::cout << "Deserialized pointer value: " << deserialized_ptr->value
            << std::endl;
  std::cout << "Deserialized pointer name: " << deserialized_ptr->name
            << std::endl;
  // Heap test
  Data *heap_obj = new Data();
  std::cout << "=== Serialization Test Heap ===" << std::endl;
  std::cout << "Heap pointer address: " << heap_obj << std::endl;
  uintptr_t serialized_h = Serializer::serialize(heap_obj);
  std::cout << "\nHeap Serialized to integer: " << serialized_h << std::endl;
  Data *restored = Serializer::deserialize(serialized_h);
  std::cout << "\nDeserialized heap pointer address: " << restored << std::endl;
  delete heap_obj;

  // Verify we cannot instantiate Serializer
  // Uncommenting this line will cause a compilation error:
  // Serializer s;  // Error: constructor is private

  return 0;
}
