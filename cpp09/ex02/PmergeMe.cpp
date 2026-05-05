#include "PmergeMe.hpp"
#include "test.hpp"
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

// TEST FUNCTION //
int PmergeMe::fordJohnsonTheoretical(int n) {
    int total = 0;
    int chainSize = 1; // mainChain empieza con 1 elemento
    for (int i = 1; i < n; ++i) {
        // costo de insertar en chainSize elementos
        int bits = 0;
        int tmp = chainSize;
        while (tmp > 0) { bits++; tmp >>= 1; }
        total += bits;
        chainSize++;
    }
    return total;
}

void PmergeMe::printInput() {
    std::cout << "\nvictor is: ";
    for (size_t i = 0; i < victor.size(); ++i) {
        std::cout << victor[i];
        if (i < victor.size() - 1) std::cout << " ";
    }
}

std::vector<std::pair<int,int> > PmergeMe::makePend(const std::vector<int>& v, CountingLess<int>& cmp) {//TEST
    std::vector<std::pair<int,int> > pend;
    for (std::vector<int>::const_iterator it = v.begin();
        it + 1 < v.end(); it += 2) {
            int a = *it;
            int b = *(it + 1);

            // pend.push_back(std::make_pair(
                // std::min(*it, *(it+1)), std::max(*it, *(it+1))));//guarantee order in each pair -> compara 1 de mas
                // std::min(*it, *(it+1)), std::max(*it, *(it+1), cmp)));//TEST
                // *it, *(it+1)));//TEST -> no cumple con el algoritmo

            if (cmp(a, b))//one comparison
                pend.push_back(std::make_pair(a, b));
            else
                pend.push_back(std::make_pair(b, a));
    }
    return pend;
}

void PmergeMe::insertPend(std::vector<int>& newMain,
                std::vector<std::pair<int,int> > pend, int newStrang, CountingLess<int>& cmp) {//TEST: ountingLess<int> cmp
    // insert pend[0] is free
    int va = pend[0].first;
    // std::vector<int>::iterator itt = std::lower_bound(newMain.begin(), newMain.end(), va);
    std::vector<int>::iterator itt = std::lower_bound(newMain.begin(), newMain.end(), va, cmp);//TEST
    newMain.insert(itt, va);

    //if there is strangler put it
    if (newStrang != -1) {
        // std::vector<int>::iterator it = std::lower_bound(newMain.begin(), newMain.end(), newStrang);
        std::vector<int>::iterator it = std::lower_bound(newMain.begin(), newMain.end(), newStrang, cmp);//TEST
        newMain.insert(it, newStrang);
    }

    //create jackobsthal
    std::vector<int> jack = createJack(pend.size() + 1);

    /*     LOOP TO INSERT WITH JACKOBSTHAL
        1. Loop in jack
            start in 1
        2. Loop in pend & insert
            Loop in pend should start in pen[1] (can be start)
    */
    for (size_t j = 1; j < jack.size(); ++j) {//size_t = 1 because before was inserted pend[0]
        size_t start = jack[j] - 1;//j = 1 because
        // pend[0] was inserted
        size_t end = jack[j - 1] - 1;
        if (start >= pend.size())//to avoid jack going beyond pend size
            start = pend.size() - 1;

        // testJackRange(start, end, j, pend);//TEST

        for (size_t i = start; i > end && i < pend.size(); --i) {//end is the last insertion considering jack
                // testCurrentPendInsert(pend, i);//TEST
                int val = pend[i].first;
                std::vector<int>::iterator it = std::lower_bound(newMain.begin(),
                    // newMain.end(), val);//-1 to start in pend[0]
                    newMain.end(), val, cmp);//TEST
                newMain.insert(it, val);
            }
    }
    // testJack(jack, count);//TEST
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
            jack.push_back(jack[jack.size()-1] + 2 * jack[jack.size()-2]);//jack.size()-1 is = to jack.back()
        return jack;
}

void    PmergeMe::fordJohnson(std::vector<int>&mainChain, std::vector<std::pair<int,int> > pend, int strangler, int count, CountingLess<int>& cmp) {//TEST
    // 4. recursion part 1. to organize "main chains" from cupido + create pends with pairs
    // if (mainChain.size() <= 1){ //base case to stop recursion
    (void)strangler;
    if (pend.size() <= 1) { //check this option
        if (!pend.empty()) {
            // std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[0].first);
            std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[0].first, cmp);//TEST
            mainChain.insert(it, pend[0].first);
        }
        return;
    }
    // std::vector<std::pair<int,int> > newPend = makePend(mainChain);
    std::vector<std::pair<int,int> > newPend = makePend(mainChain, cmp);//TEST

    testPend(newPend, count);//test

    std::vector<int> newMain = makeMain(newPend);
    int newStrang = makeStrang(mainChain);

    // fordJohnson(newMain, newPend, newStrang, count + 1);
    fordJohnson(newMain, newPend, newStrang, count + 1, cmp);//TEST

    testMainCinRonud(mainChain, count);//TEST per round

    // 5. recursion part 2. include pend insertion with Jackobshal number (include stranglers)
    // insertPend(newMain, pend, newStrang, count);//count just for testing
    insertPend(newMain, pend, newStrang, cmp);//TEST

    //update mainchain with the result
    mainChain = newMain;

    testMainCinRonud(newMain, count);//TEST
}
