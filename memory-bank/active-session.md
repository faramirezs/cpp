<!-- Memory Bank File: Active Session Tracker -->
# Active Session Context

**Session Date:** 2026-05-05
**Student Identifier:** alejiri

## Current Problem/Topic Focus:
- C++ Module 09 - Exercise 02 (PmergeMe) - Ford-Johnson merge-insert sort algorithm

## Evaluation of Current State (PmergeMe):

### What is DONE:
✅ **Core Algorithm Logic Prototype:** Working prototype in `main.cpp`.
✅ **MVP 1 Progress (Restructuring Started):** You've created `PmergeMe.hpp` and `PmergeMe.cpp`. You've moved some attributes into the class (`mainChain`, `d`, `pend`, `victor`, `cupido`) and started implementing the constructor to parse input.
✅ **Second Container Identified:** You've added `std::deque<int> d` to your class, which is a great choice as your second container!

### What is MISSING / NEEDS FIXING:
❌ **Compile-Breaking Copy Operations:** `PmergeMe(const PmergeMe &other): s(other.s){}` has an error because `s` doesn't exist in this class. (Copy syntax from old classes often needs a quick update).
❌ **Strict Parsing in Constructor:** The parsing inside `PmergeMe::PmergeMe(char** av)` uses `iss >> n;` but does NOT check if the stream fails, if there are leftover characters (like `123a`), or if `n <= 0`.
❌ **Algorithm Transfer Incomplete:** Most of the algorithm (`fordJohnson`, `insertPend`, `createJack`, etc.) is still sitting in `main.cpp`. 
❌ **Makefile:** Still missing compilation rules to link the new `.cpp` files.

## Pathway to Finish (Step-by-Step MVP Approach):
1. **MVP 1 (Current Focus): Finish the Structure**
   - Fix the `PmergeMe` copy constructor and copy assignment operator.
   - Fortify the input constructor parsing (check for bad characters and negative numbers).
   - Move the rest of the `vector` sorting functions from `main.cpp` into `PmergeMe` and ensure it runs natively inside a `.sort()` method.
2. **MVP 2: Clean Output Formatting**
   - Format `Before:` and `After:` correctly. Remove debug prints.
3. **MVP 3: Second Container (Deque)**
   - Adapt the logic to run for `std::deque` as well.
4. **MVP 4: Timing & Final Integration**
   - Wrap the execution in the correct timing logs required by the subject.

## Next Socratic Question
"I see you've created `PmergeMe.hpp/cpp` and brought in `victor` and a new `deque`! However, if you look closely at your copy constructor, there's a small copy-paste leftover causing a compilation issue. Before we migrate the rest of the algorithm, what is the best way to handle parsing errors in a C++ constructor if an invalid input like `"123a"` or `"-5"` is encountered?"
