/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:43:01 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/07 17:10:23 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_H__
#define __DOG_H__

# include <string>
# include <iostream>
# include <limits>
# include <iomanip>
# include <stdlib.h>
# include <stdio.h>
# include <cctype>
# include <algorithm>
# include <cmath>
# include "Animal.hpp"


class Dog : public Animal
{
	public:
		Dog();
		Dog(Dog const & src);
		Dog& operator=(Dog const & rhs);
        virtual ~Dog(void);

		virtual void makeSound() const;
};

#endif
