# include "Fixed.hpp"

int main() {

    std::cout << "=== Constructors ===" << std::endl;
    Fixed a;
    Fixed b(10);
    Fixed c(42.42f);
    Fixed d = b;

    std::cout << "=== Assignment ===" << std::endl;
    Fixed e;
    e = c;

    std::cout << "=== Get/Set Raw Bits ===" << std::endl;
    std::cout << "e raw bits: " << e.getRawBits() << std::endl;
    e.setRawBits(123456);
    std::cout << "e raw bits after set: " << e.getRawBits() << std::endl;

    std::cout << "=== toFloat / toInt ===" << std::endl;
    std::cout << "e toFloat: " << e.toFloat() << std::endl;
    std::cout << "e toInt: " << e.toInt() << std::endl;

    std::cout << "=== Comparison Operators ===" << std::endl;
    std::cout << "b == d: " << (b == d) << std::endl;
    std::cout << "b != c: " << (b != c) << std::endl;
    std::cout << "b < c: " << (b < c) << std::endl;
    std::cout << "b > c: " << (b > c) << std::endl;
    std::cout << "b <= d: " << (b <= d) << std::endl;
    std::cout << "b >= d: " << (b >= d) << std::endl;

    std::cout << "=== Arithmetic Operators ===" << std::endl;
    Fixed sum = b + c;
    Fixed diff = b - c;
    Fixed prod = b * c;
    Fixed quot = b / c;
    std::cout << "b + c = " << sum.toFloat() << std::endl;
    std::cout << "b - c = " << diff.toFloat() << std::endl;
    std::cout << "b * c = " << prod.toFloat() << std::endl;
    std::cout << "b / c = " << quot.toFloat() << std::endl;

    std::cout << "=== Increment/Decrement ===" << std::endl;
    Fixed f;
    std::cout << "f = " << f.toFloat() << std::endl;
    std::cout << "++f = " << (++f).toFloat() << std::endl;
    std::cout << "f++ = " << (f++).toFloat() << std::endl;
    std::cout << "f = " << f.toFloat() << std::endl;
    std::cout << "--f = " << (--f).toFloat() << std::endl;
    std::cout << "f-- = " << (f--).toFloat() << std::endl;
    std::cout << "f = " << f.toFloat() << std::endl;

    std::cout << "=== Destructors (will be called automatically) ===" << std::endl;

    return 0;
}