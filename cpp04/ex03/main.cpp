/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:42:46 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/08 16:00:00 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include "Character.hpp"
# include "IMateriaSource.hpp"
# include "MateriaSource.hpp"
# include "Ice.hpp"
# include "Cure.hpp"


int main()
{	
	//MVP mode
	ICharacter* character = new Character("test");
	std::cout << character->getName() << std::endl;
	delete character;
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	// for (int i = 0; i < 4; i++) 
	// {
	// 	if(src->spellBook[i])
	// 		std::cout << src->spellBook[i].type << std::endl;
    // }
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	std::cout << me->getName() << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}


