#include <stdio.h>

void decode1(long *xp, long *yp, long *zp)
{
    long x = *xp;
    long y = *yp;
    long z = *zp;

    *yp = x;
    *zp = y;
    *xp = z;
}

int main()
{
    printf("Hello, World!\n");
    return 0;
}
