#ifndef PMERGEME_HPP
# define PMERGEME_HPP
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <deque>
#include <vector>
#include <utility>
#include <sys/time.h>

class PmergeMe
{
private:
	std::vector<int> mainChain;
	std::vector<std::pair<int,int> > pend;
	std::vector<int> victor;
public:
	PmergeMe();
	PmergeMe(char**av);
	PmergeMe(const PmergeMe &other);
	PmergeMe& operator=(const PmergeMe &other);
	~PmergeMe();

	void printInput();

	// std::vector implementations
	std::vector<std::pair<int,int> > makePend(const std::vector<int>& v);
	void insertPend(std::vector<int>& newMain,
				std::vector<std::pair<int,int> > pend, int newStrang);
	std::vector<int> makeMain(std::vector<std::pair<int,int> > pend);
	int makeStrang(std::vector<int> v);
	std::vector<int> createJack(size_t n);
	void fordJohnson(std::vector<int>&mainChain,
				std::vector<std::pair<int,int> > pend, int strangler, int count);

	// std::deque implementations
	std::deque<std::pair<int,int> > makePendDeque(const std::deque<int>& v);
	void insertPendDeque(std::deque<int>& newMain,
				std::deque<std::pair<int,int> > pend, int newStrang);
	std::deque<int> makeMainDeque(std::deque<std::pair<int,int> > pend);
	int makeStrangDeque(std::deque<int> v);
	void fordJohnsonDeque(std::deque<int>&mainChain,
				std::deque<std::pair<int,int> > pend, int strangler, int count);

	size_t getVictorSize();
	int getVictorValue(int index);
	std::vector<int>& getVictor();
};

#endif
