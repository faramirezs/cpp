
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

// std::vector<std::pair<int,int> > makePend(std::vector<int> v) {
// std::vector<std::pair<int,int> > makePend(const std::vector<int>& v, CountingLess<int>& cmp) {//TEST
//     std::vector<std::pair<int,int> > pend;
//     for (std::vector<int>::const_iterator it = v.begin();
//         it + 1 < v.end(); it += 2) {
//             int a = *it;
//             int b = *(it + 1);

//             // pend.push_back(std::make_pair(
//                 // std::min(*it, *(it+1)), std::max(*it, *(it+1))));//guarantee order in each pair -> compara 1 de mas
//                 // std::min(*it, *(it+1)), std::max(*it, *(it+1), cmp)));//TEST
//                 // *it, *(it+1)));//TEST -> no cumple con el algoritmo

//             if (cmp(a, b))//one comparison
//                 pend.push_back(std::make_pair(a, b));
//             else
//                 pend.push_back(std::make_pair(b, a));
//     }
//     return pend;
// }

// std::vector<int> makeMain(std::vector<std::pair<int,int> > pend) {
//     std::vector<int> mainChain;
//     for (size_t i = 0; i < pend.size(); i++)
//         mainChain.push_back(pend[i].second);
//     return mainChain;
// }

// int makeStrang(std::vector<int> v) {
//     if (v.size() % 2 == 1)
//         return v.back();
//     return -1;
// }

// std::vector<int> createJack(size_t n) {
//         std::vector<int> jack;
//         jack.push_back(1);
//         jack.push_back(3);
//         while (jack.back() <= static_cast<int>(n))
//             jack.push_back(jack[jack.size()-1] + 2 * jack[jack.size()-2]);//jack.size()-1 is = to jack.back()
//         return jack;
// }

/*
    1. Always insert pend[0]
    2. If there is strangler place it for free
    3. create jackobsthal seq
    4. Loop to inset pend
*/
// void insertPend(std::vector<int>& newMain,
//                 // std::vector<std::pair<int,int> > pend, int newStrang) {
//                 std::vector<std::pair<int,int> > pend, int newStrang, CountingLess<int>& cmp) {//TEST: ountingLess<int> cmp
//     // insert pend[0] is free
//     int va = pend[0].first;
//     // std::vector<int>::iterator itt = std::lower_bound(newMain.begin(), newMain.end(), va);
//     std::vector<int>::iterator itt = std::lower_bound(newMain.begin(), newMain.end(), va, cmp);//TEST
//     newMain.insert(itt, va);

//     //if there is strangler put it
//     if (newStrang != -1) {
//         // std::vector<int>::iterator it = std::lower_bound(newMain.begin(), newMain.end(), newStrang);
//         std::vector<int>::iterator it = std::lower_bound(newMain.begin(), newMain.end(), newStrang, cmp);//TEST
//         newMain.insert(it, newStrang);
//     }

//     //create jackobsthal
//     std::vector<int> jack = createJack(pend.size() + 1);

//     /*     LOOP TO INSERT WITH JACKOBSTHAL
//         1. Loop in jack
//             start in 1
//         2. Loop in pend & insert
//             Loop in pend should start in pen[1] (can be start)
//     */
//     for (size_t j = 1; j < jack.size(); ++j) {//size_t = 1 because before was inserted pend[0]
//         int start = jack[j] - 1;//j = 1 because
//         // pend[0] was inserted
//         int end = jack[j - 1] - 1;
//         if (start >= static_cast<int>(pend.size()))//to avoid jack going beyond pend size
//             start = static_cast<int>(pend.size()) - 1;

//         // testJackRange(start, end, j, pend);//TEST

//         for (int i = start; i > end && i < static_cast<int>(pend.size()); --i) {//end is the last insertion considering jack
//                 // testCurrentPendInsert(pend, i);//TEST
//                 int val = pend[i].first;
//                 std::vector<int>::iterator it = std::lower_bound(newMain.begin(),
//                     // newMain.end(), val);//-1 to start in pend[0]
//                     newMain.end(), val, cmp);//TEST
//                 newMain.insert(it, val);
//             }
//     }
//     // testJack(jack, count);//TEST
// }


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
// void    fordJohnson(std::vector<int>&mainChain, std::vector<std::pair<int,int> > pend, int strangler, int count) {
// void    fordJohnson(std::vector<int>&mainChain, std::vector<std::pair<int,int> > pend, int strangler, int count, CountingLess<int>& cmp) {//TEST
//     // 4. recursion part 1. to organize "main chains" from cupido + create pends with pairs
//     // if (mainChain.size() <= 1){ //base case to stop recursion
//     if (pend.size() <= 1) { //check this option
//         if (!pend.empty()) {
//             // std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[0].first);
//             std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[0].first, cmp);//TEST
//             mainChain.insert(it, pend[0].first);
//         }
//         return;
//     }
//     // std::vector<std::pair<int,int> > newPend = makePend(mainChain);
//     std::vector<std::pair<int,int> > newPend = makePend(mainChain, cmp);//TEST

//     testPend(newPend, count);//test

//     std::vector<int> newMain = makeMain(newPend);
//     int newStrang = makeStrang(mainChain);

//     // fordJohnson(newMain, newPend, newStrang, count + 1);
//     fordJohnson(newMain, newPend, newStrang, count + 1, cmp);//TEST

//     testMainCinRonud(mainChain, count);//TEST per round

//     // 5. recursion part 2. include pend insertion with Jackobshal number (include stranglers)
//     // insertPend(newMain, pend, newStrang, count);//count just for testing
//     insertPend(newMain, pend, newStrang, cmp);//TEST

//     //update mainchain with the result
//     mainChain = newMain;

//     testMainCinRonud(newMain, count);//TEST
// }

//change "victor" "for Before: "
// void printInput(std::vector<int> victor) {
//     std::cout << INPUT << BOLD << "\nvictor is: " << RESET;
//     for (int i = 0; i < victor.size(); ++i) {
//         std::cout << victor[i];
//         if (i < victor.size() - 1) std::cout << " ";
//     }
// }

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
    // std::vector<int> victor;
	try {
    PmergeMe p(av);
    // int i = 0;
    // for (int j = 1; av[j]; j++) {
    //     std::istringstream iss(av[j]);//handle eof
    //     int n;
    //     iss >> n;// extracts the int from stream
    //     p.victor.push_back(n);//check if worked, else invalid int if needed
    // }

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
    // std::vector<std::pair<int,int> > cupido = makePend(victor);
    std::vector<std::pair<int,int> > cupido = p.makePend(p.getVictor(), cmp);//add cmp TEST
    int strangler = p.makeStrang(p.getVictor());

    testCupido(cupido); //TEST
    testStrangler(strangler);//TEST

    // Recursion
    std::vector<int> mainChain = p.makeMain(cupido);
    // fordJohns on(mainChain, cupido, strangler, 0);
    p.fordJohnson(mainChain, cupido, strangler, 0, cmp);

    //insert the very first strangler
    if (strangler != -1) {
        // std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), strangler);
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
