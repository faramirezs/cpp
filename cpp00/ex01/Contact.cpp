/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:37:49 by alramire          #+#    #+#             */
/*   Updated: 2025/07/07 13:40:17 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Contact.hpp"

Contact::Contact (std::string fnm, std::string lnm, std::string scrt, int ide, std::string nnm, std::string phn)
    :id(ide), fname(fnm), lname(lnm), secret(scrt), nname(nnm), phone(phn)   
{

}

Contact::Contact()
    :id(0), fname(""), lname(""), secret(""), nname(""), phone("")
{

}

Contact::~Contact() {}

int Contact::getID() { return id; }

void Contact::updateID(int i) { id = i; }

std::string Contact::getFname() { return fname; }
std::string Contact::getLname() { return lname; }
std::string Contact::getPhone() { return phone; }
std::string Contact::getNname() { return nname; }

void Contact::displayContact() 
{ 
    std::cout << "\n";
    std::cout << "First name: " << fname << "\n" 
        << "Last name: " << lname << "\n" 
        << "Phone: " << phone << "\n" 
        << "Nickname: " << nname << "\n"
        << "Darkest secret: " << secret << "\n";
    std::cout << "\n";
}