<!-- Memory Bank File: Common Student Issues Catalog -->
<!-- Purpose: Catalog of common errors and Socratic diagnostic approaches -->
<!-- Update Frequency: When new error patterns emerge during tutoring -->
<!-- Cross-references: →knowledgebase.md (concept explanations), →tutoring-insights.md (effective patterns) -->

# Common Student Issues & Socratic Guidance - C++ Focus

## How to Use This File:
- Reference when students encounter errors or show confusion
- Use diagnostic questions to help students self-identify issues
- Add new patterns as they emerge during tutoring sessions
- Guide students toward understanding rather than giving direct solutions
- Focus on C++ specific issues for modules 00-04

---

## C++ Specific Common Issues:

### Issue: Missing Semicolon After Class Definition
**Symptoms:** Compiler error about missing semicolon; errors in subsequent code lines.
**Likely Misconceptions:** Not understanding that class definitions need semicolons (unlike functions).
**Socratic Diagnostic Questions:**
- "What's different about how you end a class definition versus a function definition?"
- "Look at the error line number - is that where you think the problem is?"
- "What punctuation do you see after other class definitions in examples?"
**Guidance Strategies (NOT solutions):**
- Guide them to compare their class syntax with working examples
- Ask them to read compiler error messages carefully
- Point out the difference between class declarations and function definitions

### Issue: Confusion Between Public and Private Access
**Symptoms:** Compiler errors about accessing private members; confusion about encapsulation.
**Likely Misconceptions:** Not understanding access specifiers; thinking all class members are accessible.
**Socratic Diagnostic Questions:**
- "What's the difference between public and private in your class?"
- "Why might you want some parts of your class to be hidden from outside code?"
- "Where are you trying to access this variable from?"
- "What methods does your class provide to work with private data?"
**Guidance Strategies (NOT solutions):**
- Use analogy of house with public rooms vs private rooms
- Guide them to trace data flow and access patterns
- Reference encapsulation concepts in knowledgebase.md

### Issue: Static Member Access Confusion
**Symptoms:** Trying to access static members through object instances; confusion about class-level vs object-level data.
**Likely Misconceptions:** Not understanding that static members belong to class, not objects.
**Socratic Diagnostic Questions:**
- "Does this data belong to a specific object or to all objects of this class?"
- "If no objects exist yet, should this data still be accessible?"
- "How many copies of this variable exist if you have 5 objects?"
- "What's the difference between Account::_nbAccounts and myAccount._amount?"
**Guidance Strategies (NOT solutions):**
- Use whiteboard analogy (shared vs individual notebooks)
- Guide them to think about data ownership and scope
- Reference static vs instance concepts in knowledgebase.md

### Issue: Constructor Parameter vs Member Variable Confusion
**Symptoms:** Shadowing warnings; incorrect initialization; confusion about parameter scope.
**Likely Misconceptions:** Not understanding scope of constructor parameters vs member variables.
**Socratic Diagnostic Questions:**
- "What happens when a parameter has the same name as a member variable?"
- "How does the compiler know which 'name' you're referring to?"
- "What's the scope of constructor parameters?"
- "How long do constructor parameters exist?"
**Guidance Strategies (NOT solutions):**
- Guide them to use different parameter names first, then introduce 'this->'
- Help them trace variable scope and lifetime
- Reference constructor concepts in knowledgebase.md

### Issue: Header File and Implementation Separation
**Symptoms:** Linker errors; multiple definition errors; confusion about .hpp vs .cpp files.
**Likely Misconceptions:** Not understanding declaration vs definition; confusion about header inclusion.
**Socratic Diagnostic Questions:**
- "What's the difference between declaring a function and defining it?"
- "Why do we separate class declarations from implementations?"
- "What happens when you #include a file?"
- "Where should function bodies go - header or implementation file?"
**Guidance Strategies (NOT solutions):**
- Use blueprint vs building analogy
- Guide them to understand compilation process
- Help them organize code structure logically

