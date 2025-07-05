/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 10:24:16 by alramire          #+#    #+#             */
/*   Updated: 2025/07/05 10:59:29 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

Harl::Harl()
{
    std::cout << "Created." << "\n";
}

Harl::~Harl()
{
    std::cout <<"Destroyed." << "\n";
}

void Harl::complain( std::string level )
{
    std::string *ptr = NULL;
    size_t i = -1;

    hptr ptr_mem[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string lev[] = {"debug", "info", "warning", "error"};
    ptr = std::find(lev, lev+4, level);
    if (ptr == lev+4)
    {
        std::cout << "Wrong input. Use only: 'debug', 'info', 'warning' or 'error'. "<< '\n';
        return;
    }
    i = ptr - lev;
    CALL_MEMBER_FN(*this, ptr_mem[i])();
};