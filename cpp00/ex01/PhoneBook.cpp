/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:37:49 by alramire          #+#    #+#             */
/*   Updated: 2025/07/07 13:32:20 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

void PhoneBook::memory_full (Contact *array)
{
    int i;

    i = 0;
    while(i < 7)
    {
        array[i] = array[i + 1];
        array[i].updateID(i);
        i++;
    }
    array[7] = Contact();
}
        
void PhoneBook::addContact(int *id)
{
    std::string fname;
    std::string lname;
    std::string secret;
    std::string nname;
    std::string phone;

    if (*id == 8)
    {
        std::cout << "Memory full! ovewritting oldest contact...\n";
        memory_full(contacts);
        (*id)--;
        std::cout << "Contacts: " << *id << "\n";
    }
    std::cout << "Enter first name: ";
    std::cin >> fname;
    std::cout << "Enter last name: ";
    std::cin >> lname;
    std::cout << "Enter darkest secret: ";
    std::cin >> secret;
    std::cout << "Enter nickname: ";
    std::cin >> nname;
    std::cout << "Enter phone: ";
    std::cin >> phone;
    contacts[*id] = Contact(fname, lname, secret, *id, nname, phone);
    (*id)++;
    std::cout << "Contacts: " << *id << "\n";
}

void PhoneBook::searchContact(int *id)
{
    int i;
    std::string fname;
    std::string lname;
    std::string nname;
    int command;

    i = 0;
    if (*id == 0)
    {
        std::cout << "Empty phoneBook" << std::endl;
        return;
    }
    std::cout << "\n";
    std::cout << "|" << std::left << std::setw(10) << "index" << "|" 
        << std::setw(10) << "first name" << "|" 
        << std::setw(10) << "last name" << "|" 
        << std::setw(10) << "nickname" << "|" << std::endl;
    std::cout << "|----------|----------|----------|----------|\n";
    while(i < *id)
    {
        fname = contacts[i].getFname();
        if (fname.length() > 9)
            fname = fname.substr(0, 9) + ".";
        lname = contacts[i].getLname();
        if (lname.length() > 9)
            lname = lname.substr(0, 9) + ".";
        nname = contacts[i].getNname();
        if (nname.length() > 9)
            nname = nname.substr(0, 9) + ".";
        std::cout << "|" << std::left 
            << std::setw(10) << contacts[i].getID() << "|" 
            << std::setw(10) << fname << "|" 
            << std::setw(10) << lname << "|" 
            << std::setw(10) << nname << "|" << std::endl;
        i++;
        }
    std::cout << "\n";
    std::cout << "Enter the index of the contact you want to see: ";
    if (!(std::cin >> command)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a numeric index.\n";
        searchContact(id);
        return;
    }
    if (command >= 0 && command < *id)
        contacts[command].displayContact();
    else
    {
        std::cout << "Invalid index. Please enter a valid index from the table below.\n";
        searchContact(id);
    }
}
