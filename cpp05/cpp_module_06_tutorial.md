# C++ Module 06 Tutorial: Repetition and Exceptions

*Note: This tutorial covers Module 05 (Repetition and Exceptions). The content provided covers this module in depth.*

## Role & Identity

**Your Role:** Programming tutor using the Socratic method  
**Your Goal:** Foster independent problem-solving and deep conceptual understanding  

---

## Part 1: Understanding Exception Handling Fundamentals

Before diving into the exercises, let's establish a strong foundation in exception handling.

### 1.1 What is Exception Handling?

**Guiding Questions:**

1. In C, how did you typically signal that an error occurred in a function? What were the limitations of that approach?

<details>
<summary>Show Hint</summary>

Think about return codes. What happens if a function needs to return actual data but also needs to signal an error? How do you distinguish between them?

</details>

2. Imagine you're writing a function that must never fail (or failure is unrecoverable). Would a return code approach work well? Why or why not?

<details>
<summary>Show Hint</summary>

Consider: What if the caller ignores the return code? What if multiple functions need to cooperate to clean up resources?

</details>

### 1.2 Exception Mechanics

**Guiding Questions:**

1. What do you think happens when you `throw` an exception? Where does control flow go?

<details>
<summary>Show Hint</summary>

The program doesn't continue to the next line after a throw statement. Instead, it searches for a matching `catch` block. The program "unwinds" the call stack until it finds one.

</details>

2. If a `catch` block catches an exception, does the program terminate or continue?

<details>
<summary>Show Hint</summary>

After the catch block completes, execution continues with the next statement *after* the try-catch construct (not back into the try block).

</details>

3. What happens if you throw an exception and there's no matching `catch` block anywhere in the call stack?

<details>
<summary>Show Answer</summary>

The program terminates with `std::terminate()`. This is why it's important to catch exceptions where they can be handled meaningfully.

</details>

---

## Part 2: Exception Classes and Design Patterns

### 2.1 Creating Custom Exceptions

**Guiding Question:**

In the Bureaucrat exercise, you need to create `Bureaucrat::GradeTooHighException` and `Bureaucrat::GradeTooLowException`. What would be a good base class for these exceptions?

<details>
<summary>Show Hint</summary>

Look at the code example in the exercise. What type is caught in the catch block? What does this tell you about what your exceptions should inherit from?

</details>

**Key Insight to Discover:**

Think about this: The example shows catching `std::exception`. What do you think is the advantage of having all your exceptions inherit from a common base class?

<details>
<summary>Show Answer</summary>

By inheriting from `std::exception`, your custom exceptions can be caught by a generic `catch (std::exception& e)` block. This allows the caller to handle both your specific exceptions and standard library exceptions uniformly. You can also call `e.what()` to get an error message.

</details>

### 2.2 What the Specifications Require

**Guiding Question:**

The specification says: "Please note that exception classes do not have to be designed in Orthodox Canonical Form. However, every other class must follow it."

What do you think the Orthodox Canonical Form is?

<details>
<summary>Show Hint</summary>

Think about what a complete class needs to manage its lifetime and data. What special member functions control how objects are created, copied, and destroyed?

</details>

<details>
<summary>Show Answer</summary>

Orthodox Canonical Form includes:
1. A default constructor
2. A copy constructor
3. A copy assignment operator
4. A destructor

For exception classes specifically, you can keep things simple since they typically just store and report error information.

</details>

---

## Part 3: Exercise 0 Deep Dive - Building Your First Exception-Aware Class

### 3.1 Designing the Bureaucrat Class

Let's think about what a Bureaucrat needs.

**Question 1:** The Bureaucrat has a `name` that is constant and a `grade` that ranges from 1 to 150. Which of these should be attributes, and why should the name be constant?

<details>
<summary>Show Hint</summary>

A constant attribute cannot be modified after initialization. What does this tell you about the Bureaucrat's identity? Should a bureaucrat be able to change their name mid-career?

</details>

**Question 2:** The specification requires getters for both `name` and `grade`. Should these getters be const member functions? Why or why not?

<details>
<summary>Show Hint</summary>

A const member function cannot modify the object. If you're just reading a value, should you be allowed to modify the object? Think about the principle of least privilege.

</details>

### 3.2 Managing Grade Validity

**Question 1:** You need to validate the grade in the constructor. If the grade is out of range (not between 1 and 150), you must throw an exception. When exactly should this validation happen?

<details>
<summary>Show Hint</summary>

Before or after the object is fully constructed? What are the implications for exception safety?

</details>

