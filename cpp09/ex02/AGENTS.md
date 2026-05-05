# Repository Guidelines

## Project Overview

PmergeMe is Exercise 02 of 42's C++ Module 09 (STL). It implements the Ford-Johnson merge-insertion sort algorithm to sort a sequence of positive integers passed as command-line arguments. The program must sort using **two different STL containers** and display timing comparisons between them.

The project lives inside the `cpp09/ex02/` directory of a larger 42 C++ module sequence.

---

## Architecture & Data Flow

### High-Level Flow

1. **Parse** CLI arguments into integers (`main.cpp`)
2. **Pair** adjacent elements, sorting each pair internally (`makePend`)
3. **Recursively sort** the "main chain" (larger elements of each pair) using the same algorithm (`fordJohnson`)
4. **Insert** the "pending" elements (smaller elements of each pair) back into the sorted main chain in Jacobsthal order (`insertPend`)
5. **Handle** the "strangler" (odd element out if odd count) via binary insertion
6. **Measure** and display timing for both containers

### Key Modules

| Component | File | Purpose |
|-----------|------|---------|
| `PmergeMe` class | `PmergeMe.hpp`, `PmergeMe.cpp` | Core algorithm: pair creation, recursion, Jacobsthal insertion |
| `CountingLess<T>` | `Count.hpp` | Functor template wrapping `operator<` to count comparisons |
| Debug helpers | `test.hpp`, `test.cpp` | Colored console output for intermediate state verification |
| Color macros | `colors.hpp` | ANSI escape codes for terminal output |
| Entry point | `main.cpp` | Parsing, orchestration, timing (`gettimeofday`), result display |

### Data Structures

- **`cupido`** (`std::vector<std::pair<int,int>>`): Pairs of adjacent input elements, where `pair.first <= pair.second` within each pair.
- **`mainChain`** (`std::vector<int>`): The recursively sorted sequence of larger pair elements.
- **`pend`** (`std::vector<std::pair<int,int>>`): During recursion, the pairs derived from the current main chain.
- **`strangler`** (`int`): The unpaired last element when input size is odd; `-1` if none.
- **`jack`** (`std::vector<int>`): Jacobsthal sequence (`J(n) = J(n-1) + 2*J(n-2)`), used to determine optimal insertion order of pending elements.

---

## Key Directories

This is a flat, single-directory exercise. All source files are at the repository root:

```
cpp09/ex02/
├── main.cpp          # Entry point, parsing, timing, display
├── PmergeMe.hpp      # Class declaration
├── PmergeMe.cpp      # Ford-Johnson algorithm implementation
├── Count.hpp         # Comparison-counting functor template
├── test.hpp          # Debug function declarations
├── test.cpp          # Debug function implementations
├── colors.hpp        # ANSI color macros
└── en.subject.md     # 42 exercise subject (requirements)
```

---

## Development Commands

### Build

There is **no Makefile in `ex02/` yet**, but the module pattern from `ex00/` and `ex01/` is:

```makefile
NAME    = PmergeMe
SRCS    = main.cpp PmergeMe.cpp test.cpp
CCXX    = g++
CCXXFLAGS = -Wall -Wextra -Werror -std=c++98
```

Manual compile (mirroring the module standard):

```bash
g++ -Wall -Wextra -Werror -std=c++98 main.cpp PmergeMe.cpp test.cpp -o PmergeMe
```

### Run

```bash
# Small test
./PmergeMe 3 5 9 7 4

# Large test (3000 random integers, Linux)
./PmergeMe $(shuf -i 1-100000 -n 3000 | tr "\n" " ")

# Large test (macOS)
./PmergeMe $(jot -r 3000 1 100000 | tr '\n' ' ')
```

### Clean

```bash
rm -f PmergeMe *.o
```

---

## Code Conventions & Common Patterns

### Language & Standard

- **C++98** (`-std=c++98`). No C++11 or later features.
- **Compiler**: `g++` with `-Wall -Wextra -Werror`.
- No `using namespace std;` (forbidden by 42 guidelines).
- No `friend` keyword (forbidden by 42 guidelines).

### Class Design: Orthodox Canonical Form

All classes must implement:
1. Default constructor
2. Copy constructor
3. Copy assignment operator
4. Destructor

Example from `PmergeMe`:
```cpp
PmergeMe();
PmergeMe(const PmergeMe &other);
PmergeMe& operator=(const PmergeMe &other);
~PmergeMe();
```

> **Note**: The copy constructor and assignment operator in `PmergeMe` are currently stubbed (`//todo`) and unsafe if used.

### Naming Conventions

- **Classes**: `UpperCamelCase` (e.g., `PmergeMe`, `CountingLess`)
- **Files**: Match class name exactly (`PmergeMe.hpp`, `PmergeMe.cpp`)
- **Member variables**: No enforced prefix, but observe `mainChain`, `comp_count`, `victor`
- **Functions**: `lowerCamelCase` for methods (`makePend`, `insertPend`, `fordJohnson`)

### Headers & Includes

- Use **include guards** (`#ifndef` / `#define` / `#endif`) or `#pragma once`.
- Every header must be independently includable (include all its own dependencies).
- Function implementations in headers (except templates) are penalized.

