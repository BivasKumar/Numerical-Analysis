#include <stdio.h>
#include <math.h>

float fx(float y, float z)
{
    float x = (1.57 - 0.15 * y - 0.30 * z) / 4.50;
    return x;
}

float fy(float x, float z)
{
    float y = (3.86 + 0.15 * x + 0.45 * z) / 10.50;
    return y;
}

float fz(float x, float y)
{
    float z = (0.45 * x + 0.30 * y - 14.28) / 15;
    return z;
}

int main()
{
    float x, y, z;
    float tx, ty, tz;
    float ex, ey, ez;
    float e;
    printf("Enter initial values of x, y and z = ");
    scanf("%f%f%f", &x, &y, &z);
    printf("Enter error threshold = ");
    scanf("%f", &e);
    do
    {
        tx = fx(y, z);
        ty = fy(x, z);
        tz = fz(x, y);
        ex = fabs(x - tx);
        ey = fabs(y - ty);
        ez = fabs(z - tz);
        x = tx;
        y = ty;
        z = tz;
    } while (ex > e && ey > e && ez > e);
    printf("x = %f\ny = %f\nz = %f", x, y, z);
    return 0;
}