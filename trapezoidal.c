#include <stdio.h>
#include <math.h>

double fx(double x)
{
    double y = sqrt(1 / (1 + pow(x, 2)));
    return y;
}

int main()
{
    int n;
    printf("Enter number of sub-intervlas(any) = ");
    scanf("%d", &n);
    double x[n + 1], y[n + 1];
    double a, b;
    printf("Enter lower-limit a & upper-limit b = ");
    scanf("%lf%lf", &a, &b);
    double h = (b - a) / (double)n;
    double sum = 0;
    for (int i = 0; i < n + 1; i++)
    {
        x[i] = a;
        y[i] = fx(x[i]);
        a += h;
    }
    for (int i = 1; i < n; i++)
    {
        sum += y[i];
    }
    double integration = h * (((y[0] + y[n]) / 2) + sum);
    printf("Integration = %lf", integration);
    return 0;
}