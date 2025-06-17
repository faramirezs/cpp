<!-- Memory Bank File: Programming Concepts Knowledge Base -->
<!-- Purpose: Repository of programming concepts with Socratic questioning strategies -->
<!-- Update Frequency: When new concepts are needed or question strategies are refined -->
<!-- Cross-references: ←common-student-issues.md (error patterns), ←progress.md (student mastery) -->

# Programming Concepts Knowledge Base - C++ Focus

## How to Use This File:
- Add new concepts as needed during tutoring
- Reference concept-specific questions during sessions
- Use analogies to help explain abstract concepts
- Keep code snippets simple and illustrative
- Focus on C++ object-oriented programming concepts for modules 00-04

---

## C++ Module Progression Overview:
- **Module 00:** Namespace, classes, member functions, stdio streams, initialization lists, static, const
- **Module 01:** Memory allocation, pointers to members, references, switch statement
- **Module 02:** Ad-hoc polymorphism, operator overloading, Orthodox Canonical class form
- **Module 03:** Inheritance
- **Module 04:** Subtype polymorphism, abstract classes, interfaces

---

## C++ Specific Concepts:

### Concept: Class vs Object

**Core Explanation (For Tutor's Understanding):**
- Class is a blueprint/template that defines structure and behavior
- Object is an instance of a class - actual memory allocation
- Classes define member variables and member functions
- Each object has its own copy of member variables but shares member functions

**Helpful Analogies:**
- Class = House blueprint, Object = Actual house built from that blueprint
- Class = Cookie cutter, Object = Individual cookies made with the cutter
- Class = Recipe, Object = Actual meal cooked from the recipe

**Key Socratic Questions for This Concept:**
- "What's the difference between defining a class and creating an object?"
- "If I have 3 contact objects, how many copies of the member functions exist?"
- "What happens in memory when you write 'contact c1' vs when you write 'c1.displayContact()'?"
- "Why do we need both classes and objects instead of just one or the other?"

**Common Student Misconceptions:**
- Thinking class and object are the same thing
- Believing each object has its own copy of member functions
- Confusion about when memory is allocated

**Diagnostic Questions for Misconceptions:**
- "How many contact classes exist in your phonebook program?"
- "When you create a contact object, what exactly gets stored in memory?"

**Simple Illustrative Code Snippets (For Tutor Reference Only):**
```cpp
// Class definition - blueprint
class Contact {
private:
    std::string name;
public:
    void setName(std::string n) { name = n; }
};

// Object creation - actual instances
Contact person1; // One object
Contact person2; // Another object
```

**Prerequisites:** Basic understanding of data types and functions
**Leads to:** Constructors, destructors, static members

### Concept: Static vs Instance Members

**Core Explanation (For Tutor's Understanding):**
- Static members belong to the class itself, not to any specific object
- Instance members belong to each individual object
- Static members are shared across all objects of the class
- Static members exist even before any objects are created

**Helpful Analogies:**
- Static = Shared classroom whiteboard (one for all students)
- Instance = Individual student notebooks (each student has their own)
- Static = University rules (same for all students), Instance = Student grades (different for each)

**Key Socratic Questions for This Concept:**
- "If I have 5 Account objects, how many copies of _nbAccounts exist?"
- "What happens to static variables when all objects are destroyed?"
- "Why would you want data that's shared between all objects?"
- "How do you access a static member without creating an object?"

**Common Student Misconceptions:**
- Thinking static members are copied for each object
- Confusion about when static members are initialized
- Not understanding why static methods can't access instance variables

**Diagnostic Questions for Misconceptions:**
- "If I change _totalAmount in one Account object, what happens in other Account objects?"
- "Can a static method access a non-static member variable? Why or why not?"

**Simple Illustrative Code Snippets (For Tutor Reference Only):**
```cpp
class Account {
private:
    static int _nbAccounts;  // Shared by all objects
    int _amount;             // Each object has its own
public:
    static int getNbAccounts() { return _nbAccounts; }
    int getAmount() { return _amount; }
};
```

**Prerequisites:** Understanding of classes and objects
**Leads to:** Singleton pattern, class design principles

### Concept: Constructor and Destructor

**Core Explanation (For Tutor's Understanding):**
- Constructor is called automatically when object is created
- Destructor is called automatically when object is destroyed
- Constructors initialize object state and can take parameters
- Destructors clean up resources (memory, files, etc.)

**Helpful Analogies:**
- Constructor = Setting up your workspace when you arrive at work
- Destructor = Cleaning up your workspace when you leave
- Constructor = Birth certificate, Destructor = Death certificate
- Constructor = Moving into apartment, Destructor = Moving out

**Key Socratic Questions for This Concept:**
- "What happens if you don't write a constructor for your class?"
- "When exactly does the destructor get called?"
- "Why might you need different constructors with different parameters?"
- "What's the relationship between object lifetime and constructor/destructor calls?"

**Common Student Misconceptions:**
- Thinking constructors and destructors are regular functions you call manually
- Not understanding automatic constructor/destructor invocation
- Confusion about default constructor vs parameterized constructor

**Diagnostic Questions for Misconceptions:**
- "Do you need to explicitly call the constructor when creating an object?"
- "What happens if your class allocates memory but doesn't have a destructor?"

**Simple Illustrative Code Snippets (For Tutor Reference Only):**
```cpp
class Contact {
public:
    Contact() { std::cout << "Contact created\n"; }           // Constructor
    Contact(std::string n) : name(n) { }                     // Parameterized constructor
    ~Contact() { std::cout << "Contact destroyed\n"; }       // Destructor
private:
    std::string name;
};
```

**Prerequisites:** Understanding of classes and objects
**Leads to:** Copy constructors, assignment operators, RAII

### Concept: Stack vs Heap Allocation

**Core Explanation (For Tutor's Understanding):**
- Stack allocation: automatic storage, managed by compiler, limited lifetime (scope-based)
- Heap allocation: dynamic storage, managed by programmer, flexible lifetime (until explicitly deleted)
- Stack is faster but limited in size and lifetime
- Heap allows larger allocations and cross-scope object sharing

**Helpful Analogies:**
- Stack = Post-it notes (temporary, automatically discarded when done)
- Heap = Filing cabinet (permanent storage until you decide to throw away)
- Stack = Hotel room (automatic checkout when you leave)
- Heap = Buying a house (yours until you sell it)

**Key Socratic Questions for This Concept:**
- "When would you want an object to outlive the function that created it?"
- "What happens to stack-allocated objects when a function returns?"
- "Who is responsible for cleaning up heap-allocated memory?"
- "What are the trade-offs between stack and heap allocation?"

**Common Student Misconceptions:**
- Thinking all objects should be heap-allocated
- Not understanding automatic cleanup of stack objects
- Forgetting to delete heap-allocated memory

**Diagnostic Questions for Misconceptions:**
- "What happens to a Zombie object created with 'Zombie z' when the function ends?"
- "If you create a Zombie with 'new', what must you remember to do?"

**Simple Illustrative Code Snippets (For Tutor Reference Only):**
```cpp
void function() {
    Zombie stackZombie("Bob");     // Stack - automatic cleanup
    Zombie* heapZombie = new Zombie("Alice"); // Heap - manual cleanup required
    // stackZombie destroyed automatically here
    delete heapZombie; // Must manually delete
}
```

**Prerequisites:** Understanding of object lifecycle and constructors/destructors
**Leads to:** Smart pointers, RAII principles

### Concept: References vs Pointers

**Core Explanation (For Tutor's Understanding):**
- Reference is an alias - another name for an existing object
- Pointer is a variable that stores memory address of another object
- References must be initialized and cannot be reassigned
- Pointers can be null, reassigned, and used for arithmetic

**Helpful Analogies:**
- Reference = Nickname (always refers to the same person)
- Pointer = Address on envelope (can be changed, can be invalid)
- Reference = Direct phone connection (always connected to same person)
- Pointer = Phone number (can call different numbers, number might not exist)

**Key Socratic Questions for This Concept:**
- "What's the difference between giving someone a nickname vs giving them your address?"
- "Can a reference exist without referring to something?"
- "Why might you choose a reference over a pointer for a function parameter?"
- "When would you need the flexibility of a pointer instead of a reference?"

**Common Student Misconceptions:**
- Thinking references are just "safer pointers"
- Trying to reassign references after initialization
- Not understanding that references must always refer to valid objects

**Diagnostic Questions for Misconceptions:**
- "Can you change what a reference refers to after you create it?"
- "What happens if you try to create a reference without initializing it?"

**Simple Illustrative Code Snippets (For Tutor Reference Only):**
```cpp
int x = 5;
int& ref = x;        // Reference - alias for x
int* ptr = &x;       // Pointer - stores address of x

ref = 10;            // Changes x to 10
*ptr = 20;           // Changes x to 20
ptr = nullptr;       // Valid - pointer can be null
// int& ref2;        // ERROR - references must be initialized
```

**Prerequisites:** Understanding of memory addresses and variable scope
**Leads to:** Function parameters, member variables design decisions

### Concept: Dynamic Arrays (new[] and delete[])

**Core Explanation (For Tutor's Understanding):**
- Arrays can be allocated dynamically when size is not known at compile time
- Must use new[] for array allocation and delete[] for deallocation
- Mixing new/delete with new[]/delete[] causes undefined behavior
- Each element's constructor/destructor is called appropriately

**Helpful Analogies:**
- new[] = Renting a row of hotel rooms (all at once)
- delete[] = Checking out of all rooms (must return all keys)
- Single new/delete = Renting/returning one room
- Wrong pairing = Using wrong key type (chaos ensues)

**Key Socratic Questions for This Concept:**
- "Why do we need a special delete[] for arrays?"
- "What happens if you use delete instead of delete[] on an array?"
- "How does the program know how many objects to destroy with delete[]?"
- "When would you use dynamic arrays instead of fixed-size arrays?"

**Common Student Misconceptions:**
- Using delete instead of delete[] for arrays
- Thinking array size must be constant
- Not understanding that each array element gets constructed/destructed

**Simple Illustrative Code Snippets (For Tutor Reference Only):**
```cpp
int n = 5;
Zombie* zombies = new Zombie[n];  // Array of n zombies
// ... use the zombies
delete[] zombies;                 // Must use delete[] not delete
```

**Prerequisites:** Understanding of constructors/destructors and basic pointers
**Leads to:** STL containers, memory management patterns

### Concept: Reference Binding and Const-correctness

**Core Explanation (For Tutor's Understanding):**
- Non-const lvalue references (T&) can only bind to non-const lvalues (named variables that can be modified)
- Const references (const T&) can bind to lvalues, temporaries, literals, and const objects
- Const member functions guarantee not to modify the object, allowing them to be called on const objects
- Reference members must be initialized in the initializer list
- Object lifetime is critical: references to destroyed/copy objects lead to undefined behavior

**Helpful Analogies:**
- Reference = Nickname for a specific person (must always refer to someone who exists)
- Const reference = Nickname you promise never to use to change the person
- Temporary = Visitor who leaves quickly; only safe to reference if you promise not to change them

**Key Socratic Questions for This Concept:**
- "Why can't you bind a non-const reference to a temporary or literal?"
- "What happens if you try to modify an object through a const reference?"
- "Why do reference members require initialization in the initializer list?"
- "What is the difference between lvalue and rvalue in C++?"
- "How does object lifetime affect the safety of references in class design?"
- "Why do you need const member functions to call them on const objects?"

**Common Student Misconceptions:**
- Thinking all references can bind to any object
- Not realizing temporaries are destroyed at the end of the full expression
- Confusing constness of reference with constness of the object

**Diagnostic Questions for Misconceptions:**
- "What happens if you return a reference to a local variable?"
- "Why does the compiler complain about type qualifiers when calling a non-const member function on a const object?"

**Simple Illustrative Code Snippets (For Tutor Reference Only):**
```cpp
int x = 5;
int &ref1 = x;         // OK: non-const lvalue
const int &ref2 = 10;  // OK: binds to temporary
int &ref3 = 10;        // ERROR: cannot bind non-const ref to temporary
```

**Prerequisites:** Understanding of references and object lifetime
**Leads to:** Advanced class design, understanding temporaries and literals

### Concept: Class Design - References vs Pointers for Object Relationships

**Core Explanation (For Tutor's Understanding):**
- References represent permanent, required relationships between objects
- Pointers represent optional, changeable relationships between objects
- References must be initialized in constructor, cannot be reassigned
- Pointers can be NULL/nullptr, can be assigned later, can be changed
- Const references allow binding to temporaries and provide read-only access
- Choice depends on relationship semantics: permanent vs optional, required vs changeable

**Helpful Analogies:**
- Reference = Marriage certificate (permanent, cannot be changed once established)
- Pointer = Dating relationship (can be single, can change partners)
- Const reference = Library book (read-only access, but you can look at any book)
- Non-const reference = Personal tool (full access, but only to tools you own)

**Key Socratic Questions for This Concept:**
- "If HumanA must always have a weapon, what storage type ensures this requirement?"
- "If HumanB might not have a weapon initially, what storage type allows this flexibility?"
- "Why can't you assign to a reference member after construction?"
- "What's the difference between 'Weapon club; setWeapon(club);' and 'setWeapon(&club);'?"
- "When would you prefer a const reference over a non-const reference parameter?"
- "How do you represent 'no weapon' with a pointer vs a reference?"

**Common Student Misconceptions:**
- Thinking all references can be reassigned like pointers
- Not understanding why reference members require initializer list initialization
- Confusion about reference parameter vs pointer parameter in function calls
- Believing that passing by reference always creates a copy

**Diagnostic Questions for Misconceptions:**
- "Can you set a reference member to point to a different object after construction?"
- "What happens if you try to call setWeapon(club) when expecting a pointer?"
- "Why does 'const Weapon &' bind to temporaries but 'Weapon &' doesn't?"

**Simple Illustrative Code Snippets (For Tutor Reference Only):**
```cpp
// Permanent relationship - always has weapon
class HumanA {
    const Weapon &weapon;  // Reference: permanent, required
public:
    HumanA(const Weapon &w) : weapon(w) {}  // Must initialize
};

// Optional relationship - may have weapon
class HumanB {
    Weapon *weapon;  // Pointer: optional, changeable
public:
    HumanB() : weapon(nullptr) {}  // Can start with no weapon
    void setWeapon(Weapon &w) { weapon = &w; }  // Can assign later
};
```

**Prerequisites:** Understanding of references, pointers, constructors, const-correctness
**Leads to:** Advanced class design patterns, RAII, smart pointers

---

## Template for Adding New Concepts:

### Concept: [Concept Name]

**Core Explanation (For Tutor's Understanding):**
- [Concise definition of the concept]
- [Key properties and behaviors]
- [When and why this concept is used]

**Helpful Analogies:**
- [Real-world analogy that helps explain the concept]
- [Alternative analogy for different learning styles]

**Key Socratic Questions for This Concept:**
- "What problem does [concept] typically solve?"
- "What are the essential parts of a [concept]?"
- "How does [concept] differ from [related_concept]?"
- "Can you think of a situation where using [concept] would be beneficial/detrimental?"
- "What happens if we remove/change [specific part] of this [concept]?"

**Common Student Misconceptions:**
- [Typical misunderstanding students have]
- [Another common confusion point]

**Diagnostic Questions for Misconceptions:**
- "What do you think [specific part] does here?"
- "How would you explain [concept] to someone who's never seen it before?"

**Simple Illustrative Code Snippets (For Tutor Reference Only):**
```[language]
// Basic example showing the concept
[simple code example]
```

```[language]
// Common mistake or edge case
[example of common error]
```

**Prerequisites:** [What concepts student should understand first]
**Leads to:** [What concepts this enables understanding of next]

---

## Example Concept Entry:

### Concept: Variables

**Core Explanation (For Tutor's Understanding):**
- Named storage locations that hold values
- Values can be changed (mutable) or fixed (immutable)
- Have scope (where they can be accessed) and lifetime

**Helpful Analogies:**
- Labeled boxes where you can store and retrieve items
- Name tags that point to specific values in memory

**Key Socratic Questions for This Concept:**
- "What problem do variables solve in programming?"
- "What happens when you try to use a variable before giving it a value?"
- "How is creating a variable different from using a variable?"
- "Why might you want to change a variable's value?"

**Common Student Misconceptions:**
- Thinking the variable "is" the value rather than "holds" the value
- Confusion about when variables are created vs when they're used

**Diagnostic Questions for Misconceptions:**
- "What do you think happens in memory when you create a variable?"
- "If I change this variable here, what happens to other places that use it?"

**Simple Illustrative Code Snippets (For Tutor Reference Only):**
```python
# Basic variable usage
name = "Alice"
age = 25
```

```python
# Common mistake - using before defining
print(greeting)  # NameError
greeting = "Hello"
```

**Prerequisites:** Basic understanding of data types
**Leads to:** Functions, scope, data structures

---

*Add new concepts below following the template structure above.*

**Cross-References:**
- **← tutoring-insights.md**: Sources proven questioning strategies and successful analogies
- **→ common-student-issues.md**: Links concept misconceptions to diagnostic approaches
- **← progress.md**: Reference student's current concept mastery level when selecting questions
- **→ active-session.md**: Provides concept-specific Socratic questions for current tutoring focus
