/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wanimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:43:01 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/08 08:15:53 by alramire         ###   ########.fr       */
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
		Wanimal();
		Wanimal(std::string type);
		Wanimal(Wanimal const & src);
		Wanimal& operator=(Wanimal const & rhs);
		virtual ~Wanimal(void);

		void makeSound() const;
		std::string getType() const;
};

#endif
