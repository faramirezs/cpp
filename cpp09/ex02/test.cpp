#include "test.hpp"

void testComparison(std::vector<int> mainChain, std::vector<int> victor) {
    std::vector<int> sorted = victor;
    std::sort(sorted.begin(), sorted.end());
    if (sorted == mainChain)
        std::cout << RESULT << "CORRECT" << RESET << std::endl;
    else
        std::cout << RED << "WRONG" << RESET << std::endl;
}

void testCupido(std::vector<std::pair<int,int> >cupido) {
    std::cout << "cupido: ";
    for (int i = 0; i < cupido.size(); ++i) {
        std::cout << "(" << cupido[i].first << "," << cupido[i].second << ")";
        if (i + 1 < cupido.size()) {
        std::cout << " ";
        }
    }
}

void testPend(std::vector<std::pair<int,int> > newPend, int count) {
    std::cout << PEND << "\nround " << count << " newPend: " << RESET;
    for (size_t i = 0; i < newPend.size(); ++i) {
        std::cout << "(" << newPend[i].first << "," << newPend[i].second << ")";
        if (i + 1 < newPend.size()) std::cout << " ";
    }
    std::cout << std::endl;
}

void testStrangler(int strangler) {
    std::cout << "\nstrangler: ";
    if (strangler == -1) std::cout << "none";
    else std::cout << strangler;
    std::cout << std::endl;
}

void testCurrentPendInsert(std::vector<std::pair<int,int> > pend, int i) {
    std::cout << "inserting pend[" << i << "].first=" << pend[i].first << std::endl;
}

void testJack(std::vector<int> jack, int count){
    std::cout << JACK << "Jackobsthal" << count << ": " << RESET;
    for (int i = 0; i < jack.size(); ++i){
        std::cout << jack[i] << " ";
    }
    std::cout << std::endl;
}

void testJackRange(int start, int end, int j, std::vector<std::pair<int,int> > pend) {
    std::cout << "j=" << j << " start=" << start << " end=" << end << " pend.size()=" << pend.size() << std::endl;//TEST
}

void testMainCinRonud(std::vector<int> mainChain, int count) {
    std::cout << BOLD << "\nround " << count << " mainChain: " << RESET;
    for (int i = 0; i <mainChain.size(); ++i) {
        std::cout << mainChain[i];
    if (i + 1 < static_cast<int>(mainChain.size())) std::cout << " ";
    } std::cout << std::endl;
    std::cout << std::endl;
}
