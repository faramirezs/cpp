/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:42:46 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/08 11:14:17 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "Wanimal.hpp"
# include "Wcat.hpp"
# include <string>

int main()
{	
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
	}
	
	{
		int j = 10;
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
	}

	std::cout << "====Dog and Cat deep copies====" << std::endl;
	Dog a;
	a.getBrain().ideas[0] = "Idea dog a";
	std::cout << "Dog 'a' idea: " << a.getBrain().ideas[0]<< std::endl;
	std::cout << "====Dog 'a' copy into Dog 'b'====" << std::endl;
	Dog b(a);
	std::cout << "Dog 'b' idea: " << b.getBrain().ideas[0]<< std::endl;
	std::cout << "Has Dog 'b' its own brain?" << std::endl;
	b.getBrain().ideas[0] = "Idea dog b";
	std::cout << "Dog 'b' idea: " << b.getBrain().ideas[0]<< std::endl;
	std::cout << "Dog 'a' idea: " << a.getBrain().ideas[0]<< std::endl;
	std::cout << "Can Dog 'b' convince Dog 'a'?" << std::endl;
	a = b;
	std::cout << "Dog 'b' idea: " << b.getBrain().ideas[0]<< std::endl;
	std::cout << "Dog 'a' idea: " << a.getBrain().ideas[0]<< std::endl;
	std::cout << "====Destructors====" << std::endl;
	return 0;
}


