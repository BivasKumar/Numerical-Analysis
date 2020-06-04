#include <stdio.h>
#include <math.h>

double f(double x)
{
    return 2 * x - 3 * cos(x) - 1.85;
}

void bisection(double a, double b, double EPSILON)
{
    if (f(a) * f(b) >= 0)
    {
        printf("\nroot can't lie between %lf & %lf", a, b);
        return;
    }
    double c;
    int ITER = 0;
    while (fabs(a - b) >= EPSILON)
    {
        ITER++;
        c = (a + b) / 2;
        if (f(c) == (double)0)
        {
            break;
        }
        else if (f(a) * f(c) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    }
    printf("\nroot using Bisection Method = %lf", c);
    printf("\niteration count = %d", ITER);
}

void regulaFalsi(double a, double b, double EPSILON)
{
    if (f(a) * f(b) >= 0)
    {
        printf("\nroot can't lie between %lf & %lf", a, b);
    }
    double c;
    int ITER = 0;
    while (fabs(a - b) >= EPSILON)
    {
        ITER++;
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        if (f(c) == (double)0)
        {
            break;
        }
        else if (f(a) * f(c) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    }
    printf("\nroot using Reugla-Falsi Method = %lf", c);
    printf("\niteration count = %d", ITER);
}

int main()
{
    double a, b, e;
    printf("\ninterval = ");
    scanf("%lf%lf", &a, &b);
    printf("\nerror threshold = ");
    scanf("%lf", &e);
    bisection(a, b, e);
    regulaFalsi(a, b, e);
    return 0;
}