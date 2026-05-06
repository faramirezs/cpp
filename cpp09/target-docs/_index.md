# Target Documentation Index

## Total Concepts: 31

## Concept Map
| ID | Concept | Dependencies | Complexity | Domain |
|----|---------|--------------|------------|--------|
| C01 | CSV Database Loading | none | foundational | ex00 — Bitcoin Exchange |
| C02 | std::map as Ordered Dict | none | foundational | ex00 — Bitcoin Exchange |
| C03 | Date Validation (YYYY-MM-DD) | none | intermediate | ex00 — Bitcoin Exchange |
| C04 | Amount Validation (0..1000) | none | intermediate | ex00 — Bitcoin Exchange |
| C05 | Nearest-Date Rate Lookup (lower_bound) | C02 | advanced | ex00 — Bitcoin Exchange |
| C06 | Line-by-Line Input Processing | C01 | intermediate | ex00 — Bitcoin Exchange |
| C07 | Error Message Strategy | none | foundational | ex00 — Bitcoin Exchange |
| C08 | Orthodox Canonical Form | none | foundational | General C++ |
| C09 | Container Non-Reuse Rule | none | foundational | Module Rules |
| C10 | RPN Definition (Postfix) | none | foundational | ex01 — RPN |
| C11 | Stack-Based Evaluation | C10 | foundational | ex01 — RPN |
| C12 | Token Parsing from String | none | intermediate | ex01 — RPN |
| C13 | Operator Reduction (pop, apply, push) | C11 | intermediate | ex01 — RPN |
| C14 | RPN Error States | C11 | intermediate | ex01 — RPN |
| C15 | Single-Digit Operand Constraint | none | foundational | ex01 — RPN |
| C16 | std::stack Container Adapter | none | intermediate | ex01 — RPN |
| C17 | Container Chaining Restriction | C09 | foundational | Module Rules |
| C18 | Ford-Johnson Algorithm Overview | none | advanced | ex02 — PmergeMe |
| C19 | Pairing Adjacent Elements | C18 | intermediate | ex02 — PmergeMe |
| C20 | Main Chain Extraction | C19 | intermediate | ex02 — PmergeMe |
| C21 | Strangler Element | C19 | intermediate | ex02 — PmergeMe |
| C22 | Recursive Sorting of Main Chain | C20, C18 | advanced | ex02 — PmergeMe |
| C23 | Jacobsthal Sequence | none | intermediate | ex02 — PmergeMe |
| C24 | Binary Search Insertion (lower_bound) | none | intermediate | ex02 — PmergeMe |
| C25 | Pending Element Insertion Order | C23, C24, C18 | advanced | ex02 — PmergeMe |
| C26 | Two-Container Requirement | C18 | foundational | ex02 — PmergeMe |
| C27 | Performance Measurement (gettimeofday) | none | intermediate | ex02 — PmergeMe |
| C28 | Template vs Explicit Duplication | C26 | advanced | ex02 — PmergeMe |
| C29 | Comparison Counting | C18 | advanced | ex02 — PmergeMe |
| C30 | Input Size Handling (3000+) | none | foundational | ex02 — PmergeMe |
| C31 | Positive Integer Input Validation | none | intermediate | ex02 — PmergeMe |

## Key Themes
- **CSV I/O & Validation**: covers concepts [C01, C03, C04, C06, C07]
- **Container Fundamentals**: covers concepts [C02, C09, C16, C26]
- **Expression Evaluation**: covers concepts [C10, C11, C12, C13, C14, C15]
- **Ford-Johnson Mechanics**: covers concepts [C18, C19, C20, C21, C22, C23, C24, C25, C29]
- **Performance & Constraints**: covers concepts [C27, C28, C30, C31]
- **C++98 Discipline**: covers concepts [C08, C09, C17, C28]

## Coverage Baseline
Total atomic concepts: 31
Estimated questions to full coverage: 47
