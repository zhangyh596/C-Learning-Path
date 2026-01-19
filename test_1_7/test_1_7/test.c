#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int max = 0;
    int min = 0x7fffffff;
    for (int i = 0; i < n; i++)
    {
        int score = 0;
        scanf("%d", &score);
        if (score > max)
        {
            max = score;
        }
        if (score < min)
        {
            min = score;
        }
    }
    int d = max - min;
    printf("%d", d);
    return 0;
}