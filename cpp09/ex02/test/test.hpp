#ifndef TEST_HPP
#define TEST_HPP

#include <vector>
#include <algorithm> //sort
#include <iostream>
#include <utility> // pair
#include "colors.hpp"

void testComparison(std::vector<int> mainChain, std::vector<int> victor);

void testCupido(std::vector<std::pair<int,int> >cupido);

void testPend(std::vector<std::pair<int,int> > newPend, int count);

void testStrangler(int strangler);

void testCurrentPendInsert(std::vector<std::pair<int,int> > pend, int i);

void testJack(std::vector<int> jack, int count);

void testJackRange(int start, int end, int j, std::vector<std::pair<int,int> > pend);

void testMainCinRonud(std::vector<int> mainChain, int count);

#endif