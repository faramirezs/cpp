/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:56:11 by alramire          #+#    #+#             */
/*   Updated: 2025/12/09 15:56:16 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SERIALIZER_H__
#define __SERIALIZER_H__

#include "Data.hpp"
#include <stdint.h>

class Serializer {

private:
  Serializer();
  Serializer(const Serializer &other);
  Serializer &operator=(const Serializer &other);
  ~Serializer();

public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};

#endif
