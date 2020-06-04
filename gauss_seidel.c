#include <stdio.h>
#include <math.h>

float fx(float y, float z)
{
    float x = 9 - y - (4 * z);
    return x;
}

float fy(float x, float z)
{
    float y = ((8 * x) + (2 * z) - 20) / 3;
    return y;
}

float fz(float x, float y)
{
    float z = ((4 * x) + (11 * y) - 33);
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
        ty = fy(tx, z);
        tz = fz(tx, ty);
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