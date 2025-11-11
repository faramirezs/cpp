/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:42:57 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/09 12:02:29 by alramire         ###   ########.fr       */
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
	std::cout << "MateriaSource copy constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (src.spellBook[i])
			spellBook[i] = src.spellBook[i]->clone();
		else
			spellBook[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(MateriaSource const & rhs)
{
	std::cout << "MateriaSource assignment operator called." << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			if (spellBook[i])
			{
				delete spellBook[i];
				spellBook[i] = NULL;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			if (rhs.spellBook[i])
				spellBook[i] = rhs.spellBook[i]->clone();
			else
				spellBook[i] = NULL;
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if(!materia)
		return;
	for (int i = 0; i < 4; i++) 
	{
        if(!spellBook[i])
		{
			spellBook[i] = materia->clone();
			delete materia;
			return;
		}
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++) 
	{
        if(spellBook[i])
		{
			if (spellBook[i]->getType() == type)
				return spellBook[i];

		}
    }
	return NULL;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++) 
	{
        if(spellBook[i])
			delete spellBook[i];
    }
	std::cout << "MateriaSource destructor called." << std::endl;
}