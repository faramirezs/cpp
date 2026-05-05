#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <deque>
#include <vector>
#include <utility>
#include <sys/time.h>
#include "Count.hpp"

class PmergeMe
{
private:
	std::vector<int> mainChain;
	std::deque<int> dictor;
	std::vector<std::pair<int,int> > pend;
	std::vector<int> victor;
public:
	PmergeMe();
	PmergeMe(char**av);
	PmergeMe(const PmergeMe &other);
	PmergeMe& operator=(const PmergeMe &other);
	~PmergeMe();

	void printInput();

	// Eval versions (no comparison counting)
	std::vector<std::pair<int,int> > makePend(const std::vector<int>& v);
	void insertPend(std::vector<int>& newMain,
				std::vector<std::pair<int,int> > pend, int newStrang);
	std::vector<int> makeMain(std::vector<std::pair<int,int> > pend);
	int makeStrang(std::vector<int> v);
	std::vector<int> createJack(size_t n);
	void fordJohnson(std::vector<int>&mainChain, std::vector<std::pair<int,int> > pend, int strangler, int count);

	// Test versions (with CountingLess)
	std::vector<std::pair<int,int> > makePend(const std::vector<int>& v, CountingLess<int>& cmp);
	void insertPend(std::vector<int>& newMain,
				std::vector<std::pair<int,int> > pend, int newStrang, CountingLess<int>& cmp);
	void fordJohnson(std::vector<int>&mainChain, std::vector<std::pair<int,int> > pend, int strangler, int count, CountingLess<int>& cmp);

	size_t getVictorSize();
	int getVictorValue(int index);
	std::vector<int>& getVictor();
};
