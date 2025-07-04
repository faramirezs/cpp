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
# include <string>

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
	std::cout << "====Destructors====" << std::endl;
	delete static_cast<Wcat*>(k);
	delete wmeta;
	
	/* int j = 10;
	Animal * Animals[10];
	std::string baseIdea = "idea ";

	for(int i = 0; i < 5; i++)
	{
		Animals[i] = new Dog();
		static_cast<Dog*>(Animals[i])->getBrain().ideas[0] = baseIdea;
		baseIdea += baseIdea;
	}
	baseIdea = "idea ";
	for(int i = 5; i < j; i++)
	{
		Animals[i] = new Cat();
		static_cast<Cat*>(Animals[i])->getBrain().ideas[0] = baseIdea;
		baseIdea += baseIdea;
	}
	for(int k = 0; k < j; k++)
	{
		std::cout << "Animal[" << k << "]: " << Animals[k]->getType() << ": Brain: " 
			<< static_cast<Dog*>(Animals[k])->getBrain().ideas[0] << std::endl;
	}
	for(int k = 0; k < j; k++)
	{
		std::cout << "Deleting Animal[" << k << "]" << std::endl;
		delete Animals[k];
	}
	return 0; */
}


