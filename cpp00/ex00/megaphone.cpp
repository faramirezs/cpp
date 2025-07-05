/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:36:38 by alramire          #+#    #+#             */
/*   Updated: 2025/07/05 15:41:00 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    size_t i;

    for (i = 1; av[i]; i++)
    {
        for (size_t j = 0; av[i][j]; j++)
        {
            av[i][j] = toupper(av[i][j]);
        }
    }
    if (ac == 1)
        std::cout <<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<< std::endl;
    for (i = 1; av[i]; i++)
    {
        std::cout << av[i];
    }
    return 0;
}