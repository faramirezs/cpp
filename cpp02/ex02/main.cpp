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

    std::cout << "=== Static Min/Max Functions ===" << std::endl;
    
    // Test with non-const Fixed objects
    Fixed x(5.5f);
    Fixed y(3.2f);
    std::cout << "x = " << x.toFloat() << ", y = " << y.toFloat() << std::endl;
    
    // Test min with non-const references
    Fixed& minResult = Fixed::min(x, y);
    std::cout << "Fixed::min(x, y) = " << minResult.toFloat() << std::endl;
    
    // Test max with non-const references  
    Fixed& maxResult = Fixed::max(x, y);
    std::cout << "Fixed::max(x, y) = " << maxResult.toFloat() << std::endl;
    
    // Test with const Fixed objects
    const Fixed cx(7.8f);
    const Fixed cy(9.1f);
    std::cout << "const cx = " << cx.toFloat() << ", const cy = " << cy.toFloat() << std::endl;
    
    // Test min with const references
    Fixed& minConstResult = Fixed::min(cx, cy);
    std::cout << "Fixed::min(const cx, const cy) = " << minConstResult.toFloat() << std::endl;
    
    // Test max with const references
    Fixed& maxConstResult = Fixed::max(cx, cy);
    std::cout << "Fixed::max(const cx, const cy) = " << maxConstResult.toFloat() << std::endl;
    
    // Test edge cases - equal values
    Fixed equal1(42.0f);
    Fixed equal2(42.0f);
    std::cout << "equal1 = " << equal1.toFloat() << ", equal2 = " << equal2.toFloat() << std::endl;
    std::cout << "Fixed::min(equal1, equal2) = " << Fixed::min(equal1, equal2).toFloat() << std::endl;
    std::cout << "Fixed::max(equal1, equal2) = " << Fixed::max(equal1, equal2).toFloat() << std::endl;

    std::cout << "=== Destructors (will be called automatically) ===" << std::endl;

    return 0;
}