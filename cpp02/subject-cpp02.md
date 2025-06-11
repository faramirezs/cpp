# C++ Module 02 Summary  
**Ad-hoc polymorphism, operator overloading, and Orthodox Canonical class form**

---

## 📚 General Rules  
- **Compilation**:  
  `c++ -Wall -Wextra -Werror -std=c++98`  
- **Orthodox Canonical Form** required for all classes (unless specified otherwise):  
  - Default constructor  
  - Copy constructor  
  - Copy assignment operator  
  - Destructor  
- **Forbidden**:  
  - `using namespace <ns_name>`  
  - `friend` keyword  
  - STL containers/algorithms (until Modules 08-09)  
  - External libraries (C++11/Boost)  
  - `sprintf()`, `*alloc()`, `free()`  
- **File Structure**:  
  - Class declaration in `.hpp`/`.h`  
  - Implementation in `.cpp`  
  - Include guards mandatory  
- **Naming**:  
  - Classes: `UpperCamelCase` (e.g., `Fixed.hpp`)  
  - Directories: `ex00`, `ex01`, etc.  

---

## 🧩 Exercises  

### Exercise 00: My First Class in Orthodox Canonical Form  
**Goal**: Implement a `Fixed` class for fixed-point numbers.  
**Files**: `Makefile`, `main.cpp`, `Fixed.hpp`, `Fixed.cpp`  
**Class Structure**:  
```cpp
class Fixed {
private:
    int _value;  // Raw fixed-point value
    static const int _fractionalBits = 8;  // Always 8 fractional bits
public:
    Fixed();              // Default constructor (value=0)
    Fixed(const Fixed&);  // Copy constructor
    Fixed& operator=(const Fixed&);  // Copy assignment operator
    ~Fixed();             // Destructor
    int getRawBits() const;    // Return raw value
    void setRawBits(int raw);  // Set raw value
};
```  
**Output Requirement**:  
- Trace constructor/destructor/operator calls during operations.  
- Example output:  
  ```bash
  Default constructor called
  Copy constructor called
  getRawBits member function called
  ...
  ```

---

### Exercise 01: Enhanced Fixed-Point Class  
**Goal**: Add constructors and conversions for integers/floats.  
**Files**: Same as Exercise 00 + `roundf` allowed.  
**Additions to `Fixed`**:  
```cpp
Fixed(const int integer);        // Convert int → fixed-point
Fixed(const float floating);     // Convert float → fixed-point
float toFloat() const;           // Convert → float
int toInt() const;               // Convert → int
std::ostream& operator<<(std::ostream& os, const Fixed& obj);  // Overload <<
```  
**Key Logic**:  
- Integer → Fixed: `value = integer << _fractionalBits`  
- Float → Fixed: `value = roundf(floating * (1 << _fractionalBits))`  
- `toFloat()`: `return (float)value / (1 << _fractionalBits)`  

**Test Output**:  
```bash
Float constructor called
a is 1234.43
b is 10
...
a is 1234 as integer
```

---

### Exercise 02: Operator Overloading  
**Goal**: Overload operators for comparisons, arithmetic, and increments.  
**Files**: Same as Exercise 01.  
**Operators to Overload**:  
- **Comparisons**: `>`, `<`, `>=`, `<=`, `==`, `!=`  
- **Arithmetic**: `+`, `-`, `*`, `/`  
- **Increment/Decrement**:  
  - Pre: `Fixed& operator++()`  
  - Post: `Fixed operator++(int)`  
  - Pre-decrement: `Fixed& operator--()`  
  - Post-decrement: `Fixed operator--(int)`  
- **Static Functions**:  
  ```cpp
  static Fixed& min(Fixed& a, Fixed& b);
  static const Fixed& min(const Fixed& a, const Fixed& b);
  static Fixed& max(Fixed& a, Fixed& b);
  static const Fixed& max(const Fixed& a, const Fixed& b);
  ```  
**Increment Logic**:  
- Smallest ε = `1 / (1 << 8)` = `0.00390625`  
- Pre-increment: `_value += 1` (ε = `1` in raw value)  

**Test Output**:  
```bash
0
0.00390625
0.00390625
10.1016
10.1016
```

---

### Exercise 03: Point-in-Triangle Check (BSP)  
**Goal**: Implement `bsp()` to check if a point is inside a triangle.  
**Files**: `Makefile`, `main.cpp`, `Fixed.hpp`, `Fixed.cpp`, `Point.hpp`, `Point.cpp`, `bsp.cpp`  
**Class `Point`**:  
```cpp
class Point {
private:
    const Fixed _x;  // Fixed-point coordinates
    const Fixed _y;
public:
    Point();                       // Default: (0, 0)
    Point(const float x, const float y);  // Initialize with floats
    Point(const Point&);           // Copy constructor
    Point& operator=(const Point&); // Copy assignment
    ~Point();
    // Getters for _x/_y (optional but useful)
};
```  
**Function**:  
```cpp
bool bsp(Point const a, Point const b, Point const c, Point const point);
```  
**Rules**:  
- Returns `true` only if `point` is strictly inside the triangle.  
- Returns `false` if on a vertex/edge.  
- **Algorithm**: Use barycentric coordinates or cross-product sign checks.  

---

## 📤 Submission  
- Submit per exercise directory: `ex00/`, `ex01/`, etc.  
- Mandatory files for each exercise specified in the PDF.  
- Peer evaluation assesses:  
  - Correct Orthodox Canonical Form  
  - No memory leaks  
  - Adherence to output requirements  
  - Proper operator overloading logic  

> **Note**: Exercise 03 is optional for passing the module.  

---  
✅ **Key Takeaway**: Master fixed-point arithmetic, operator overloading, and canonical class design while adhering to strict C++98 standards.