<details>
<summary>Show Answer</summary>

Validation should happen in the constructor's member initialization list or at the very beginning of the constructor body, before any attributes are set. If you throw an exception before the object is fully constructed, the destructor is not called, so no cleanup is needed.

</details>

**Question 2:** When you decrement the grade (remember, 1 is highest), what validation check needs to happen?

<details>
<summary>Show Hint</summary>

If you decrement grade 1, you would get 0. Is 0 valid? What exception should be thrown?

</details>

### 3.3 Implementing Grade Modification

Let's say you have:
```cpp
void incrementGrade() { /* increase grade number */ }
void decrementGrade() { /* decrease grade number */ }
```

**Question 1:** Which direction increases the grade numerically? Which direction improves the grade (moves it closer to 1)?

<details>
<summary>Show Hint</summary>

Re-read the specification: "Remember, since grade 1 is the highest and 150 the lowest, incrementing a grade 3 should result in a grade 2 for the bureaucrat."

</details>

**Question 2:** What's the relationship between the function name and the grade number? Does incrementing mean adding or subtracting?

<details>
<summary>Show Hint</summary>

The grade gets "incremented" semantically (improved), but numerically it might decrease. Confusing, right? That's intentional—this is a good lesson in API design vs. implementation.

</details>

### 3.4 Output Formatting

**Question:** The specification requires overloading the `<<` operator to print:
```
<name>, bureaucrat grade <grade>.
```

Is this a member function or a free function? How do you know?

<details>
<summary>Show Hint</summary>

The left operand of `<<` is the output stream (e.g., `std::cout`), and the right operand is your Bureaucrat. Can you make a member function where the left operand is something you don't control (the stream)?

</details>

<details>
<summary>Show Answer</summary>

It must be a free function (not a member), so your Bureaucrat can be the right operand. Also, to access private attributes, you'll need to declare this function as a `friend` of the Bureaucrat class... but wait! The specification says `friend` is forbidden in most cases. How do you solve this?

</details>

**Challenge Question:** Given that you can't use `friend`, how can you print private attributes?

<details>
<summary>Show Answer</summary>

Use public getters! The `<<` operator can call `getName()` and `getGrade()` to access the data.

</details>

---

## Part 4: Exercise 1 - Introducing Polymorphic Behavior

### 4.1 Understanding the Form Class

**Question 1:** A Form has attributes: name (constant), a signed status (boolean), a signing grade, and an execution grade. All are private. Why are they private instead of protected or public?

<details>
<summary>Show Hint</summary>

Think ahead: Later, you'll create concrete form types (ShrubberyCreationForm, RobotomyRequestForm, etc.). Should these subclasses directly modify a form's signing status, or should they go through a public interface?

</details>

**Question 2:** The Form's grades follow the same 1-150 range as Bureaucrat grades. Should Form have the same exception classes, or different ones?

<details>
<summary>Show Hint</summary>

Would it be confusing to catch `Form::GradeTooHighException` when you're working with a Bureaucrat? Is code clarity important?

</details>

### 4.2 The beSigned() Member Function

**Question 1:** The `beSigned()` function takes a Bureaucrat as a parameter and changes the form's status if the bureaucrat's grade is high enough. What does "high enough" mean in terms of the grade numbers?

<details>
<summary>Show Hint</summary>

A lower number is a higher grade. If a form requires grade 50 to sign, can a grade 60 bureaucrat sign it? Can a grade 40 bureaucrat?

</details>

**Question 2:** If the Bureaucrat's grade is too low, throw an exception. Should `beSigned()` ever change the form's status and then throw? Why or why not?

<details>
<summary>Show Hint</summary>

Think about atomicity and consistency. If an exception is thrown, what should the form's state be? What if the caller has code that depends on this?

</details>

### 4.3 Adding signForm() to Bureaucrat

**Question:** You need to add a `signForm(Form& form) const` member function to Bureaucrat. It calls `form.beSigned(*this)` inside a try-catch. What should happen in the catch block?

<details>
<summary>Show Hint</summary>

The output example shows:
- Success: `<bureaucrat> signed <form>`
- Failure: `<bureaucrat> couldn't sign <form> because <reason>.`

How do you get the reason from the exception?

</details>

<details>
<summary>Show Answer</summary>

When you catch an exception as `catch (std::exception& e)`, you can call `e.what()` to get a descriptive message. Your custom exception classes should override the `what()` method to return appropriate error messages.

</details>

---

## Part 5: Exercise 2 - Abstraction and Polymorphism

### 5.1 From Form to AForm (Abstract Form)

