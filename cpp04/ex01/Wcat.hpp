/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wcat.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:43:01 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/07 17:06:50 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WCAT_H__
#define __WCAT_H__

# include <string>
# include <iostream>
# include <limits>
# include <iomanip>
# include <stdlib.h>
# include <stdio.h>
# include <cctype>
# include <algorithm>
# include <cmath>
# include "Wanimal.hpp"


class Wcat : public Wanimal
{
	public:
		Wcat();
		Wcat(Wcat const & src);
		Wcat& operator=(Wcat const & rhs);
        virtual ~Wcat(void);
	
		virtual void makeSound() const;
};

#endif
