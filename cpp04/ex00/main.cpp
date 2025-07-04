/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroramirez <alejandroramirez@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:42:46 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/02 16:42:17 by alejandrora      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "Wanimal.hpp"

int main()
{
	const Animal* j = new Dog();
	std::cout << j->getType() << " " << std::endl;
	j->makeSound();
	const Animal* i = new Cat();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	std::cout << "====Destructors====" << std::endl;
	delete j;
	delete i;

	std::cout << "====Wrong Animal====" << std::endl;
	Wanimal* wmeta = new Wanimal();
	Wanimal* k = new Wcat();
	std::cout << k->getType() << " " << std::endl;
	std::cout << "====Wrong Cat sound====" << std::endl;
	k->makeSound();
	std::cout << "====Wrong Animal sound====" << std::endl;
	wmeta->makeSound();
	delete static_cast<Wcat*>(k);
	delete wmeta;

	return 0;
}


