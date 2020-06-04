#include <stdio.h>

int main()
{
    float x[25], y[25];
    float ip, sum = 0, t;
    int n;
    printf("Enter number of data points = ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("x[%d] = ", i + 1);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i + 1);
        scanf("%f", &y[i]);
    }
    printf("Enter the interpolating point = ");
    scanf("%f", &ip);
    for (int i = 0; i < n; i++)
    {
        t = y[i];
        for (int j = 0; j < n; j++)
        {
            if (i != j)
                t *= (ip - x[j]) / (x[i] - x[j]);
        }
        sum += t;
    }
    printf("f[%f] = %f", ip, sum);
    return 0;
}