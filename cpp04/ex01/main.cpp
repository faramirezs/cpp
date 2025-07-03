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
	Dog dog1("Rex");
	Dog dog2 = dog1;  // Copy

	// Modify dog1's brain
	dog1.getBrain()->ideas[0] = "I want food";
	dog2.getBrain()->ideas[0] = "I want to sleep";

	// Print both - are they different or the same?
	std::cout << "Dog1 idea: " << dog1.getBrain()->ideas[0] << std::endl;
	std::cout << "Dog2 idea: " << dog2.getBrain()->ideas[0] << std::endl;
	
	/* int i = 0;
	int j = 10;
	Animal * Animals[10];

	while(i < 5)
	{
		Animals[i] = new Dog();
		//Animals[i].getBrain()->ideas[0] = "hello";
		i++;
	}
	while(i < j)
	{
		Animals[i] = new Cat();
		i++;
	}
	for(int k = 0; k < j; k++)
	{
		std::cout << "Animal[" << k << "]: " << Animals[k]->getType() << std::endl;
	}
	for(int k = 0; k < j; k++)
	{
		std::cout << "Deleting Animal[" << k << "]" << std::endl;
		delete Animals[k];
	} */
	
	/* const Animal* meta = new Animal();
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
	wmeta->makeSound(); */
	return 0;
}


