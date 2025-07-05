/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 11:01:13 by alramire          #+#    #+#             */
/*   Updated: 2025/07/05 11:06:10 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HARL_H__
#define __HARL_H__

# include <string>
# include <iostream>
# include <limits>
# include <iomanip>
# include <stdlib.h>
# include <stdio.h>
# include <cctype>
# include <algorithm>
# define CALL_MEMBER_FN(object,ptrToMember)  ((object).*(ptrToMember))

class Harl
{
    private:
        std::string type;
        typedef void (Harl::*hptr)(void);
        void debug(void) {std::cout << "Debug:  love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << "\n";};
        void info( void ) {std::cout << "info:  cannot believe adding extra bacon costs more money. You didn't put enough acon in my burger! If you did, I wouldn’t be asking for more!" << "\n";};
        void warning( void ) { std::cout << "warning: I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << "\n";};
        void error( void ) { std::cout << "error: This is unacceptable! I want to speak to the manager now." << "\n";};
    
    public:
        void complain( std::string level );
        Harl(void);
        ~Harl(void);
};


#endif