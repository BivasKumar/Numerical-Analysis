#include <stdio.h>
#include <math.h>

double f(double x, double y)
{
    return ((0.5 - x + (double)pow(y, 2)) / ((double)pow(x, 2) + y + 1));
}

double rungeKuttaOrder2(double h, double x0, double y0, double xn)
{
    int n = (xn - x0) / h;
    double x[n + 1], y[n + 1];
    x[0] = x0;
    y[0] = y0;
    double ty;
    ty = y0 + f(x0, y0);
    for (int i = 0; i < n; i++)
    {
        x[i + 1] = x[i] + h;
    }

    for (int i = 0; i < n + 1; i++)
    {
        ty = y[i] + h * f(x[i], y[i]);
        y[i + 1] = y[i] + (h / 2.0) * (f(x[i], y[i]) + f(x[i + 1], ty));
    }
    return y[n + 1];
}

int main()
{
    double y = rungeKuttaOrder2(0.1, 0, 0, 0.6);
    printf("\nO.D.E: dy/dx = (0.5 - x + y^2) / (x^2 + y + 1)");
    printf("\nvalue of y when x = %lf is %lf", 0.6, y);
    return 0;
}