
#include "PmergeMe.hpp"

#include "colors.hpp"//TEST
#include "test.hpp"//TEST
#include "Count.hpp"//TEST


/*
    1. parse + handle errores
    2. create victor: argv to int (stoi)
    3. create cupido[0] (container with std::pairs)
    4. recursion (1. get final mainChain. 2. insert with Jackobsthal)
*/

// TEST FUNCTION //
int fordJohnsonTheoretical(int n) {
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
//timeval is a struct with tv_sec (seconds) and tv_usec(microsec)
struct timeval start, end;





/*
    1. Always insert pend[0]
    2. If there is strangler place it for free
    3. create jackobsthal seq
    4. Loop to inset pend
*/


void printResult(std::vector<int> mainChain) {
    std::cout << BOLD << RESULT << "\nfinal mainChain: " << RESET;
    for (size_t i = 0; i < mainChain.size(); ++i) {
        std::cout << mainChain[i];
        if (i + 1 < mainChain.size()) std::cout << " ";
    } std::cout << std::endl;
}

/*
    If there is not strangler pend[0] is free, -> handle that if there is no strangler is -1 can lead to an error
    if not if will follows jackobsthal
    organize the elements from jackobsthal to the left then to the next
*/

//change "victor" "for Before: "

void printTime(size_t n, std::string container) {
    //elapsed total time in microsec & convert the diff of sec to microsec (* 1e6)
    double elapsed = (end.tv_sec - start.tv_sec) * 1e6
               + (end.tv_usec - start.tv_usec);
    //us = microsec
    std::cout << "Time to process a range of " << n
              << " elements with " << container
              << " : " << elapsed << " us" << std::endl;
}

void printCompare(const CountingLess<int>& cmp) {
    std::cout << BOLD << "Total comparisons: " << RESET << cmp.getCount() << std::endl;
}

    /*
        Parsing errors (std::cer):
            exclude negative numbers
            exclude 0
            it's not a number like letter or abc
            overflow
    */
int main(int argc, char **av) {
    // 1. parse + handle errores
    if (argc < 2) {
        std::cerr << RED << "write one or more <int>" << RESET << std::endl;
        return 1;
    }
    // 2. argv to int
	try {
    PmergeMe p(av);

   p.printInput();
    std::cout << std::endl;

    //from epoch & ptr to struct timezone is NULL
    gettimeofday(&start, NULL);

    //handle 1 element
    if (p.getVictorSize() == 1) {
        std::cout << "Final main: " << p.getVictorValue(0) << std::endl;
        return 0;
    }

    // 3. create cupido from the original input: container with pairs
    int comp_count = 0;//TEST
    CountingLess<int> cmp(comp_count);//TEST
    std::vector<std::pair<int,int> > cupido = p.makePend(p.getVictor(), cmp);//add cmp TEST
    int strangler = p.makeStrang(p.getVictor());

    testCupido(cupido); //TEST
    testStrangler(strangler);//TEST

    // Recursion
    std::vector<int> mainChain = p.makeMain(cupido);
    p.fordJohnson(mainChain, cupido, strangler, 0, cmp);

    //insert the very first strangler
    if (strangler != -1) {
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), strangler, cmp);//include cmp TEST
        mainChain.insert(it, strangler);
    }
    printResult(mainChain);
    gettimeofday(&end, NULL);

    printTime(p.getVictorSize(), "std::vector");
    printCompare(cmp);//TEST
    std::cout << "Total Theoretical: " << fordJohnsonTheoretical(p.getVictorSize()) << std::endl;

    testComparison(mainChain, p.getVictor()); // TEST with std::sort
		return 0;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
}

/*  TEST WITH 3000 (creates numbers from 1 to 10000)
    ./a.out $(shuf -i 1-100000 -n 3000 | tr "\n" " ") 2>&1 | grep "Time"

    WITH COMPARISON TEST:
    ./a.out $(shuf -i 1-100000 -n 3000 | tr "\n" " ") 2>&1 | grep -E "Time|CORRECT|WRONG"

    WITH THEORETICAL:
    ./a.out $(shuf -i 1-100000 -n 3000 | tr "\n" " ") 2>&1 | grep "Total"
*/
