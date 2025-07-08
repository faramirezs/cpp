/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:42:46 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/08 08:11:54 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "Wanimal.hpp"
# include "Wcat.hpp"

int main()
{
	const Animal* j = new Dog();
	std::cout << "type: " << j->getType() << " " << std::endl;
	j->makeSound();
	const Animal* i = new Cat();
	std::cout << "type: " << i->getType() << " " << std::endl;
	i->makeSound();
	std::cout << "====Destructors====" << std::endl;
	delete j;
	delete i;

	std::cout << "====Wrong Animal====" << std::endl;
	Wanimal* wmeta = new Wanimal();
	Wanimal* k = new Wcat();
	std::cout << "type: " << k->getType() << " " << std::endl;

	std::cout << "====Wrong Cat sound====" << std::endl;
	k->makeSound();

	std::cout << "====Wrong Animal sound====" << std::endl;
	wmeta->makeSound();

	std::cout << "====Wrong Cat sound (static_cast)====" << std::endl;
	static_cast<Wcat*>(k)->makeSound();

	std::cout << "====Destructors====" << std::endl;
	delete static_cast<Wcat*>(k);
	delete wmeta;

	return 0;
}


