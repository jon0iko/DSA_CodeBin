#include <stdio.h>

#define MAX_SIZE 10

void printMatrix(int n, double matrix[MAX_SIZE][MAX_SIZE + 1])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void solveEchelon(int n, double matrix[MAX_SIZE][MAX_SIZE + 1])
{
    for (int i = 0; i < n; i++)
    {
        // Make the diagonal element 1
        double divisor = matrix[i][i];
        for (int j = i; j <= n; j++)
        {
            matrix[i][j] /= divisor;
        }

        // Make other rows zero in the current column
        for (int j = i + 1; j < n; j++)
        {
            double factor = matrix[j][i];
            for (int k = i; k <= n; k++)
            {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of equations: ");
    scanf("%d", &n);

    double matrix[MAX_SIZE][MAX_SIZE + 1];

    printf("Enter the augmented matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            scanf("%lf", &matrix[i][j]);
        }
    }

    solveEchelon(n, matrix);

    printf("Echelon form:\n");
    printMatrix(n, matrix);
    printf("\n");
    double solution[MAX_SIZE];
    for (int i = n - 1; i >= 0; i--)
    {
        double sum = 0;
        for (int j = i + 1; j < n; j++)
        {
            sum += matrix[i][j] * solution[j];
        }
        solution[i] = (matrix[i][n] - sum) / matrix[i][i];
        printf("x%d = %.2lf\n", i + 1, solution[i]);
    }
    return 0;
}