**Question 1:** What does it mean for a class to be "abstract"?

<details>
<summary>Show Hint</summary>

Can you create instances of an abstract class? What's the purpose of making a class abstract?

</details>

<details>
<summary>Show Answer</summary>

An abstract class cannot be instantiated directly. It typically contains pure virtual functions that subclasses must implement. The purpose is to define an interface that concrete classes must follow.

</details>

**Question 2:** How do you make a function a "pure virtual function" in C++?

<details>
<summary>Show Hint</summary>

The syntax involves `virtual` and `= 0`. What does the `= 0` mean?

</details>

**Question 3:** The specification says attributes must remain private. So AForm's attributes aren't protected; they're private. If a subclass like ShrubberyCreationForm needs access to the target, what should it do?

<details>
<summary>Show Hint</summary>

Add a public or protected getter in AForm. The subclass calls the getter to retrieve the target.

</details>

### 5.2 Implementing Concrete Form Classes

**Question 1:** Each concrete form (ShrubberyCreationForm, RobotomyRequestForm, PresidentialPardonForm) has different signing/execution grades and different behaviors. Why is inheritance useful here?

<details>
<summary>Show Hint</summary>

Imagine implementing each form as a completely independent class with no inheritance. What code would you repeat?

</details>

**Question 2:** The execute() function needs to check two things:
1. Is the form signed?
2. Does the bureaucrat have a high enough grade?

Where's a good place to put this logic: in the base class or in each concrete class?

<details>
<summary>Show Hint</summary>

The specification hints: "Whether you check the requirements in every concrete class or in the base class (and then call another function to execute the form) is up to you. However, one way is more elegant than the other."

Which is more elegant? Why?

</details>

<details>
<summary>Show Answer</summary>

Put the checks in the base class's `execute()`. This function verifies that the form is signed and the grade is sufficient, then calls a protected pure virtual function (something like `executeAction()`) that each subclass implements. This avoids code duplication and makes the validation logic consistent.

</details>

### 5.3 File I/O and Randomization

**ShrubberyCreationForm Question:** This form creates a file named `<target>_shrubbery` with ASCII trees. What header do you need to include for file operations?

<details>
<summary>Show Hint</summary>

C++ file I/O uses streams, specifically `std::ofstream`. What header do you include?

</details>

**RobotomyRequestForm Question:** This form must succeed 50% of the time. How can you generate a random decision?

<details>
<summary>Show Hint</summary>

You'll need to seed and use `rand()`. What header does that come from? Should you seed it once (where?) or every time?

</details>

<details>
<summary>Show Answer</summary>

Include `<cstdlib>` for `rand()`. Seed the random number generator once, typically in `main()`, using `std::srand(std::time(0))`. Then use `rand() % 2` to get 0 or 1, determining success or failure.

</details>

### 5.4 Bureaucrat's executeForm() Member Function

**Question:** Add `executeForm(AForm const& form) const` to Bureaucrat. It tries to execute the form. What exceptions might be thrown?

<details>
<summary>Show Hint</summary>

