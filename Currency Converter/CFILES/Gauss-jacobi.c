#include <stdio.h>
#include <math.h>
double equation1(double x2, double x3) { return (21 - x2 - 10 * x3) / -4; }
double equation2(double x1, double x3) { return (14 - 5 * x1 - x3) / -1; }
double equation3(double x1, double x2)
{
    return (-7 - 2 * x1 - x2) / -1;
}

int main()
{
    double x1, x2, x3;
    int max;
    printf("\nEnter the initial roots:");
    scanf("%lf %lf %lf", &x1, &x2, &x3);
    printf("\nEnter the no. of itterations: ");
    scanf("%d", &max);

    for (int i = 0; i < max; i++)
    {
        double newx1 = equation1(x2, x3);
        double newx2 = equation2(x1, x3);
        double newx3 = equation3(x1, x2);

        x1 = newx1;
        x2 = newx2;
        x3 = newx3;
        printf("Itteration: %d x1:%lf x2:%lf x3:%lf\n", i, newx1, newx2, newx3);
    }
    printf("Approximate roots :x1:%lf x2:%lf x3:%lf\n", x1, x2, x3);

    return 0;
}
