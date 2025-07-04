/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:37:49 by alramire          #+#    #+#             */
/*   Updated: 2025/07/04 14:39:40 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string>
# include <iostream>
# include <limits>
# include <iomanip>

class contact
{
    private:
        int id;
        std::string fname;
        std::string lname;
        std::string secret;
        std::string nname;
        std::string phone;
    public:
    contact (std::string fnm, std::string lnm, std::string scrt, int ide, std::string nnm, std::string phn){
        id = ide;
        fname = fnm;
        lname = lnm;
        secret = scrt;
        nname = nnm;
        phone = phn;
    }
    contact(){
        id = 0;
        phone = "";
        fname = "";
        lname = "";
        secret = "";
        nname = "";
    }
    int getID() { return id; }
    void updateID(int i) { id = i; }
    std::string getFname() { return fname; }
    std::string getLname() { return lname; }
    std::string getPhone() { return phone; }
    std::string getNname() { return nname; }
    void displayContact() 
    { 
        std::cout << "\n";
        std::cout << "First name: " << fname << "\n" 
            << "Last name: " << lname << "\n" 
            << "Phone: " << phone << "\n" 
            << "Nickname: " << nname << "\n"
            << "Darkest secret: " << secret << "\n";
        std::cout << "\n";
    }
};

class phonebook
{
    private:
        contact contacts[8];
    public:
        void memory_full (contact *array)
        {
            int i;

            i = 0;
            while(i < 7)
            {
                array[i] = array[i + 1];
                array[i].updateID(i);
                i++;
            }
            array[7] = contact();
        };
        void addContact(int *id)
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
            contacts[*id] = contact(fname, lname, secret, *id, nname, phone);
            (*id)++;
            std::cout << "Contacts: " << *id << "\n";
        };
        void searchContact(int *id)
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
            //std::cout << "--------------------------------------------\n";
            std::cout << "|" << std::left << std::setw(10) << "index" << "|" 
                << std::setw(10) << "first name" << "|" 
                << std::setw(10) << "last name" << "|" 
                << std::setw(10) << "nickname" << "|" << std::endl;
            //std::cout << "|" << "index" << std::setw(10) << "|" << "first name" << std::setw(10) << "|" << "last name" << std::setw(10) << "|" << "nickname" << std::setw(10) << "|\n";
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
            //std::cout << "--------------------------------------------\n";
            std::cout << "\n";
            std::cout << "Enter the index of the contact you want to see: ";
            if (!(std::cin >> command)) {
                // Input was not a valid integer
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a numeric index.\n";
                searchContact(id);
                return; // Or handle the error differently
            }
            //std::cin >> command;
            if (command >= 0 && command < *id)
                contacts[command].displayContact();
            else
            {
                std::cout << "Invalid index. Please enter a valid index from the table below.\n";
                searchContact(id);
            }
        }
};



int main()
{
    int count;
    std::string command;
    phonebook pnb;

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
    /* contact contactObj1("Alejo","Ram","NA",1,"alejiri",123456);
    std::cout << contactObj1.getID() << " " << contactObj1.getFname() << " " << contactObj1.getLname() << "\n";
    contactObj1.displayContact(); */
    return (0);
}