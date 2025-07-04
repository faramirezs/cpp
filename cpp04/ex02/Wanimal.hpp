/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroramirez <alejandroramirez@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:43:01 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/02 17:56:30 by alejandrora      ###   ########.fr       */
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
		void makeSound() const;
		std::string getType() const;
		Wanimal(std::string type);
		Wanimal();
		virtual ~Wanimal(void);
};

class Wcat : public Wanimal
{
	public:
		virtual void makeSound() const;
		Wcat(std::string type);
		Wcat();
		~Wcat(void);
};

#endif
