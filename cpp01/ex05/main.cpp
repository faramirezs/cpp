/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 10:24:45 by alramire          #+#    #+#             */
/*   Updated: 2025/07/05 10:58:42 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string>
# include <iostream>
# include <limits>
# include <iomanip>
# include <stdlib.h>
# include <stdio.h>
# include <cctype>
# include "Harl.hpp"

int main()
{
    Harl myHarl;
    myHarl.complain("debug");
    myHarl.complain("info");
    myHarl.complain("warning");
    myHarl.complain("error");
    myHarl.complain("");

    return 0;
}