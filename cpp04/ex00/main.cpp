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
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	std::cout << j->getType() << " " << std::endl;
	j->makeSound();
	const Animal* i = new Cat();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	std::cout << "====Animal sound====" << std::endl;
	meta->makeSound();
	std::cout << "====Wrong Animal====" << std::endl;
	const Wanimal* wmeta = new Wanimal();
	const Wanimal* k = new Wcat();
	std::cout << k->getType() << " " << std::endl;
	std::cout << "====Wrong Cat sound====" << std::endl;
	k->makeSound();
	std::cout << "====Wrong Animal sound====" << std::endl;
	wmeta->makeSound();
	return 0;
}


