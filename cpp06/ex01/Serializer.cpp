/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:55:56 by alramire          #+#    #+#             */
/*   Updated: 2025/12/09 15:56:01 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &other) { (void)other; }
Serializer &Serializer::operator=(const Serializer &other) {
  (void)other;
  return *this;
}
Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data *ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}
Data *Serializer::deserialize(uintptr_t raw) {
  return reinterpret_cast<Data *>(raw);
}
