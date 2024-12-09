#include "FuncA.h"
#include <cmath> // Для математичних функцій

// Функція для обчислення факторіалу
long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // Факторіал 0 і 1 дорівнює 1
    }
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Реалізація методу FuncA
double Function::FuncA(double x, int n) {
    double sum = 0.0;

    for (int i = 0; i < n; ++i) {
        // Обчислення факторіалів
        long long factorial2i = factorial(2 * i); // 2i!
        long long factorialI = factorial(i);     // i!

        // Обчислення члена суми
        double term = pow(-1, i) * factorial2i / (pow(4, i) * pow(factorialI, 2)) * pow(x, 2 * i);

        // Додавання члена до суми
        sum += term;
    }

    return sum;
}
