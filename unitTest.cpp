#include <cassert>
#include <cmath>
#include "FuncA.h" // Замініть на шлях до вашого заголовного файлу

// Декларація тестової функції
void test_FuncA();

int main() {
    test_FuncA();
    return 0;
}

// Тест для функції FuncA
void test_FuncA() {
    Function func;

    // Тест: x = 0, n = 1
    assert(std::abs(func.FuncA(0, 1) - 1.0) < 1e-9);

    // Тест: x = 0, n = 5 (результат не змінюється для x = 0)
    assert(std::abs(func.FuncA(0, 5) - 1.0) < 1e-9);

    // Тест: x = 1, n = 2
    assert(std::abs(func.FuncA(1, 2) - 0.75) < 1e-9); // Ручний підрахунок: 1 - 1/4
}
