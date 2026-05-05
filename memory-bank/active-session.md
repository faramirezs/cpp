<!-- Memory Bank File: Active Session Tracker -->
# Active Session Context

**Session Date:** 2026-05-05
**Student Identifier:** alejiri

## Current Problem/Topic Focus:
- C++ Module 09 - Exercise 02 (PmergeMe) - Ford-Johnson merge-insert sort algorithm

## Evaluation of Current State (PmergeMe):

### What is DONE:
✅ **Core Algorithm Logic:** Working prototype for `std::vector`! The Ford-Johnson algorithm sorts the vector correctly.
✅ **Second Container Identified:** `std::deque<int> dictor` is declared in the class.
✅ **Compilation:** The copy constructors and makefile issues are resolved, and the project compiles and runs the vector sort successfully.

### What is MISSING / NEEDS FIXING (Strict Subject Compliance):
❌ **Strict Parsing in Constructor:** The parsing inside `PmergeMe::PmergeMe(char** av)` uses `iss >> n;` but does NOT check if the stream fails, if there are leftover characters (like `123a`), negative numbers (`-5`), or integer overflows. If an error occurs, it must print "Error" to standard error and exit.
❌ **Algorithm for Second Container:** The algorithm is only implemented for `std::vector`. The subject explicitly mandates to implement it for a second container (e.g., `std::deque`) and strongly advises NOT using templates/generic functions for it (i.e. you need `makePendDeque`, `fordJohnsonDeque`, etc.).
❌ **Timing Measurement Placement:** Currently, part of the algorithm (`cupido = makePend(victor, cmp)`) runs inside the constructor! The timer in `main()` starts *after* the constructor, meaning the sorting time measurement is inaccurate. The algorithm execution for each container must happen entirely inside the timed block.
❌ **Strict Output Formatting:** The program prints extensive debug info (colored text, arrays of pairs, theoretical bits). The subject demands a very strict output format:
```text
Before: [unsorted sequence]
After: [sorted sequence]
Time to process a range of N elements with std::vector : X us
Time to process a range of N elements with std::deque : X us
```

## Pathway to Finish (Step-by-Step MVP Approach):
1. **MVP 1: Robust Parsing & Error Handling**
   - Fortify the input parsing to catch negative numbers, non-numeric characters, and overflows. Throw exceptions and catch them in `main` to print "Error".
2. **MVP 2: Untangle Constructor & Algorithm**
   - Remove `makePend` from the constructor. The constructor should ONLY parse and populate the initial `victor` and `dictor`.
   - Create a method like `void sortVector()` where the actual algorithm starts.
3. **MVP 3: Second Container (Deque) Implementation**
   - Duplicate/overload the `fordJohnson` and helper methods so they run independently for `std::deque dictor`.
   - Create a `void sortDeque()` method.
4. **MVP 4: Strict Output Formatting & Timing**
   - In `main()`, start the timer -> run `sortVector()` -> stop timer.
   - Start timer -> run `sortDeque()` -> stop timer.
   - Clean up all `std::cout` statements to perfectly match the subject's required 4 lines of output (`Before:`, `After:`, and the two `Time to process...` lines).

## Next Socratic Question
"Your algorithm successfully sorts the vector! However, looking at the subject, we need to precisely measure the time taken to sort the elements. Right now, `cupido = makePend(...)` is called inside your constructor, before `gettimeofday` is even called in `main`. How could we restructure this so that the entire sorting process (for both vector and deque) only happens exactly when we want to measure it?"
