#include <stdio.h>

int tadd_ok(int x, int y)
{
    int sum = (int)((unsigned)x + (unsigned)y);

    int pos_over = x > 0 && y > 0 && sum < 0;
    int neg_over = x < 0 && y < 0 && sum >= 0;

    return !neg_over && !pos_over;
}

int main()
{
    return 0;
}