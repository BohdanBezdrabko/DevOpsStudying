#include "FuncA.h"
#include <cmath> // For trigonometric function
// Function to calculate factorial
long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

}
int Function::FuncA(double x, int n) {
    double sum = 0.0;

    for (int i = 0; i < n; ++i) {
        // Calculate factorials
        long long factorial2n = factorial(2 * i);
        long long factorialN = factorial(i);

        // Calculate the term
        double term = pow(-1, i) * factorial2n / (pow(4, i) * factorialN * factorialN) * pow(x, i);

        // Add term to the sum
        sum += term;
    }

    return sum;
} 
