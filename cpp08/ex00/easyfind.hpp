/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:17:50 by alramire          #+#    #+#             */
/*   Updated: 2026/02/12 14:56:00 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <numeric>

template <typename T> typename T::iterator easyfind(T &container, int value) {
  
  typename T::iterator it = std::find(container.begin(), container.end(), value);
  if (it != container.end())
      return it;
  throw std::runtime_error("Not found");
}


