/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:43:01 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/09 08:09:47 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRAGTRAP_H__
#define __FRAGTRAP_H__

# include <string>
# include <iostream>
# include <limits>
# include <iomanip>
# include <stdlib.h>
# include <stdio.h>
# include <cctype>
# include <algorithm>
# include <cmath>
# include "ClapTrap.hpp"


class FragTrap : public ClapTrap
{
    public:

		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const & src);
		FragTrap& operator=(FragTrap const & rhs);
		~FragTrap(void);
		void attack(const std::string& target);
		void highFivesGuys(void);
};

#endif
