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

/*
 * PmergeMe implements the Ford-Johnson merge-insertion sort algorithm.
 *
 * The idea is to minimize the number of comparisons by:
 * 1. Pairing elements and sorting each pair internally.
 * 2. Recursively sorting the "main chain" (the larger element of each pair).
 * 3. Inserting the "pending" elements (the smaller elements) back into the
 *    sorted main chain in an optimal order dictated by Jacobsthal numbers.
 * 4. Using binary search (std::lower_bound) for every insertion.
 *
 * The subject requires two different containers. We provide explicit,
 * non-templated overloads for std::vector and std::deque.
 */
class PmergeMe
{
private:
	// Original input sequence, stored as a vector for parsing convenience.
	std::vector<int> victor;

public:
	PmergeMe();
	PmergeMe(char**av);
	PmergeMe(const PmergeMe &other);
	PmergeMe& operator=(const PmergeMe &other);
	~PmergeMe();

	void printInput();

	/* ---------- std::vector overloads ---------- */

	// Step 1: Pair adjacent elements. Within each pair, the smaller value
	// comes first (first) and the larger second (second).
	std::vector<std::pair<int,int> > makePend(const std::vector<int>& v);

	// Step 5: Insert pending elements into the sorted main chain.
	// Uses Jacobsthal sequence to determine optimal insertion order.
	void insertPend(std::vector<int>& newMain,
				std::vector<std::pair<int,int> > pend, int newStrang);

	// Extract the larger element (pair.second) from every pair into a new
	// sequence — this becomes the main chain for the next recursion level.
	std::vector<int> makeMain(std::vector<std::pair<int,int> > pend);

	// If the input has an odd number of elements, the last unpaired element
	// is the "strangler". Returns -1 if the count is even.
	int makeStrang(std::vector<int> v);

	// Jacobsthal sequence: J(n) = J(n-1) + 2*J(n-2).
	// Used to determine batch sizes when inserting pending elements.
	// The sequence begins 1, 3, 5, 11, 21, 43...
	std::vector<int> createJack(size_t n);

	// The core recursive sort. Recursively sorts the main chain,
	// then inserts the pending elements back using insertPend.
	void fordJohnson(std::vector<int>&mainChain,
				std::vector<std::pair<int,int> > pend, int strangler, int count);

	/* ---------- std::deque overloads ---------- */

	// Same algorithm steps as above, but operating on std::deque.
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
