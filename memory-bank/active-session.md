<!-- Memory Bank File: Active Session Tracker -->
# Active Session Context

**Session Date:** 2026-05-05
**Student Identifier:** alejiri

## Current Problem/Topic Focus:
- C++ Module 09 - Exercise 02 (PmergeMe) - Ford-Johnson merge-insert sort algorithm

## Evaluation of Current State (PmergeMe):

### What is DONE & VERIFIED (Requirements fully met):
✅ **Positive Integer Sequence Parsing:** `PmergeMe.cpp` now strictly parses only positive integers (`> 0` and `<= INT_MAX`), rejecting negative numbers and strings like `123a` or overflows, throwing and catching an `"Error"` exactly as requested.
✅ **Two Different Containers:** `std::vector` and `std::deque` are correctly utilized.
✅ **No Generic Functions Used:** Ford-Johnson is robustly overloaded/duplicated with exact implementations for `vector` and `deque` (`makePendDeque`, `insertPendDeque`, etc.).
✅ **Merge-Insert Sort Algorithm:** The Ford-Johnson split, sort, and Jacobsthal insertion routine correctly implements the assignment constraints for both containers.
✅ **Timing Measurement Placement:** Timers (`gettimeofday`) strictly enclose only the algorithm logic per container now, keeping parsing isolated.
✅ **Strict Output Format:** The required output matches line-by-line expectations perfectly:
   - `Before: ...`
   - `After: ...`
   - `Time to process a range of X elements with std::vector : X us`
   - `Time to process a range of X elements with std::deque : X us`

### What is MISSING / NEEDS FIXING:
- **Nothing core!** You have functionally satisfied 100% of the C++ Module 09 Exercise 02 subject rules.
- *(Minor/Optional Cleanup)* You have an unused member `std::deque<int> dictor;` inside `PmergeMe.hpp` (since you're allocating `std::deque<int> dequeVictor` in `main.cpp`). It can optionally be removed to clean up the private space or populated in the constructor instead. 

## Pathway to Finish:
1. **Clean/Refactor (Optional):** Remove unused or commented code (e.g., `dictor`).
2. **Extensive Testing:** Verify with exactly 3000 random ints using the bash command:
   `./PmergeMe $(shuf -i 1-100000 -n 3000 | tr "\n" " ")` or the macOS equivalent `jot` / `ruby`. You did this natively in the terminal and it returned exit code 0 securely!

## Next Socratic Question
"Your recent changes hit all the requirements on the head! You isolated your algorithms perfectly without generic templates, the timers are accurately placed, and your edge-case parsing covers negativity and alphabetics gracefully. If you review your `PmergeMe.hpp`, you'll notice one private class member representing a `deque` that is sitting completely idle now because you allocated your deque dynamically inside `main`. Can you find it and remove it to finalize your code cleanup?"
