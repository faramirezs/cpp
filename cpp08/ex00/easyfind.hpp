/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:17:50 by alramire          #+#    #+#             */
/*   Updated: 2025/12/13 14:17:52 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once
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
