/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operations.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 09:51:13 by alramire          #+#    #+#             */
/*   Updated: 2025/12/12 09:51:28 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Operations.hpp"
#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>

Base *generate() {

  int choice = rand() % 3;

  if (choice == 0)
    return new A();
  if (choice == 1)
    return new B();
  else
    return new C();
}

void identify(Base *p) { p->identify_self(); }

void identify(Base &p) { p.identify_self(); }
