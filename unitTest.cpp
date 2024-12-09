#include <cassert>
#include <cmath>
#include "FuncA.h" 

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
