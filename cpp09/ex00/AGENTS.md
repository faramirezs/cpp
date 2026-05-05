# Repository Guidelines

## Project Overview

A minimal C++98 CLI tool that evaluates Bitcoin holdings over time. It reads an input file of `date | amount` pairs, looks up the nearest historical exchange rate from a CSV database, and prints the USD equivalent.

- **Binary**: `btc`
- **Standard**: C++98 (`-std=c++98`)
- **School**: 42 curriculum (cpp09/ex00)

## Architecture & Data Flow

```
   data.csv         input file           stdout/stderr
      |                 |                     ^
      v                 v                     |
 [loadCSV()]      [main parser]               |
      |                 |                     |
      v                 v                     |
 std::map        validation chain              |
 (date -> rate)   (date, amount, range)       |
      |                 |                     |
      +----> getRate() <--+                   |
                |                             |
                +-------> amount * rate ------+
```

1. `BitcoinExchange` loads `data.csv` into an ordered `std::map<std::string, float>` at construction.
2. `getRate(date)` uses `lower_bound` to find the exact or nearest earlier date.
3. `main.cpp` parses the input file, validates each line, and prints `date => amount = value`.

## Key Directories

Flat structure — all files are in the project root:

| File | Purpose |
|------|---------|
| `main.cpp` | Entry point, CLI parsing, per-line validation, output |
| `BitcoinExchange.cpp` | Class implementation: CSV loading and rate lookup |
| `BitcoinExchange.hpp` | Class declaration and `#define DB_DATA "data.csv"` |
| `Makefile` | Build rules for `btc` binary |
| `data.csv` | Price database (1614 rows, 2009-01-02 to 2022-03-29) |
| `test.txt` | Primary test input with edge cases |
| `extest.txt` | Extended test input with inline comment categories |

## Development Commands

```bash
# Build
make            # compiles btc
make re         # clean rebuild

# Clean
make clean      # remove .o files
make fclean     # remove .o + binary

# Run
./btc test.txt
./btc extest.txt
```

## Code Conventions & Common Patterns

- **Orthodox Canonical Form**: Every class implements default constructor, copy constructor, copy assignment operator, and destructor.
- **Naming**: Classes are `PascalCase`; methods and free functions are `camelCase`; private members are plain (`db`).
- **Error handling**: All errors print to `std::cerr` with distinct literal messages. No exceptions are thrown.
- **Validation is free-function based**: `isValidDate` and `isValidAmount` are non-member functions in `main.cpp`, not class methods.
- **Input parsing**: `std::getline` and `std::istringstream` with `>>` operator extraction.
- **Date format**: Strict `YYYY-MM-DD` string comparison (lexicographic ordering works because the map keys are ISO-like).
- **Amount constraints**: Must be numeric, single decimal point allowed, range `[0, 1000]` inclusive.
- **Lookup behavior**: If the exact date is missing, the most recent prior date's rate is used. Dates before `2009-01-02` are rejected by validation.

## Important Files

- **`BitcoinExchange.hpp`** (`#pragma once`)
  - `std::map<std::string, float> db`
  - `void loadCSV()` — parses comma-separated `date,rate` lines
  - `float getRate(std::string date)` — `lower_bound` lookup; may decrement iterator if exact match not found

- **`main.cpp`**
  - Expects exactly one command-line argument (input file path)
  - Skips the first line as a header
  - Parses lines as: `date` `|` `amountStr`
  - Validation order: date format → amount format → negative check → >1000 check

## Runtime/Tooling Preferences

- **Compiler**: `g++`
- **Flags**: `-Wall -Wextra -Werror` (warnings are errors)
- **Standard**: C++98
- **No external dependencies**: Only STL headers (`<iostream>`, `<map>`, `<string>`, `<fstream>`, `<sstream>`, `<iomanip>`)
- **No package manager**, no CMake, no sanitizers, no optimization flags set

## Testing & QA

- **No formal test framework**: Testing is done by running `./btc <file>` and inspecting stderr/stdout.
- **Test files**:
  - `test.txt` — broad edge case coverage (malformed dates, invalid amounts, whitespace, empty lines, boundary values)
  - `extest.txt` — same cases with inline `#` comment headers; some lines include trailing comments
- **Expected output pattern**:
  - Valid: `2011-01-03 => 3 = 0.90` (rate * amount, fixed 2 decimal places)
  - Invalid date: `Error: bad input date => <date>`
  - Invalid amount: `Error: bad input amount => <amount>`
  - Negative: `Error: negative number`
  - Too large: `Error: too large a number`
  - Parse failure: `Error: input expecs: date | amount` (note the typo)

## Known Quirks & Defects

- `getRate()` has undefined behavior if the database is empty (dereferences `lower_bound` result unconditionally).
- `atof` is used without guarding against overflow or non-numeric input beyond the `isValidAmount` pre-check.
- `isValidDate` only checks `day >= 1 && day <= 31`; it does not reject invalid month-day combinations (e.g., `2011-02-30` is accepted by day check but rejected because it does not exist in the DB — however the validation logic marks it as valid).
- The error message `Error: input expecs: date | amount` contains a typo (`expecs`).
- Trailing whitespace after the amount (e.g., `2     `) is tolerated by `ss >> amountStr`, but trailing text (e.g., `2 abc`) causes `isValidAmount` to fail.
- `extest.txt` contains `#` comment lines and inline comments; the current parser does **not** strip comments, so lines like `2010-02-26 | 2 # ===== DATES SAME AS THE DB =====` will fail parsing unless comments are handled.
