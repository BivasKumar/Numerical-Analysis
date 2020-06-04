#include <stdio.h>
#define MAX_ROW 10
#define MAX_COL 10

double table[MAX_ROW][MAX_COL];

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

void forwardDifference(int y)
{
    printf("\nY values-\n");
    for (int i = 0; i < y; i++)
    {
        printf("Y%d = ", i);
        scanf("%lf", &table[i][0]);
    }
    for (int i = 1; i < y; i++)
    {
        for (int j = 0; j < y - 1; j++)
        {
            table[j][i] = table[j + 1][i - 1] - table[j][i - 1];
        }
    }
}

void forwardInterpolation(double h, double x0, double x, int y)
{
    double u = (x - x0) / h;
    double termU = 1, termDelY, term;
    double sum = table[0][0];
    for (int i = 1; i < y; i++)
    {
        termU *= (u - i + 1);
        termDelY = table[0][i];
        term = (termU * termDelY) / (double)factorial(i);
        sum += term;
    }
    printf("\nf(%lf) = %lf", x, sum);
}

int main()
{
    double h, x0, x;
    int y;
    printf("\nnumber of Y values = ");
    scanf("%d", &y);
    forwardDifference(y);

    printf("\ninterval 'h' = ");
    scanf("%lf", &h);

    printf("\nbase value 'x0' = ");
    scanf("%lf", &x0);

    printf("\ninterpolating point 'x' = ");
    scanf("%lf", &x);
    forwardInterpolation(h, x0, x, y);
    return 0;
}