#include <stdio.h>
#include <math.h>

#define f(x, y) pow(x, 3) + y

int main()
{
    int n;
    printf("Enter step-size = ");
    scanf("%d", &n);
    double x[n + 1], y[n + 1];
    double x0, y0, xn;
    printf("Enter x0 and y0 = ");
    scanf("%lf%lf", &x0, &y0);
    printf("Enter xn = ");
    scanf("%lf", &xn);
    double h = (xn - x0) / (double)n;
    double xi = x0;
    y[0] = y0;
    for (int i = 0; i < n + 1; i++)
    {
        x[i] = xi;
        xi += h;
    }
    int i = 0;
    do
    {
        y[i + 1] = y[i] + (h * (f(x[i], y[i])));
        i++;
    } while (x[i] != xn);
    printf("Value of y for x = %lf is %lf", xn, y[i]);
    return 0;
}