/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:43:01 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/09 11:58:02 by alramire         ###   ########.fr       */
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
# include "ICharacter.hpp"


/* The Character possesses an inventory of 4 slots, which means at most 4 Materias.
The inventory is empty upon construction. They equip the Materias in the first empty
slot they find, in the following order: from slot 0 to slot 3. If they try to add a Materia to
a full inventory, or use/unequip a non-existent Materia, nothing should happen (but bugs
are still forbidden). The unequip() member function must NOT delete the Materia! */


// The use(int, ICharacter&) member function will have to use the Materia at the
// slot[idx], and pass the target parameter to the AMateria::use function.


// Your Character must have a constructor taking its name as a parameter. Any copy
// (using copy constructor or copy assignment operator) of a Character must be deep.
// During copy, the Materias of a Character must be deleted before the new ones are added
// to their inventory. Of course, the Materias must be deleted when a Character is destroyed.

class Character : public ICharacter
{
	public:
		Character();
		Character(std::string const & name);
		Character(Character const & src);
		Character& operator=(Character const & rhs);
		virtual ~Character();
	
		AMateria * slot[4];
		const std::string name;
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};

#endif
