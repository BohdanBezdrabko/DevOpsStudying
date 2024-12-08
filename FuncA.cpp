#include "FuncA.h"
#include <cmath> // For trigonometric function
long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}
int Function::FuncA(double x) {
    double sum = 0.0;

    for (int n = 0; n < 3; ++n) {
        // Calculate factorials
        long long factorial2n = factorial(2 * n);
        long long factorialN = factorial(n);

        // Calculate the term
        double term = pow(-1, n) * factorial2n / (pow(4, n) * factorialN * factorialN) * pow(x, n);

        // Add term to the sum
        sum += term;
    }

    return sum;
} 
