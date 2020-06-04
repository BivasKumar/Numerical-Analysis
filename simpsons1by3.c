#include <stdio.h>
#include <math.h>

double fx(double x)
{
    double y = sqrt(5 * pow(x, 2) + 4 * x + 1);
    return y;
}

int main()
{
    int n;
    printf("Enter number of sub-intervlas(even) = ");
    scanf("%d", &n);
    double x[n + 1], y[n + 1];
    double a, b;
    printf("Enter lower-limit a & upper-limit b = ");
    scanf("%lf%lf", &a, &b);
    double h = (b - a) / (double)n;
    double sum_odd = 0, sum_even = 0;
    for (int i = 0; i < n + 1; i++)
    {
        x[i] = a;
        y[i] = fx(x[i]);
        a += h;
    }
    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 0)
            sum_even += y[i];
        else
            sum_odd += y[i];
    }
    double integration = (h / 3) * ((y[0] + y[n]) + (4 * sum_odd) + (2 * sum_even));
    printf("Integration = %lf", integration);
    return 0;
}