The form's `execute()` function might throw exceptions if it's not signed or the grade is too low. What else might go wrong (e.g., in RobotomyRequestForm's file creation)?

</details>

**Question:** Should executeForm() catch all exceptions or let some propagate?

<details>
<summary>Show Hint</summary>

The output example shows:
- Success: `<bureaucrat> executed <form>`
- Failure: an explicit error message

What should `executeForm()` catch, and what should it print?

</details>

---

## Part 6: Exercise 3 - Polymorphic Object Creation

### 6.1 Understanding the Intern Class

**Question 1:** An Intern has no name, grade, or unique characteristics. What's its only purpose?

<details>
<summary>Show Hint</summary>

The `makeForm()` function. It takes two strings: a form name and a target. What does it return?

</details>

**Question 2:** The Intern's `makeForm()` returns a pointer to `AForm`. Why a pointer instead of a reference or a value?

<details>
<summary>Show Hint</summary>

Who owns the memory? How long should the object live? What happens if the caller wants to pass the form around or store it?

</details>

<details>
<summary>Show Answer</summary>

The caller becomes responsible for deleting the pointer. This is because the Intern creates new objects of varying types (ShrubberyCreationForm, RobotomyRequestForm, etc.), and the caller needs to manage the lifetime of these dynamically allocated objects.

</details>

### 6.2 Implementing makeForm()

**Question 1:** The function takes a form name (e.g., "robotomy request") and creates the corresponding form type. The naive approach is a long if/else chain. Why would this be rejected during evaluation?

<details>
<summary>Show Hint</summary>

Re-read the specification: "You must avoid unreadable and messy solutions, such as using an excessive if/else if/else structure. This kind of approach will not be accepted during the evaluation process."

</details>

**Question 2:** What's a cleaner design pattern for this "factory" behavior?

<details>
<summary>Show Hint</summary>

Think about how you could use a data structure (like an array or map... oh wait, you can't use STL containers yet!) to map form names to creation logic.

</details>

<details>
<summary>Show Answer</summary>

One approach is to use an array of structs that pair form names with function pointers. Another is to use a switch statement on a hashed value or enum. The key is that it should be maintainable and clear, not a long chain of if/else blocks.

</details>

**Question 3:** The output should be something like: `Intern creates <form>`. But what if the form name is invalid?

<details>
<summary>Show Hint</summary>

Print an explicit error message. Should you throw an exception or just print and return nullptr?

</details>

---

## Part 7: Design Principles and Memory Management

### 7.1 Orthodox Canonical Form

**Question 1:** Why does the specification require Orthodox Canonical Form for most classes?

<details>
<summary>Show Hint</summary>

What happens if you don't define a copy constructor? What happens if you don't define a destructor for a class that uses `new`?

</details>

<details>
<summary>Show Answer</summary>

The compiler generates default versions of these special member functions. For classes that manage resources (like dynamically allocated memory), the defaults can cause issues: shallow copies, dangling pointers, or double-deletion. By explicitly defining them, you control resource management.

</details>

**Question 2:** Intern has no attributes but still inherits from some implicit base. Do you need to define all four functions for Intern, or can you simplify?

<details>
<summary>Show Hint</summary>

If Intern has no dynamic resources, what's the risk of using compiler-generated defaults?

</details>

### 7.2 Memory Management and Exceptions

**Question 1:** In the Bureaucrat's or Intern's code, when you use `new`, you're responsible for calling `delete`. If an exception is thrown after `new` but before the caller stores the pointer, what happens?

<details>
<summary>Show Hint</summary>

Memory leak! This is a classic exception safety issue.

</details>

**Question 2:** In Intern::makeForm(), you create forms with `new`. Should you worry about exception safety here?

<details>
<summary>Show Hint</summary>

If the AForm constructor throws (unlikely, but possible), the memory is leaked. How can you avoid this?

</details>

<details>
<summary>Show Answer</summary>

One approach: after `new`, immediately assign to a temporary variable or use a smart pointer (if available). However, since you're limited to C++98 and can't use STL containers (and smart pointers come from `<memory>`), you might be okay with simple `new` for this exercise, but it's something to think about.

</details>

---

## Part 8: Const Correctness

### 8.1 Why Const Matters

**Question 1:** Several functions are marked `const` (e.g., `Bureaucrat::getName() const`). What does `const` promise?

<details>
<summary>Show Hint</summary>

A const member function cannot modify the object's state. If you call a non-const member function on a const object, what happens?

</details>

**Question 2:** In Exercise 2, the `execute()` function is `execute(Bureaucrat const& executor) const`. Why both consts?

<details>
<summary>Show Hint</summary>

The first `const` means the executor parameter won't be modified. The second `const` (after the parameter list) means the form object won't be modified either. Why is this important for an "execute" operation that changes whether a form is signed?

</details>

<details>
<summary>Show Answer</summary>

Actually, the form's state might change (e.g., it might be marked as signed or executed internally, or an action is performed). But from the caller's perspective, the form object itself isn't modified—the operation is virtual/polymorphic and might have side effects outside the object. The point is that you can call `execute()` on a const form reference safely.

</details>

---

## Part 9: Testing and Validation

### 9.1 Designing Your Tests

**Question 1:** For the Bureaucrat class, what are the critical behaviors you should test?

<details>
<summary>Show Hint</summary>

- Valid construction
- Invalid construction (grade too high, grade too low)
- Increment/decrement operations
- Boundary conditions (grades 1 and 150)
- Exception catching

</details>

**Question 2:** For Forms, what additional scenarios should you test?

<details>
<summary>Show Hint</summary>

- Creating forms with invalid grades
- Having a Bureaucrat sign a form they can't
- Having a Bureaucrat execute a signed vs. unsigned form
- Executing with insufficient grade

</details>

**Question 3:** For the Intern, what should you test?

<details>
<summary>Show Hint</summary>

- Creating valid forms
- Attempting to create an invalid form name
- Verifying the created forms work correctly

</details>

### 9.2 Writing Clean Test Code

**Question:** Should your `main()` function test all edge cases, or would separating tests into helper functions be cleaner?

<details>
<summary>Show Hint</summary>

Think about readability and maintainability. If `main()` is 200 lines of test code, is it clear what you're testing?

</details>

---

## Part 10: Common Pitfalls and Solutions

### 10.1 Exception Throwing in Constructors

**Gotcha:** If the constructor throws before the object is fully initialized, the destructor is *not* called. But if the constructor throws *after* other objects are initialized, their destructors *are* called. Understand this!

**Question:** In Bureaucrat's constructor, if you validate the grade and throw an exception, should you do this before or after initializing the name?

<details>
<summary>Show Hint</summary>

Initialization order matters. The member initialization list runs in order. If you throw during validation, what state is the object in?

</details>

### 10.2 Private vs. Protected Attributes

**Gotcha:** The specification says attributes are private, not protected. Subclasses can't access them directly.

**Question:** If ShrubberyCreationForm needs the form's target, what do you do?

<details>
<summary>Show Hint</summary>

Add a public or protected getter in AForm, like `getTarget() const`. Then ShrubberyCreationForm calls this getter.

</details>

### 10.3 Const References and Casting

**Gotcha:** In Exercise 2, `execute()` takes `Bureaucrat const&`. You might need to call non-const member functions (like `getGrade()`). But wait—getters should be const! So this isn't a problem.

**Question:** If a function parameter is a const reference to a Bureaucrat, what member functions can you call on it?

<details>
<summary>Show Hint</summary>

Only const member functions. Non-const member functions (like `incrementGrade()`) cannot be called on a const reference. This is actually good—it prevents the function from modifying the Bureaucrat unexpectedly.

</details>

---

## Part 11: Putting It All Together - A Complete Example

Now, let's walk through a simplified version of what Exercise 0 might look like:

**Question 1:** What headers do you need at the top of Bureaucrat.hpp?

<details>
<summary>Show Hint</summary>

You need `<iostream>` for output, `<string>` for the name, and `<exception>` for `std::exception`.

</details>

**Question 2:** In Bureaucrat.hpp, should you define the exception classes inside the Bureaucrat class (nested) or outside?

<details>
<summary>Show Hint</summary>

Nested exception classes can be referenced as `Bureaucrat::GradeTooHighException`. This is clear and avoids namespace pollution. It's a common pattern.

</details>

**Question 3:** In your Bureaucrat.cpp, when you implement the constructor, what's the first thing you check?

<details>
<summary>Show Hint</summary>

Grade validity. Throw the appropriate exception if it's out of range.

</details>

---

## Part 12: Final Reflection Questions

Before moving on to testing and implementation, ask yourself:

1. **Conceptual Understanding:** Why does C++ provide exception handling if we had error codes in C? What fundamental advantage does it provide?

2. **Design Thinking:** Why does the specification forbid long if/else chains for form creation? What does this teach you about writing maintainable code?

3. **Practice:** In your own words, explain the relationship between Bureaucrat grades and the functions that modify them. Why is the naming "backward"?

4. **Application:** When would you use abstract classes in a real project? Can you think of examples?

5. **Exploration:** The specification forbids `using namespace std;` and `friend`. How do these restrictions improve your code?

---

## Part 13: Implementation Checklist

As you implement, verify each step:

- [ ] Exception classes inherit from `std::exception`
- [ ] All custom exception `what()` methods are implemented
- [ ] Bureaucrat has constant name and grade in range [1, 150]
- [ ] Grade increment/decrement logic is correct (remember the direction!)
- [ ] All classes follow Orthodox Canonical Form (except exceptions)
- [ ] Getters are const member functions
- [ ] Attributes are private
- [ ] Include guards are in place
- [ ] No memory leaks (use `new` and `delete` correctly)
- [ ] Output formatting matches specifications exactly
- [ ] Tests cover edge cases and exception scenarios

---

## Conclusion

This module teaches you that **C++ is fundamentally different from C**. Instead of checking error codes, you throw exceptions that can be caught and handled. This requires careful design, understanding of object lifetime, and clear thinking about error conditions.

The progression from Bureaucrat → Form → AForm → Concrete Forms → Intern teaches you:
1. **Exception handling** (Exercise 0)
2. **Inheritance and polymorphism** (Exercise 1-2)
3. **Abstract classes and virtual functions** (Exercise 2)
4. **Factory patterns** (Exercise 3)

Work through each exercise methodically, test thoroughly, and don't be afraid to refactor. The learning process is more important than the final result.