/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:43:01 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/04 14:58:16 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CHARACTER_H__
#define __CHARACTER_H__

# include <string>
# include <iostream>
# include <limits>
# include <iomanip>
# include <stdlib.h>
# include <stdio.h>
# include <cctype>
# include <algorithm>
# include <cmath>


/* The Character possesses an inventory of 4 slots, which means at most 4 Materias.
The inventory is empty upon construction. They equip the Materias in the first empty
slot they find, in the following order: from slot 0 to slot 3. If they try to add a Materia to
a full inventory, or use/unequip a non-existent Materia, nothing should happen (but bugs
are still forbidden). The unequip() member function must NOT delete the Materia! */


class Character
{
	public:
	virtual ~Character() {}
	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, Character& target);
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
