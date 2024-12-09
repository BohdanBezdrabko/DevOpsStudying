#include <cassert>
#include <cmath>
#include "FuncA.h" 

// Тест для функції factorial
void test_factorial() {
    assert(factorial(0) == 1);
    assert(factorial(1) == 1);
    assert(factorial(2) == 2);
    assert(factorial(3) == 6);
}

// Тест для функції FuncA
void test_FuncA() {
    Function func;

    assert(std::abs(func.FuncA(0, 1) - 1.0) < 1e-9);
    assert(std::abs(func.FuncA(0, 5) - 1.0) < 1e-9);
    assert(std::abs(func.FuncA(1, 2) - 0.75) < 1e-9); 
}

int main() {
    test_factorial();
    test_FuncA();
    return 0;
}
