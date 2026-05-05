#include "PmergeMe.hpp"
#include "test.hpp"
#include <algorithm>
#include <climits>

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(char** av){
	for (int j = 1; av[j]; j++) {
		std::istringstream iss(av[j]);
		long n;
		if (!(iss >> n) || n <= 0 || n > INT_MAX) {
			throw std::runtime_error("Error");
		}
		char c;
		if (iss >> c) {
			throw std::runtime_error("Error");
		}
		victor.push_back(static_cast<int>(n));
	}
}

PmergeMe::PmergeMe(const PmergeMe &other) {
	mainChain = other.mainChain;
	dictor = other.dictor;
	pend = other.pend;
	victor = other.victor;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other){
	if (this == &other)
    	return *this;
	mainChain = other.mainChain;
	dictor = other.dictor;
	pend = other.pend;
	victor = other.victor;
	return *this;
}

PmergeMe::~PmergeMe() {}

size_t PmergeMe::getVictorSize(){
	return victor.size();
}

int PmergeMe::getVictorValue(int index){
	return victor[index];
}

std::vector<int>& PmergeMe::getVictor(){
    return victor;
}

void PmergeMe::printInput() {
    std::cout << "\nvictor is: ";
    for (size_t i = 0; i < victor.size(); ++i) {
        std::cout << victor[i];
        if (i < victor.size() - 1) std::cout << " ";
    }
}

std::vector<std::pair<int,int> > PmergeMe::makePend(const std::vector<int>& v, CountingLess<int>& cmp) {
    std::vector<std::pair<int,int> > pend;
    for (std::vector<int>::const_iterator it = v.begin();
        it + 1 < v.end(); it += 2) {
            int a = *it;
            int b = *(it + 1);
            if (cmp(a, b))
                pend.push_back(std::make_pair(a, b));
            else
                pend.push_back(std::make_pair(b, a));
    }
    return pend;
}

void PmergeMe::insertPend(std::vector<int>& newMain,
                std::vector<std::pair<int,int> > pend, int newStrang, CountingLess<int>& cmp) {
    int va = pend[0].first;
    std::vector<int>::iterator itt = std::lower_bound(newMain.begin(), newMain.end(), va, cmp);
    newMain.insert(itt, va);

    if (newStrang != -1) {
        std::vector<int>::iterator it = std::lower_bound(newMain.begin(), newMain.end(), newStrang, cmp);
        newMain.insert(it, newStrang);
    }

    std::vector<int> jack = createJack(pend.size() + 1);

    for (size_t j = 1; j < jack.size(); ++j) {
        size_t start = jack[j] - 1;
        size_t end = jack[j - 1] - 1;
        if (start >= pend.size())
            start = pend.size() - 1;

        for (size_t i = start; i > end && i < pend.size(); --i) {
                int val = pend[i].first;
                std::vector<int>::iterator it = std::lower_bound(newMain.begin(),
                    newMain.end(), val, cmp);
                newMain.insert(it, val);
            }
    }
}

std::vector<int> PmergeMe::makeMain(std::vector<std::pair<int,int> > pend) {
    std::vector<int> mainChain;
    for (size_t i = 0; i < pend.size(); i++)
        mainChain.push_back(pend[i].second);
    return mainChain;
}

int PmergeMe::makeStrang(std::vector<int> v) {
    if (v.size() % 2 == 1)
        return v.back();
    return -1;
}

std::vector<int> PmergeMe::createJack(size_t n) {
        std::vector<int> jack;
        jack.push_back(1);
        jack.push_back(3);
        while (jack.back() <= static_cast<int>(n))
            jack.push_back(jack[jack.size()-1] + 2 * jack[jack.size()-2]);
        return jack;
}

void	PmergeMe::fordJohnson(std::vector<int>&mainChain, std::vector<std::pair<int,int> > pend, int strangler, int count, CountingLess<int>& cmp) {
    (void)strangler;
    if (pend.size() <= 1) {
        if (!pend.empty()) {
            std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[0].first, cmp);
            mainChain.insert(it, pend[0].first);
        }
        return;
    }
    std::vector<std::pair<int,int> > newPend = makePend(mainChain, cmp);

    testPend(newPend, count);

    std::vector<int> newMain = makeMain(newPend);
    int newStrang = makeStrang(mainChain);

    fordJohnson(newMain, newPend, newStrang, count + 1, cmp);

    testMainCinRonud(mainChain, count);

    insertPend(newMain, pend, newStrang, cmp);

    mainChain = newMain;

    testMainCinRonud(newMain, count);
}
