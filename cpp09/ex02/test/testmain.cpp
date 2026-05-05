#include "PmergeMe.hpp"
#include "colors.hpp"
#include "test.hpp"
#include "Count.hpp"
#include <iostream>
#include <algorithm>
#include <string>
#include <sys/time.h>

struct timeval start, end;

// Theoretical comparison count for the Ford-Johnson algorithm
int fordJohnsonTheoretical(int n) {
    int total = 0;
    int chainSize = 1;
    for (int i = 1; i < n; ++i) {
        int bits = 0;
        int tmp = chainSize;
        while (tmp > 0) { bits++; tmp >>= 1; }
        total += bits;
        chainSize++;
    }
    return total;
}

void printResult(std::vector<int> mainChain) {
    std::cout << BOLD << RESULT << "\nfinal mainChain: " << RESET;
    for (size_t i = 0; i < mainChain.size(); ++i) {
        std::cout << mainChain[i];
        if (i + 1 < mainChain.size()) std::cout << " ";
    } std::cout << std::endl;
}

void printTime(size_t n, std::string container) {
    double elapsed = (end.tv_sec - start.tv_sec) * 1e6
                   + (end.tv_usec - start.tv_usec);
    std::cout << "Time to process a range of " << n
              << " elements with " << container
              << " : " << elapsed << " us" << std::endl;
}

void printCompare(const CountingLess<int>& cmp) {
    std::cout << BOLD << "Total comparisons: " << RESET << cmp.getCount() << std::endl;
}

int main(int argc, char **av) {
    if (argc < 2) {
        std::cerr << RED << "write one or more <int>" << RESET << std::endl;
        return 1;
    }

    try {
        PmergeMe p(av);

        p.printInput();
        std::cout << std::endl;

        gettimeofday(&start, NULL);

        if (p.getVictorSize() == 1) {
            std::cout << "Final main: " << p.getVictorValue(0) << std::endl;
            return 0;
        }

        int comp_count = 0;
        CountingLess<int> cmp(comp_count);
        std::vector<std::pair<int,int> > cupido = p.makePend(p.getVictor(), cmp);
        int strangler = p.makeStrang(p.getVictor());

        testCupido(cupido);
        testStrangler(strangler);

        std::vector<int> mainChain = p.makeMain(cupido);
        p.fordJohnson(mainChain, cupido, strangler, 0, cmp);

        if (strangler != -1) {
            std::vector<int>::iterator it = std::lower_bound(
                mainChain.begin(), mainChain.end(), strangler, cmp);
            mainChain.insert(it, strangler);
        }

        printResult(mainChain);
        gettimeofday(&end, NULL);

        printTime(p.getVictorSize(), "std::vector");
        printCompare(cmp);
        std::cout << "Total Theoretical: " << fordJohnsonTheoretical(p.getVictorSize()) << std::endl;

        testComparison(mainChain, p.getVictor());
        return 0;

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}
