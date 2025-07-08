/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:42:57 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/08 16:59:36 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "Default MateriaSource constructor called" << std::endl;
	for (int i = 0; i < 4; i++) 
	{
        spellBook[i] = NULL;
    }
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
	(void)src;
	std::cout << "MateriaSource copy constructor called." << std::endl;
}

MateriaSource& MateriaSource::operator=(MateriaSource const & rhs)
{
	(void)rhs;
	std::cout << "MateriaSource assignment constructor called." << std::endl;
	// if(this != &rhs)
	// {
	// 	this->type = rhs.type;
	// }
	return(*this);
}

// Copies the Materia passed as a parameter and stores it in memory so it can be cloned
// later. Like the Character, the MateriaSource can know at most 4 Materias. They
// are not necessarily unique.

void MateriaSource::learnMateria(AMateria* materia)
{
	if(!materia)
		return;
	for (int i = 0; i < 4; i++) 
	{
        if(!spellBook[i])
		{
			spellBook[i] = materia->clone();
		}
    }
}

// Returns a new Materia. The latter is a copy of the Materia previously learned by
// the MateriaSource whose type equals the one passed as parameter. Returns 0 if
// the type is unknown.

AMateria* MateriaSource::createMateria(std::string const & type)
{
	// std::cout << "Create materia" << std::endl;
	for (int i = 0; i < 4; i++) 
	{
        if(spellBook[i])
		{
			if (spellBook[i]->getType() == type)
				return spellBook[i];
			else
				return NULL;
		}
    }
	return NULL;
}