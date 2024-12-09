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

    // Простий тест: x = 0, n = 1
    assert(std::abs(func.FuncA(0, 1) - 1.0) < 1e-9);

    // Простий тест: x = 1, n = 1
    assert(std::abs(func.FuncA(1, 1) - 1.0) < 1e-9);
}
