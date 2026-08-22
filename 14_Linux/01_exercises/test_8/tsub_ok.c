#include <stdio.h>

int tsub_ok(int x, int y)
{
    int diff = x - y;

    // 正溢出条件：正数减负数（x >= 0, y < 0），结果却变成了负数 (diff < 0)
    int pos_over = x >= 0 && y < 0 && diff < 0;
    // 负溢出条件：负数减正数（x < 0, y > 0），结果却变成了正数 (diff >= 0)
    int neg_over = x < 0 && y > 0 && diff >= 0;

    return !pos_over && !neg_over;
}

int main()
{
    return 0;
}