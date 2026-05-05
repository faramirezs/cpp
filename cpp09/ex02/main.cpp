#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
#include <sys/time.h>

static void printTime(size_t n, const std::string& container,
                      struct timeval& start, struct timeval& end) {
    double elapsed = (end.tv_sec - start.tv_sec) * 1e6
                   + (end.tv_usec - start.tv_usec);
    std::cout << "Time to process a range of " << n
              << " elements with " << container
              << " : " << elapsed << " us" << std::endl;
}

int main(int argc, char **av) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    try {
        PmergeMe p(av);
        size_t n = p.getVictorSize();

        std::cout << "Before: ";
        for (size_t i = 0; i < n; ++i) {
            std::cout << p.getVictorValue(i);
            if (i + 1 < n) std::cout << " ";
        }
        std::cout << std::endl;

        if (n == 1) {
            std::cout << "After: " << p.getVictorValue(0) << std::endl;
            return 0;
        }

        // --- std::vector sort ---
        struct timeval start_v, end_v;
        gettimeofday(&start_v, NULL);

        std::vector<std::pair<int,int> > cupido = p.makePend(p.getVictor());
        int strangler = p.makeStrang(p.getVictor());
        std::vector<int> mainChain = p.makeMain(cupido);
        p.fordJohnson(mainChain, cupido, strangler, 0);
        if (strangler != -1) {
            std::vector<int>::iterator it = std::lower_bound(
                mainChain.begin(), mainChain.end(), strangler);
            mainChain.insert(it, strangler);
        }

        gettimeofday(&end_v, NULL);

        // --- std::deque sort ---
        struct timeval start_d, end_d;
        gettimeofday(&start_d, NULL);

        std::deque<int> dequeVictor(p.getVictor().begin(), p.getVictor().end());
        std::deque<std::pair<int,int> > cupidoDeque = p.makePendDeque(dequeVictor);
        int stranglerDeque = p.makeStrangDeque(dequeVictor);
        std::deque<int> mainChainDeque = p.makeMainDeque(cupidoDeque);
        p.fordJohnsonDeque(mainChainDeque, cupidoDeque, stranglerDeque, 0);
        if (stranglerDeque != -1) {
            std::deque<int>::iterator it = std::lower_bound(
                mainChainDeque.begin(), mainChainDeque.end(), stranglerDeque);
            mainChainDeque.insert(it, stranglerDeque);
        }

        gettimeofday(&end_d, NULL);

        std::cout << "After: ";
        for (size_t i = 0; i < mainChain.size(); ++i) {
            std::cout << mainChain[i];
            if (i + 1 < mainChain.size()) std::cout << " ";
        }
        std::cout << std::endl;

        printTime(n, "std::vector", start_v, end_v);
        printTime(n, "std::deque", start_d, end_d);

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
