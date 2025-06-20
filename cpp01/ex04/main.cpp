/* # include "Weapon.hpp"
# include "HumanA.hpp"
# include "HumanB.hpp" */

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


/* 
t must open the file <filename> and copy its content into a new file
<filename>.replace, replacing every occurrence of s1 with s2. 
*/

/* 
What I have:
1. file name
2. target str s1
3. new str s2

How:
1. Read file (or line?)
- store read in buf
- handle empty
- wrong file
2. look for s1 in buf
3. Replace s1 with s2 in buf
4. Create new file
5. Write buf into new filen
6. Iterate until there is nothing else to read on file.

What I want:
1. a new file
2. Every s1 str is replace by s2 str. 

*/

int main(int ac, char **av)
{
    //ssize_t n;
    //char buf[1024];
    //int fd;

    if(ac != 4)
        return 1;
    std::string s0 = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    //if((fd = open(av[0], O_RDONLY) == -1))
    //    return 1;

    std::ifstream file(av[1]);
    if(!file)
        return 1;
    if(file.is_open())
        std::cout << "File open\n"; 
    else
        std::cout << "File not open\n";

    std::string line;
    std::string tmp;
    size_t pos;
    while(std::getline(file, line))
    {
        //std::cout << "Untoched line: " << line << "\n";
        pos = line.find(av[2]);
        while(pos != std::string::npos)
        {
            line.erase(pos, s1.length());
            //std::cout << "s1 found and erased from line: " << line << "\n";
            line.insert(pos, av[3]);
            //std::cout << "s2 inserted on line: " << line << "\n";
            pos = line.find(av[2]);
        }
        tmp.append(line);
        std::cout << "From line to tmp: " << tmp << "\n";
    }

    //std::cout << "Count: " << ac << ". String0: " << s0 << "\n";
    //std::cout << "Count: " << ac << ". String1: " << s1 << "\n";
    //std::cout << "Count: " << ac << ". String2: " << s2 << "\n";

    return 0;
}