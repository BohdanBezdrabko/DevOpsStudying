#include "FuncA.h"
#include "timeCalculator.h"
#include <iostream>
#include <cassert>
#include <cmath>

void test_FuncA() {
    Function func;

    // Простий тест
    assert(std::abs(func.FuncA(0, 1) - 1.0) < 1e-9);
    assert(std::abs(func.FuncA(1, 1) - 1.0) < 1e-9);

    // Перевірка часу виконання
    int execTime = timeCalculator();
    assert(execTime >= 500 && execTime <= 2000);
    std::cout << "Execution time (ms): " << execTime << std::endl;

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    test_FuncA();
    return 0;
}