### Error Handling

- Parsing errors write to `std::cerr` and exit non-zero.
- No exceptions are used; errors are handled via early returns or `std::cerr`.
- Input validation requirements: positive integers only, no non-numeric input, handle overflow.

### Algorithm Patterns

**Pair-wise sorting (`makePend`)**:
```cpp
for (it = v.begin(); it + 1 < v.end(); it += 2) {
    if (cmp(a, b))
        pend.push_back(std::make_pair(a, b));
    else
        pend.push_back(std::make_pair(b, a));
}
```

**Recursive sorting (`fordJohnson`)**:
```cpp
if (pend.size() <= 1) { /* base case: insert last pending element */ return; }
std::vector<std::pair<int,int>> newPend = makePend(mainChain, cmp);
std::vector<int> newMain = makeMain(newPend);
int newStrang = makeStrang(mainChain);
fordJohnson(newMain, newPend, newStrang, count + 1, cmp);
insertPend(newMain, pend, strangler, cmp);
mainChain = newMain;
```

**Jacobsthal insertion (`insertPend`)**:
- `pend[0]` is inserted "for free" (no comparison cost in theoretical model).
- If a strangler exists, it is inserted next.
- Remaining pending elements are inserted in batches dictated by Jacobsthal numbers, using `std::lower_bound` (binary search) for each insertion.

**Comparison counting**:
```cpp
int comp_count = 0;
CountingLess<int> cmp(comp_count);
// Pass cmp to all sort operations; cmp.getCount() returns total comparisons.
```

---

## Important Files

| File | Role |
|------|------|
| `main.cpp` | Entry point. Parses args, creates `PmergeMe`, runs sort, prints timing and comparisons. |
| `PmergeMe.hpp` | Class interface. Declares all algorithm methods and member containers. |
| `PmergeMe.cpp` | Algorithm implementation. Contains `fordJohnson`, `insertPend`, `makePend`, `createJack`. |
| `Count.hpp` | Template functor `CountingLess<T>` that wraps a comparison and increments a counter. |
| `test.cpp` / `test.hpp` | Debug utilities: print intermediate chains, pairs, Jacobsthal sequence, correctness check against `std::sort`. |
| `colors.hpp` | ANSI color definitions for terminal output. |
| `en.subject.md` | Full 42 exercise specification (requirements, constraints, expected output). |

---

## Runtime/Tooling Preferences

| Setting | Value |
|---------|-------|
| Compiler | `g++` |
| Standard | C++98 (`-std=c++98`) |
| Flags | `-Wall -Wextra -Werror` |
| Build system | `Makefile` (expected; missing in current directory) |
| Timing | `gettimeofday` (microsecond precision) |
| OS | Cross-platform (Linux/macOS); note `shuf` vs `jot` for test data generation |

---

## Testing & QA

### Manual Verification

The codebase includes a built-in correctness test:
```cpp
testComparison(mainChain, victor); // Compares result against std::sort
```

This prints `CORRECT` (green) or `WRONG` (red) to stdout.

### Subject Requirements Checklist

The following are mandated by `en.subject.md` and should be verified:

- [ ] Program name is `PmergeMe`.
- [ ] Accepts a positive integer sequence as arguments.
- [ ] Uses **two different containers** (currently `std::vector` is implemented; `std::deque` is declared but unused).
- [ ] Displays `Before:` line with unsorted sequence.
- [ ] Displays `After:` line with sorted sequence.
- [ ] Displays timing for **both** containers with element count.
- [ ] Can handle at least **3000** different integers.
- [ ] Errors go to `std::cerr`.
- [ ] No generic/template sort function spanning both containers (subject advises separate implementations per container).

### Known Gaps (as of current state)

1. **Missing `Makefile`** in `ex02/`.
2. **`std::deque` implementation is absent**: `PmergeMe` declares `std::deque<int> d` but never uses it. The subject requires sorting with two distinct containers.
3. **Display format mismatch**: The current `main.cpp` does not print `Before:` / `After:` headers as specified.
4. **Unsafe OCF stubs**: Copy constructor and assignment operator are incomplete (`//todo`).
5. **Parser robustness**: `std::istringstream >> n` does not validate that the entire token is consumed (e.g., `123abc` would parse as `123`).
6. **Commented dead code**: `main.cpp` contains large blocks of commented-out free functions that were refactored into the `PmergeMe` class.

---

## Working with This Codebase

- **Adding the second container**: The subject strongly advises implementing the algorithm separately for each container rather than using a single template function. Consider adding `fordJohnsonDeque`, `insertPendDeque`, etc., or templating only the comparator/element type while duplicating the container-specific logic.
- **Removing debug code**: The `//TEST` comments and `test*.hpp/cpp` files are development aids. Before submission, strip or guard debug output to match the exact subject display format.
- **Fixing the parser**: Ensure tokens like `+5`, `-1`, `abc`, `2147483648` are rejected appropriately. Check `iss >> n` followed by `iss.eof()`.
- **Completing OCF**: Implement or delete the copy constructor and assignment operator. If deleted, ensure no code paths invoke them.
