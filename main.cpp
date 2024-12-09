#include <iostream>
#include "FuncA.h"

int main() {
    Function obj;

    // Перевірка результатів
    double x = 0.1;
    int n1 = 3, n2 = 7;

    std::cout << "FuncA calculation result (x = " << x << ", n = " << n1 << "): " << obj.FuncA(x, n1) << std::endl;
    std::cout << "FuncA calculation result (x = " << x << ", n = " << n2 << "): " << obj.FuncA(x, n2) << std::endl;

    return 0;
}
