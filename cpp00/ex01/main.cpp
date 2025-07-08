/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:37:49 by alramire          #+#    #+#             */
/*   Updated: 2025/07/08 17:09:49 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

int main()
{
    int count = 0;
    std::string command;
    PhoneBook pnb;

    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!(std::cin >> command)) {
            if (std::cin.eof()) {
                std::cout << "\nInput stream closed. Exiting program.\n";
                break;
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter ADD, SEARCH, or EXIT.\n";
            continue;
        }

        if (command == "EXIT")
            break;
        else if (command == "ADD")
            pnb.addContact(&count);
        else if (command == "SEARCH")
            pnb.searchContact(&count);
        else
            std::cout << "Unknown command. Please use ADD, SEARCH or EXIT.\n";
    }

    return 0;
}
