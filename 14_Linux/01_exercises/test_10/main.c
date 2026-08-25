#include <stdio.h>

int div16(int x)
{
    // 提取掩码：正数得到 0，负数得到 0xFFFFFFFF
    int mask = x >> 31;

    // 计算偏置量：正数得到 0，负数得到 15
    int bias = mask & 15;

    // 3. 加上偏置量并执行算术右移
    return (x + bias) >> 4;
}

int main()
{
    return 0;
}