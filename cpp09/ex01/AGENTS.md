# Repository Guidelines

## Project Overview

A minimal C++98 reverse-polish notation (RPN) calculator. It evaluates space-separated expressions composed of single-digit positive integers (`0`–`9`) and the operators `+`, `-`, `*`, `/`. The evaluator is stack-based and signals all error conditions via exceptions.

## Architecture & Data Flow

```
main.cpp
  │─ validates CLI args (exactly one argument)
  │─ instantiates RPN
  └─ calls evaluateRPN(string) and prints result
        │
        └─ istringstream tokenizes input by whitespace
              │─ digit (0–9)  → push to stack
              │─ operator     → pop two operands, apply, push result
              └─ anything else → throw std::runtime_error("Error")
```

- **Core logic is stateful**: `RPN` owns a `std::stack<int>`. Reusing the same instance for multiple evaluations accumulates state unless the stack is cleared—currently it is not.
- **Operator arity**: binary only. Pops `b` (top), then `a` (next), computes `a op b`.
- **Division**: integer division; division by zero throws `std::runtime_error("Error: division by zero")`.
- **Validation**: after tokenization, the stack must contain exactly one value; otherwise throws `std::runtime_error("Error")`.

## Key Directories

Flat layout at repository root:

| Path | Purpose |
|------|---------|
| `RPN.hpp` | Class declaration (`RPN`) |
| `RPN.cpp` | Implementation of stack evaluator |
| `main.cpp` | Entry point: argument validation, I/O, exception handling |
| `Makefile` | Build rules for the `RPN` binary |

## Development Commands

```bash
# Build
make              # produces ./RPN

# Clean
make clean      # remove object files
make fclean     # remove object files + binary
make re         # full rebuild
```

Compiler: `g++` with flags `-Wall -Wextra -Werror -std=c++98`.

## Code Conventions & Common Patterns

- **Standard**: strict C++98. No `auto`, range-based `for`, lambdas, or modern STL conveniences.
- **Error handling**: uses `std::runtime_error` with message `"Error"` for all malformed input cases. Division by zero uses `"Error: division by zero"`. The caller in `main.cpp` catches `const std::exception&` and prints `e.what()` to `std::cerr`.
- **Input tokenization**: `std::istringstream` with `operator>>` to split on whitespace.
- ** Orthodox Canonical Form**: `RPN` implements default constructor, copy constructor, copy assignment operator, and destructor even though the class is typically used as a short-lived automatic variable.
- **Naming**: PascalCase for class (`RPN`), camelCase for methods (`evaluateRPN`), snake_case for locals. Private member is `s` (the stack).
- **No dynamic allocation**: everything is value-based (`std::stack<int>`).
- **No tests**: there is no test harness or test directory.

## Important Files

| File | Role |
|------|------|
| `RPN.hpp` | Header guard (`#pragma once`), includes `<stack>`, `<string>`, `<sstream>`, `<iostream>`, `<stdexcept>`. Declares `evaluateRPN`. |
| `RPN.cpp` | Core evaluator logic. All parsing and arithmetic happen here. |
| `main.cpp` | Entry point. Validates `ac == 2`, wraps evaluation in `try/catch`, prints result or error message. |
| `Makefile` | Defines `NAME`, `SRCS`, `HEADERS`, `CCXXFLAGS`. Standard 42-school Makefile layout. |

## Runtime/Tooling Preferences

- **Compiler**: `g++`
- **Language**: C++98
- **Build tool**: GNU Make
- **No external dependencies**: only standard library headers.

## Testing & QA

There is no automated test suite. To verify behavior manually:

```bash
make
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"   # expected: 42
./RPN "7 7 * 7 -"                    # expected: 42
./RPN "1 2 * 2 / 2 * 2 4 - +"        # expected: 0
./RPN "(1 + 1)"                      # expected: Error
./RPN "10 2 +"                       # expected: Error (multi-digit numbers rejected)
./RPN "1 0 /"                        # expected: Error: division by zero
./RPN ""                             # expected: Error: no input (from main)
```

## AI Assistant Notes

- **Do not modernize to C++11/14/17/20** unless explicitly requested; the Makefile enforces `-std=c++98`.
- **Do not add a test framework** unless the user asks; 42-school exercises are typically validated by peer review and manual smoke tests.
- **When fixing parser bugs**, keep the `std::runtime_error("Error")` contract consistent—external evaluators often grep for exact output.
- **State reuse bug watch**: `RPN::evaluateRPN` does not clear `s` between calls. If the user later reuses an `RPN` instance, accumulated stack state will corrupt results. A robust fix is `while (!s.empty()) s.pop();` at the start of `evaluateRPN`, but verify intent before changing behavior.
- **Integer domain**: operands must be single-character digits. Negative numbers and multi-digit integers are explicitly rejected.
