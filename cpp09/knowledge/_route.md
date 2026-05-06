# Learning Route

## Overview
This route covers the three exercises of cpp09 across 5 sessions. We start with Bitcoin Exchange — the most accessible exercise — building from its data-loading fundamentals through its trickiest edge case (nearest-date lookup). Then we tackle Reverse Polish Notation, a compact exercise whose core insight (stack-based evaluation) connects directly to the pending-element insertion in PmergeMe. Finally, Ford-Johnson, the heavyweight: we'll decompose it step by step from pairing through Jacobsthal-ordered insertion.

## Sessions

### Session 1 — Bitcoin Exchange: I/O & Validation (6 concepts, ~15 min)
- [ ] C01: CSV Database Loading — entry point for understanding the program
- [ ] C06: Line-by-Line Input Processing — how the input file is consumed
- [ ] C03: Date Validation — building up from format to calendar correctness
- [ ] C04: Amount Validation — range and format checks
- [ ] C07: Error Message Strategy — what errors surface and how
- [ ] C08: Orthodox Canonical Form — class design requirement

### Session 2 — Bitcoin Exchange: Lookup & Maps (3 concepts, ~10 min)
- [ ] C02: std::map as Ordered Dict — why map, key ordering
- [ ] C05: Nearest-Date Rate Lookup — the core algorithmic challenge
- [ ] C09: Container Non-Reuse Rule — module constraint

### Session 3 — RPN (7 concepts, ~15 min)
- [ ] C10: RPN Definition — postfix notation fundamentals
- [ ] C11: Stack-Based Evaluation — the core algorithm
- [ ] C12: Token Parsing — splitting the expression
- [ ] C13: Operator Reduction — pop, compute, push
- [ ] C14: RPN Error States — what can go wrong
- [ ] C15: Single-Digit Operand Constraint — why it matters
- [ ] C16: std::stack Container Adapter — interface and limitations
- [ ] C17: Container Chaining Restriction — connecting back to module rules

### Session 4 — PmergeMe: Ford-Johnson Foundations (7 concepts, ~20 min)
- [ ] C18: Ford-Johnson Algorithm Overview — the big picture
- [ ] C31: Positive Integer Input Validation — parsing requirements
- [ ] C30: Input Size Handling — the 3000+ element requirement
- [ ] C19: Pairing Adjacent Elements — the first step
- [ ] C20: Main Chain Extraction — separating larger elements
- [ ] C21: Strangler Element — handling odd counts
- [ ] C22: Recursive Sorting of Main Chain — the recursive core

### Session 5 — PmergeMe: Insertion & Container Choice (7 concepts, ~20 min)
- [ ] C23: Jacobsthal Sequence — what it is and why it's optimal
- [ ] C24: Binary Search Insertion — lower_bound mechanics
- [ ] C25: Pending Element Insertion Order — tying it all together
- [ ] C26: Two-Container Requirement — vector and deque
- [ ] C27: Performance Measurement — timing approach
- [ ] C28: Template vs Explicit Duplication — design trade-off
- [ ] C29: Comparison Counting — theoretical performance angle

## Route Rationale
The exercises are taken in subject order (ex00 → ex01 → ex02), which also happens to be increasing difficulty. Bitcoin Exchange introduces file I/O, maps, and validation patterns that build confidence. RPN is the shortest, cleanest exercise — a single-function algorithm on a stack — and serves as a warm-up for the more complex Ford-Johnson insertion mechanic, which also relies on ordered structures and sequential insertion. PmergeMe is split into two sessions: first the pairing/recursive pipeline, then the Jacobsthal insertion and container-level concerns.
