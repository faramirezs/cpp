/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:42:46 by alejandrora       #+#    #+#             */
/*   Updated: 2025/07/08 09:15:31 by alramire         ###   ########.fr       */
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
	return 0;
}


