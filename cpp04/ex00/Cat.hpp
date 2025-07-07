/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:43:01 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/07 17:07:31 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_H__
#define __CAT_H__

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


class Cat : public Animal
{
	public:
		Cat();
		Cat(Cat const & src);
		Cat& operator=(Cat const & rhs);
        virtual ~Cat(void);

		virtual void makeSound() const;
};

#endif
