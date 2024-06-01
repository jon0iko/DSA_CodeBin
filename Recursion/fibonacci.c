#include <stdio.h>

void printFibonacciSeries(int n) {
    int prevNum = 0;
    int currentNum = 1;

    printf("Fibonacci Series up to %d terms: ", n);

    for (int i = 0; i < n; i++) {
        printf("%d ", prevNum);
        int nextNum = prevNum + currentNum;
        prevNum = currentNum;
        currentNum = nextNum;
    }

    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of terms in the Fibonacci Series: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input. Please enter a positive number.\n");
        return 1;
    }

    printFibonacciSeries(n);

    return 0;
}
