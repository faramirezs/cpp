/*
 * PmergeMe — Ford-Johnson Merge-Insertion Sort
 *
 * This program sorts a sequence of positive integers using the
 * Ford-Johnson algorithm on two different STL containers:
 * std::vector and std::deque.
 *
 * The Ford-Johnson algorithm is a comparison-optimal sorting method.
 * It works by pairing elements, recursively sorting the larger half,
 * then inserting the smaller half back in an order dictated by the
 * Jacobsthal sequence.
 */

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

        // Display the unsorted input sequence
        std::cout << "Before: ";
        for (size_t i = 0; i < n; ++i) {
            std::cout << p.getVictorValue(i);
            if (i + 1 < n) std::cout << " ";
        }
        std::cout << std::endl;

        // Trivial case: a single element is already sorted
        if (n == 1) {
            std::cout << "After: " << p.getVictorValue(0) << std::endl;
            return 0;
        }

        /* ---------- std::vector sort ---------- */
        struct timeval start_v, end_v;
        gettimeofday(&start_v, NULL);

        // 1. Pair adjacent elements, sorting each pair internally.
        std::vector<std::pair<int,int> > cupido = p.makePend(p.getVictor());

        // 2. Detect the unpaired "strangler" if the count is odd.
        int strangler = p.makeStrang(p.getVictor());

        // 3. Build the main chain from the larger elements of each pair.
        std::vector<int> mainChain = p.makeMain(cupido);

        // 4. Recursively sort the main chain, then insert pending elements.
        p.fordJohnson(mainChain, cupido, strangler, 0);

        // 5. Insert the strangler back into the fully sorted chain.
        if (strangler != -1) {
            std::vector<int>::iterator it = std::lower_bound(
                mainChain.begin(), mainChain.end(), strangler);
            mainChain.insert(it, strangler);
        }

        gettimeofday(&end_v, NULL);

        /* ---------- std::deque sort ---------- */
        struct timeval start_d, end_d;
        gettimeofday(&start_d, NULL);

        // Copy the input into a deque and run the same algorithm.
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

        // Display the sorted sequence (vector result; both are identical)
        std::cout << "After: ";
        for (size_t i = 0; i < mainChain.size(); ++i) {
            std::cout << mainChain[i];
            if (i + 1 < mainChain.size()) std::cout << " ";
        }
        std::cout << std::endl;

        // Display timing for both containers
        printTime(n, "std::vector", start_v, end_v);
        printTime(n, "std::deque", start_d, end_d);

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
