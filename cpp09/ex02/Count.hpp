#pragma once

template<typename T>
class CountingLess {
private:
    int& count;  // Reference to external counter

public:
    CountingLess(int& c) : count(c) {}
    bool operator()(const T& a, const T& b) const {
        ++count;
        return a < b;
    }
    int getCount() const { return count; }
};