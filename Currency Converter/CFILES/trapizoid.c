#include<stdio.h>
#include<math.h>

// Function to integrate
double fun(double x) {
    return pow(x, 2) + x + 2;
}

int main() {
    double a = 2.0; // Lower limit
    double b = 6.0; // Upper limit
    double h = 1.0; // Step size
    int n = ceil((b - a) / h); // Number of intervals

    double x[n+1], y[n+1]; // Arrays for x and y values

    // Generate x and y values
    double p = a;
    for(int i = 0; i <= n; i++) {
        x[i] = p;
        y[i] = fun(p);
        p = p + h;
    }

    // Print x and y values
    printf("\nx: ");
    for(int i = 0; i <= n; i++) {
        printf("%lf ", x[i]);
    }
    printf("\ny: ");
    for(int i = 0; i <= n; i++) {
        printf("%lf ", y[i]);
    }

    // Trapezoidal rule calculation
    double sum = y[0] + y[n]; // Add the first and last terms
    for(int i = 1; i < n; i++) { // Interior points
        sum += 2 * y[i];
    }
    sum = (h / 2.0) * sum; // Final result

    // Print result
    printf("\nApproximate integral value: %lf\n", sum);

    return 0;
}
