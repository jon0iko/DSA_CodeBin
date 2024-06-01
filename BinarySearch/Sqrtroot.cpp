#include <iostream>

// Function to find the square root of a number using binary search
double squareRoot(double x) {
    if (x < 0) return -1; // Negative numbers don't have real square roots

    double left = 0.0;
    double right = x;
    double eps = 1e-6; // Set a small value for precision

    while (right - left > eps) {
        double mid = left + (right - left) / 2.0;
        double midSquare = mid * mid;

        if (midSquare < x)
            left = mid;
        else
            right = mid;
    }

    return left; // Return the left boundary as the square root
}

int main() {
    double x = 16.0; // Number to find the square root of

    double root = squareRoot(x);
    std::cout << "The square root of " << x << " is: " << root << std::endl;

    return 0;
}
