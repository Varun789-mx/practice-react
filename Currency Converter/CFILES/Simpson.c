#include<stdio.h>
#include<math.h>

// Function to integrate
double fun(double x) {
    return 1.0 / (1.0 + x);
}

int main() {
    double a = 0.0, b = 1.0; // Lower and upper limits
    int n = 2;              // Number of intervals (must be even)

    // Ensure that n is even
    if (n % 2 != 0) {
        printf("Error: Number of intervals (n) must be even.\n");
        return -1;
    }

    double h = (b - a) / n; // Step size
    double x[n+1], y[n+1]; // Arrays for x and y values

    // Generate x and y values
    double p = a;
    for (int i = 0; i <= n; i++) {
        x[i] = p;
        y[i] = fun(p);
        p = p + h;
    }

    // Print x and y values
    printf("\nx: ");
    for (int i = 0; i <= n; i++) {
        printf("%lf ", x[i]);
    }
    printf("\ny: ");
    for (int i = 0; i <= n; i++) {
        printf("%lf ", y[i]);
    }

    // Simpson's Rule Calculation
    double sum = y[0] + y[n]; // First and last terms
    for (int i = 1; i < n; i++) { // Interior points
        if (i % 2 == 0) {
            sum += 2 * y[i]; // Even indices
        } else {
            sum += 4 * y[i]; // Odd indices
        }
    }
    sum = (h / 3.0) * sum; // Final result

    // Print the result
    printf("\nThe final result is: %lf\n", sum);

    return 0;
}
