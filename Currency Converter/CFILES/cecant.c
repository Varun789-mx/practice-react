#include <stdio.h>
#include <math.h>

double fun(double x)
{
    return (x * x * x) - (5 * x) + 1;
}

int main()
{
    double x1, x2, x3;
    int count;
    printf("Enter the first itteration of [x1 and x2]:");
    scanf("%lf %lf", &x1, &x2);
    printf("Enter the number of itterarions : ");
    scanf("%d", &count);
    int itteration = 1;
    while (itteration <= count)
    {
        x3 = (x1 * fun(x2) - x2 * fun(x1)) / (fun(x2) - fun(x1));
        printf("Itteraton : %d  x1:%.2lf  x2:%lf  x3:%.2lf \n", itteration, x1, x2, x3);
        x1 = x2;
        x2 = x3;

        itteration++;
    }
    printf("Approximate root is : %.2lf", x3);
    return 0;
}
