#include "PmergeMe.hpp"
#include <algorithm>
#include <climits>

PmergeMe::PmergeMe(){}

/*
 * Constructor: parses and validates all command-line arguments.
 * Every argument must be a strictly positive integer that fits in an int.
 * Non-numeric tokens, partial numbers (e.g. "123abc"), negatives,
 * zero, and overflow are all rejected with "Error".
 */
PmergeMe::PmergeMe(char** av){
	for (int j = 1; av[j]; j++) {
		std::istringstream iss(av[j]);
		long n;
		// Parse the number; reject if extraction fails
		if (!(iss >> n) || n <= 0 || n > INT_MAX) {
			throw std::runtime_error("Error");
		}
		// Reject if there is trailing garbage (e.g. "123abc")
		char c;
		if (iss >> c) {
			throw std::runtime_error("Error");
		}
		victor.push_back(static_cast<int>(n));
	}
}

PmergeMe::PmergeMe(const PmergeMe &other) {
	victor = other.victor;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other){
	if (this == &other)
    	return *this;
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

/* ============================================================
 *                    std::vector implementation
 * ============================================================ */

/*
 * makePend: Step 1 of Ford-Johnson.
 * Walk through the input in pairs. Sort each pair internally so that
 * pair.first <= pair.second. The smaller element will later become a
 * "pending" element; the larger becomes part of the main chain.
 */
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

/*
 * insertPend: Step 5 of Ford-Johnson.
 * We have a sorted main chain and a list of pending elements (the
 * smaller values from each original pair). We insert them back.
 *
 * The first pending element (pend[0].first) is inserted "for free"
 * in the theoretical model — it goes directly into the chain.
 * If a strangler exists, it is inserted next.
 *
 * The remaining pending elements are inserted in batches whose sizes
 * follow the Jacobsthal sequence. Within each batch, every insertion
 * uses binary search (std::lower_bound) on the already-sorted chain.
 */
void PmergeMe::insertPend(std::vector<int>& newMain,
                std::vector<std::pair<int,int> > pend, int newStrang) {
    // Insert the first pending element for free
    int va = pend[0].first;
    std::vector<int>::iterator itt = std::lower_bound(newMain.begin(), newMain.end(), va);
    newMain.insert(itt, va);

    // Insert the strangler (odd unpaired element) if it exists
    if (newStrang != -1) {
        std::vector<int>::iterator it = std::lower_bound(newMain.begin(), newMain.end(), newStrang);
        newMain.insert(it, newStrang);
    }

    // Build the Jacobsthal sequence up to pend.size() + 1
    std::vector<int> jack = createJack(pend.size() + 1);

    // Insert remaining pending elements in Jacobsthal-sized batches.
    // For each Jacobsthal number, we insert a block of pending elements
    // from index 'start' down to 'end' + 1.
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

/*
 * makeMain: Extract the larger element from every pair.
 * These larger elements form the "main chain" that will be sorted
 * recursively by fordJohnson.
 */
std::vector<int> PmergeMe::makeMain(std::vector<std::pair<int,int> > pend) {
    std::vector<int> mainChain;
    for (size_t i = 0; i < pend.size(); i++)
        mainChain.push_back(pend[i].second);
    return mainChain;
}

/*
 * makeStrang: Detect the unpaired element when the input size is odd.
 * Returns the last element, or -1 if the size is even.
 */
int PmergeMe::makeStrang(std::vector<int> v) {
    if (v.size() % 2 == 1)
        return v.back();
    return -1;
}

/*
 * createJack: Build the Jacobsthal sequence.
 * J(0) = 0, J(1) = 1, and J(n) = J(n-1) + 2*J(n-2).
 * This yields: 1, 3, 5, 11, 21, 43, 85...
 * These numbers tell us how many pending elements to insert in each
 * batch. The order is optimal because it maximizes the knowledge we
 * gain from each comparison (Knuth, Art of Computer Programming Vol.3).
 */
std::vector<int> PmergeMe::createJack(size_t n) {
        std::vector<int> jack;
        jack.push_back(1);
        jack.push_back(3);
        while (jack.back() <= static_cast<int>(n))
            jack.push_back(jack[jack.size()-1] + 2 * jack[jack.size()-2]);
        return jack;
}

/*
 * fordJohnson: The core recursive merge-insertion sort.
 *
 * High-level flow:
 *   1. Base case: if we have 0 or 1 pending elements, just insert
 *      the pending element into the main chain and return.
 *   2. Build new pairs from the current main chain (makePend).
 *   3. Extract the larger elements as a new main chain (makeMain).
 *   4. Find the strangler of the current main chain.
 *   5. Recursively sort the new main chain.
 *   6. Insert the original pending elements back into the sorted chain
 *      using the Jacobsthal order (insertPend).
 *   7. Update the caller's mainChain with the fully sorted result.
 */
void	PmergeMe::fordJohnson(std::vector<int>&mainChain, std::vector<std::pair<int,int> > pend, int strangler, int count) {
    (void)strangler;
    (void)count;

    // Base case: 0 or 1 pending elements means we can insert directly.
    if (pend.size() <= 1) {
        if (!pend.empty()) {
            std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[0].first);
            mainChain.insert(it, pend[0].first);
        }
        return;
    }

    // Build pairs from the current main chain and extract larger elements.
    std::vector<std::pair<int,int> > newPend = makePend(mainChain);
    std::vector<int> newMain = makeMain(newPend);
    int newStrang = makeStrang(mainChain);

    // Recursively sort the new main chain.
    fordJohnson(newMain, newPend, newStrang, count + 1);

    // Insert the original pending elements back into the sorted chain.
    insertPend(newMain, pend, newStrang);

    // Propagate the sorted result upward.
    mainChain = newMain;
}

/* ============================================================
 *                    std::deque implementation
 * ============================================================
 *
 * The deque overloads follow the EXACT same algorithm as the vector
 * overloads above. The logic is duplicated rather than templated,
 * because the 42 subject explicitly advises against generic/template
 * sort functions spanning both containers.
 */

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