### Issue: iostream vs stdio Mixing
**Symptoms:** Mixing printf/scanf with cout/cin; confusion about C vs C++ I/O.
**Likely Misconceptions:** Not understanding difference between C and C++ I/O approaches.
**Socratic Diagnostic Questions:**
- "What language features are you using here - C or C++?"
- "What's the difference between printf and cout?"
- "Why might C++ provide its own I/O system instead of just using C's?"
- "Which approach fits better with object-oriented programming?"
**Guidance Strategies (NOT solutions):**
- Guide them to choose one approach consistently
- Help them understand language evolution and design principles
- Reference C++ stream concepts

### Issue: Memory Management Confusion (new/delete)
**Symptoms:** Memory leaks; double deletion; using delete instead of delete[]; segmentation faults.
**Likely Misconceptions:** Not understanding dynamic memory ownership; confusion about when to delete.
**Socratic Diagnostic Questions:**
- "Who owns this memory - which part of your code is responsible for cleaning it up?"
- "What happens if you delete the same memory twice?"
- "How does 'new' differ from declaring a variable normally?"
- "What's the difference between 'delete' and 'delete[]'?"
**Guidance Strategies (NOT solutions):**
- Use RAII principles and smart pointer concepts
- Guide them to trace memory ownership
- Reference dynamic allocation concepts in knowledgebase.md

### Issue: Memory Leaks from Forgetting delete/delete[]
**Symptoms:** Program uses increasing memory; valgrind shows "definitely lost" blocks.
**Likely Misconceptions:** Not understanding that new requires matching delete; thinking destructors automatically clean up dynamic memory.
**Socratic Diagnostic Questions:**
- "When you use 'new' to create an object, who is responsible for cleaning it up?"
- "What happens to heap-allocated memory if you don't explicitly delete it?"
- "How is this different from stack-allocated objects?"
- "Why doesn't the destructor automatically clean up objects created with new?"
**Guidance Strategies (NOT solutions):**
- Guide them to trace object ownership and lifetime
- Help them identify every 'new' and match it with corresponding 'delete'
- Reference RAII concepts in knowledgebase.md

### Issue: Using delete instead of delete[] for arrays
**Symptoms:** Undefined behavior; possible crashes; only first element destructor called.
**Likely Misconceptions:** Not understanding difference between single object and array allocation.
**Socratic Diagnostic Questions:**
- "What's the difference between 'new Zombie' and 'new Zombie[5]'?"
- "How does the compiler know how many destructors to call?"
- "Why do arrays need special treatment for deletion?"
- "What happens if you mix up delete and delete[]?"
**Guidance Strategies (NOT solutions):**
- Guide them to match allocation/deallocation pairs consistently
- Help them understand array vs single object lifetime
- Reference dynamic arrays concepts in knowledgebase.md

### Issue: Reference Initialization and Reassignment Confusion
**Symptoms:** Compiler errors about uninitialized references; confusion about reference behavior.
**Likely Misconceptions:** Treating references like pointers; not understanding reference immutability.
**Socratic Diagnostic Questions:**
- "What does it mean for a reference to be an 'alias'?"
- "Can a nickname exist without a person to nickname?"
- "What happens when you assign to a reference after creating it?"
- "Why can't references be reassigned like pointers?"
**Guidance Strategies (NOT solutions):**
- Use nickname/alias analogies consistently
- Guide them to understand reference binding vs assignment
- Reference references vs pointers concepts in knowledgebase.md

### Issue: Null Pointer Dereferencing in Pointer to Member Functions
**Symptoms:** Segmentation faults when calling function through null pointer.
**Likely Misconceptions:** Not checking pointer validity; confusion about pointer to member syntax.
**Socratic Diagnostic Questions:**
- "What could cause a pointer to member function to be invalid?"
- "How do you check if a pointer is safe to dereference?"
- "What's the difference between a null pointer and an uninitialized pointer?"
- "Why might a pointer to member function be null?"
**Guidance Strategies (NOT solutions):**
- Guide them to validate pointers before dereferencing
- Help them understand pointer safety patterns
- Reference pointer concepts in knowledgebase.md

