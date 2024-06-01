#include <stdio.h>
#include <math.h>

// Function to calculate the value of the cubic equation at a given x
double cubicEquation(double a, double b, double c, double d, double x) {
    return a * pow(x, 3) + b * pow(x, 2) + c * x + d;
}

// Function to find the root of a cubic equation using the bisection method
double findRoot(double a, double b, double c, double d, double start, double end, double tolerance) {
    double mid = (start + end) / 2.0; // Initial midpoint

    while (fabs(end - start) > tolerance) {
        mid = (start + end) / 2.0; // Update midpoint
        double f_mid = cubicEquation(a, b, c, d, mid);

        if (f_mid == 0.0) {
            break; // Found root exactly
        } else if (cubicEquation(a, b, c, d, start) * f_mid < 0) {
            end = mid; // Root lies in first half
        } else {
            start = mid; // Root lies in second half
        }
    }

    return mid;
}

int main() {
  //  double a = 1.0, b = -2.0, c = -3.0, d = 2.0; // Coefficients of the cubic equation
    double a,b,c,d;
    scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
    double start = -10.0, end = 10.0; // Range to search for roots
    double tolerance = 0.0001; // Tolerance for bisection method

    // Find one root between start and end
    double root = findRoot(a, b, c, d, start, end, tolerance);

    printf("Root: %.6f\n", root);

    return 0;
}
