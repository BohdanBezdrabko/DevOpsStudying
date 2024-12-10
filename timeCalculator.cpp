#include "timeCalculator.h"
#include "FuncA.h"
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>

int timeCalculator() {
    auto t1 = std::chrono::high_resolution_clock::now();

    Function func;
    std::vector<double> results;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> distr(0.0, 2 * M_PI);

    for (int i = 0; i < 20000; ++i)
        results.push_back(func.FuncA(distr(gen), 10));

    for (int i = 0; i < 4000; ++i)
        std::sort(results.begin(), results.end());

    auto t2 = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
}
