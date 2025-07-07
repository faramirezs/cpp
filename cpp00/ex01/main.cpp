/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:37:49 by alramire          #+#    #+#             */
/*   Updated: 2025/07/07 13:33:34 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

int main()
{
    int count;
    std::string command;
    PhoneBook pnb;

    count = 0;
    while(true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::cin >> command;
        if(command == "EXIT" || command == "E")
            break;
        else if (command == "ADD" || command == "A")
        {
            pnb.addContact(&count);
        }
        else if (command == "SEARCH" || command == "S" )
        {
            pnb.searchContact(&count);
        }
        else
            std::cout << "Uknown command. Please use ADD, SEARCH or EXIT.\n";
    }    
    return (0);
}