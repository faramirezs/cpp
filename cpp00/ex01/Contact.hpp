/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 09:21:20 by alramire          #+#    #+#             */
/*   Updated: 2025/07/07 13:35:14 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONTACT_H__
#define __CONTACT_H__

# include <string>
# include <iostream>
# include <limits>
# include <iomanip>
# include <stdlib.h>
# include <stdio.h>
# include <cctype>

class Contact
{
    private:
        int id;
        std::string fname;
        std::string lname;
        std::string secret;
        std::string nname;
        std::string phone;
        
    public:
        Contact(std::string fnm, std::string lnm, std::string scrt, int ide, std::string nnm, std::string phn);
        Contact();
        ~Contact();
        int getID();
        void updateID(int i);
        std::string getFname();
        std::string getLname();
        std::string getPhone();
        std::string getNname();
        void displayContact();
};

#endif