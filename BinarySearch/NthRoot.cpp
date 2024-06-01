#include <iostream>

// Function to find the nth root of a number using binary search
double nthRoot(double x, int n) {
    double left = 0.0;
    double right = x;
    double eps = 1e-6; // Set a small value for precision

    while (right - left > eps) {
        double mid = left + (right - left) / 2.0;
        double midToNth = 1.0;
        for (int i = 0; i < n; ++i)
            midToNth *= mid;

        if (midToNth < x)
            left = mid;
        else
            right = mid;
    }

    return left; // Return the left boundary as the nth root
}

int main() {
    double x = 64.0; // Number to find the nth root of
    int n = 3;       // Value of n for nth root

    double root = nthRoot(x, n);
    std::cout << "The " << n << "th root of " << x << " is: " << root << std::endl;

    return 0;
}
