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
        return 1;
    std::string s0 = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    std::ifstream file(av[1]);
    std::ofstream outfile(s0.append(".replace").c_str());
    if(!file || !outfile)
        return 1;
    if(!file.is_open() || !outfile.is_open())
        return 1;
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

    return 0;
}