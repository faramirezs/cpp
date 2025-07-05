/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 10:11:59 by alramire          #+#    #+#             */
/*   Updated: 2025/07/05 10:23:13 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string>
# include <iostream>
# include <limits>
# include <iomanip>
# include <stdlib.h>
# include <stdio.h>
# include <cctype>
# include <sys/stat.h>
# include <fcntl.h>
# include <fstream>

int main(int ac, char **av)
{
   if(ac != 4)
   {
    std::cout << "Error. Use ./sed <filename> <s1> <s2>" << std::endl;
    return 1;
   }
    std::string s0 = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    std::ifstream file(av[1]);
    if(!file)
    {
        std::cout << "Error: file." << std::endl;
        return 1;
    }
    std::ofstream outfile(s0.append(".replace").c_str());
    if(!outfile)
    {
        std::cout << "Error: file." << std::endl;
        return 1;
    }
    if(!file.is_open() || !outfile.is_open())
    {
        std::cout << "Error: open file." << std::endl;
        return 1;
    }
    std::string line;
    std::string tmp;
    size_t pos;
    while(std::getline(file, line))
    {
        pos = line.find(av[2]);
        while(pos != std::string::npos)
        {
            line.erase(pos, s1.length());
            line.insert(pos, av[3]);
            pos = line.find(av[2]);
        }
        tmp.append(line);
        outfile << tmp << "\n"; 
        tmp.clear();
    }
    std::cout << "Success." << std::endl;
    return 0;
}