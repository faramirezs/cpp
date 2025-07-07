/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wanimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:43:01 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/07 16:53:12 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WANIMAL_H__
#define __WANIMAL_H__

# include <string>
# include <iostream>
# include <limits>
# include <iomanip>
# include <stdlib.h>
# include <stdio.h>
# include <cctype>
# include <algorithm>
# include <cmath>

class Wanimal
{
	protected:
		std::string type;

    public:
		Wanimal& operator=(Wanimal const & rhs);
        Wanimal(Wanimal const & src);
		virtual ~Wanimal(void);
		Wanimal(std::string type);
		Wanimal();

		void makeSound() const;
		std::string getType() const;
};

#endif
