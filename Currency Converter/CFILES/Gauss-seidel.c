#include <stdio.h>
#include <math.h>

// Functions to update values based on the latest Gauss-Seidel iteration
double equation1(double x2, double x3) { return (21 - x2 - 10 * x3) / -4; }
double equation2(double x1, double x3) { return (14 - 5 * x1 - x3) / -1; }
double equation3(double x1, double x2) { return (-7 - 2 * x1 - 8 * x2) / -1; }

int main()
{
    double x1, x2, x3;
    int max;

    // Taking input for initial guesses
    printf("Enter initial values of x1, x2, x3: ");
    scanf("%lf %lf %lf", &x1, &x2, &x3);

    // Taking input for maximum iterations
    printf("Enter the max iterations: ");
    scanf("%d", &max);

    // Gauss-Seidel Iteration
    for (int i = 1; i <= max; i++)
    {
        x1 = equation1(x2, x3);
        x2 = equation2(x1, x3); // Uses the updated x1
        x3 = equation3(x1, x2); // Uses the updated x1 and x2

        printf("Iteration %d: x1 = %lf, x2 = %lf, x3 = %lf\n", i, x1, x2, x3);
    }

    // Printing approximate solution
    printf("\nApproximate roots: x1 = %lf, x2 = %lf, x3 = %lf\n", x1, x2, x3);
    return 0;
}
