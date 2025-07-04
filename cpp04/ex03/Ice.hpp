/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroramirez <alejandroramirez@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:43:01 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/02 17:45:48 by alejandrora      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_H__
#define __ANIMAL_H__

# include <string>
# include <iostream>
# include <limits>
# include <iomanip>
# include <stdlib.h>
# include <stdio.h>
# include <cctype>
# include <algorithm>
# include <cmath>


class AMateria
{
	protected:
		//[...]
	public:
		AMateria(std::string const & type);
		//[...]
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};


/* class Animal
{
	protected:
		std::string type;

    public:
		virtual void makeSound() const = 0;
		std::string getType() const;
		Animal(Animal const & rhs); 
		Animal(std::string type);
		Animal();
		virtual ~Animal(void);
};

class Brain
{
	public:
	std::string ideas[100];
	Brain();
	virtual ~Brain(void);
}; */

#endif