### Issue: Stack Overflow from Large Stack Allocations
**Symptoms:** Segmentation fault; stack overflow errors with large objects/arrays.
**Likely Misconceptions:** Not understanding stack size limitations; using stack for large data.
**Socratic Diagnostic Questions:**
- "Why might the stack have size limitations?"
- "When would you choose heap over stack for large objects?"
- "What happens if you try to create a very large array on the stack?"
- "How do you determine if something should be stack or heap allocated?"
**Guidance Strategies (NOT solutions):**
- Guide them to consider data size and lifetime requirements
- Help them understand stack vs heap trade-offs
- Reference stack vs heap concepts in knowledgebase.md

---

## Template for Adding New Issues:

### Issue: [Issue Name]
**Symptoms:** [How the problem manifests - error messages, unexpected behavior, etc.]
**Likely Misconceptions:** [What students typically misunderstand that leads to this]
**Socratic Diagnostic Questions:**
- "[Question to help student identify the problem]"
- "[Question to explore their understanding]"
- "[Question to guide toward solution]"
**Guidance Strategies (NOT solutions):**
- [Strategy to help them discover the fix]
- [Alternative approach if first doesn't work]
- [Reference to related concepts in knowledgebase.md]
- "What do you think happens when Python reads this function definition?"
- "When do you think the code inside the function actually runs?"
- "What's the difference between writing a recipe and cooking a meal?"
**Guidance Strategies (NOT solutions):**
- Use the recipe analogy (writing vs cooking)
- Have them trace through code execution step by step
- Ask them to predict what gets printed before running code

### Issue: Variable Scope Confusion
**Symptoms:** UnboundLocalError, unexpected None values, variables not updating as expected.
**Likely Misconceptions:** Not understanding where variables can be accessed; confusion about local vs global.
**Socratic Diagnostic Questions:**
- "Where do you think this variable was created?"
- "From this point in the code, which variables can you access?"
- "What's the 'lifetime' of this variable?"
**Guidance Strategies (NOT solutions):**
- Use box/container analogies for different scopes
- Have them draw variable scope diagrams
- Ask them to trace variable creation and destruction

### Issue: Indentation Errors (Python-specific)
**Symptoms:** IndentationError, unexpected indent, unindent does not match.
**Likely Misconceptions:** Not understanding that indentation defines code structure in Python.
**Socratic Diagnostic Questions:**
- "What do you think the indentation is telling Python about your code structure?"
- "Which lines should be 'inside' the function/loop/if statement?"
- "How does Python know where one block ends and another begins?"
**Guidance Strategies (NOT solutions):**
- Have them identify which lines belong together
- Ask them to explain the code structure in words first
- Suggest using consistent indentation (tabs vs spaces)

### Issue: Infinite Loops
**Symptoms:** Program hangs, doesn't terminate, needs to be force-stopped.
**Likely Misconceptions:** Not ensuring loop condition eventually becomes false.
**Socratic Diagnostic Questions:**
- "What needs to change inside the loop for it to eventually stop?"
- "How does the loop condition change with each iteration?"
- "What would make this condition become false?"
**Guidance Strategies (NOT solutions):**
- Have them trace through several iterations
- Ask them to identify what should change each time
- Suggest adding print statements to see variable changes

---

*Add new common issues below using the template structure above.*

**Cross-References:**
- **→ knowledgebase.md**: Links to related concept definitions and core explanations
- **← tutoring-insights.md**: Sources proven guidance strategies and successful approaches
- **→ active-session.md**: Provides diagnostic questions for current student difficulties
- **← progress.md**: Reference student's learning journey to contextualize current issues
