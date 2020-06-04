#include <stdio.h>

double f(double xv, double yv)
{
    return (xv * yv);
}

int main()
{
    double x0, y0;
    printf("Enter value of x0 and y0 = ");
    scanf("%lf%lf", &x0, &y0);
    double h;
    printf("Enter value of h = ");
    scanf("%lf", &h);
    double k1, k2, k3, k4, k;
    int n;
    printf("Enter number of sub-intervals = ");
    scanf("%d", &n);
    double x[n + 1], y[n + 1];
    double xi = 0;
    y[0] = y0;
    for (int i = 0; i < n + 1; i++)
    {
        x[i] = xi;
        xi += h;
    }
    int i = 0;
    double xn;
    printf("Enter value of x = ");
    scanf("%lf", &xn);
    do
    {
        k1 = h * f(x[i], y[i]);
        k2 = h * f((x[i] + (h / 2)), (y[i] + (k1 / 2)));
        k3 = h * f((x[i] + (h / 2)), (y[i] + (k2 / 2)));
        k4 = h * f((x[i] + h), (y[i] + k3));
        k = (k1 + 2 * k2 + 2 * k3 + k4) * ((double)1 / (double)6);
        y[i + 1] = y[i] + k;
        i++;
    } while (x[i] != xn);
    printf("y = %lf when x = %lf", y[i], x[i]);
    return 0;
}
