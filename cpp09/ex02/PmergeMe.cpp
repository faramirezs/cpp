#include "PmergeMe.hpp"
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
	pend = other.pend;
	victor = other.victor;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other){
	if (this == &other)
    	return *this;
	mainChain = other.mainChain;
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

// ========== std::vector implementations ==========

std::vector<std::pair<int,int> > PmergeMe::makePend(const std::vector<int>& v) {
    std::vector<std::pair<int,int> > pend;
    for (std::vector<int>::const_iterator it = v.begin();
        it + 1 < v.end(); it += 2) {
            int a = *it;
            int b = *(it + 1);
            if (a < b)
                pend.push_back(std::make_pair(a, b));
            else
                pend.push_back(std::make_pair(b, a));
    }
    return pend;
}

void PmergeMe::insertPend(std::vector<int>& newMain,
                std::vector<std::pair<int,int> > pend, int newStrang) {
    int va = pend[0].first;
    std::vector<int>::iterator itt = std::lower_bound(newMain.begin(), newMain.end(), va);
    newMain.insert(itt, va);

    if (newStrang != -1) {
        std::vector<int>::iterator it = std::lower_bound(newMain.begin(), newMain.end(), newStrang);
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
                    newMain.end(), val);
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

void	PmergeMe::fordJohnson(std::vector<int>&mainChain, std::vector<std::pair<int,int> > pend, int strangler, int count) {
    (void)strangler;
    (void)count;
    if (pend.size() <= 1) {
        if (!pend.empty()) {
            std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[0].first);
            mainChain.insert(it, pend[0].first);
        }
        return;
    }
    std::vector<std::pair<int,int> > newPend = makePend(mainChain);
    std::vector<int> newMain = makeMain(newPend);
    int newStrang = makeStrang(mainChain);

    fordJohnson(newMain, newPend, newStrang, count + 1);
    insertPend(newMain, pend, newStrang);
    mainChain = newMain;
}

// ========== std::deque implementations ==========

std::deque<std::pair<int,int> > PmergeMe::makePendDeque(const std::deque<int>& v) {
    std::deque<std::pair<int,int> > pend;
    for (size_t i = 0; i + 1 < v.size(); i += 2) {
        int a = v[i];
        int b = v[i + 1];
        if (a < b)
            pend.push_back(std::make_pair(a, b));
        else
            pend.push_back(std::make_pair(b, a));
    }
    return pend;
}

void PmergeMe::insertPendDeque(std::deque<int>& newMain,
                std::deque<std::pair<int,int> > pend, int newStrang) {
    int va = pend[0].first;
    std::deque<int>::iterator itt = std::lower_bound(newMain.begin(), newMain.end(), va);
    newMain.insert(itt, va);

    if (newStrang != -1) {
        std::deque<int>::iterator it = std::lower_bound(newMain.begin(), newMain.end(), newStrang);
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
                std::deque<int>::iterator it = std::lower_bound(newMain.begin(),
                    newMain.end(), val);
                newMain.insert(it, val);
            }
    }
}

std::deque<int> PmergeMe::makeMainDeque(std::deque<std::pair<int,int> > pend) {
    std::deque<int> mainChain;
    for (size_t i = 0; i < pend.size(); i++)
        mainChain.push_back(pend[i].second);
    return mainChain;
}

int PmergeMe::makeStrangDeque(std::deque<int> v) {
    if (v.size() % 2 == 1)
        return v.back();
    return -1;
}

void	PmergeMe::fordJohnsonDeque(std::deque<int>&mainChain, std::deque<std::pair<int,int> > pend, int strangler, int count) {
    (void)strangler;
    (void)count;
    if (pend.size() <= 1) {
        if (!pend.empty()) {
            std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[0].first);
            mainChain.insert(it, pend[0].first);
        }
        return;
    }
    std::deque<std::pair<int,int> > newPend = makePendDeque(mainChain);
    std::deque<int> newMain = makeMainDeque(newPend);
    int newStrang = makeStrangDeque(mainChain);

    fordJohnsonDeque(newMain, newPend, newStrang, count + 1);
    insertPendDeque(newMain, pend, newStrang);
    mainChain = newMain;
}
