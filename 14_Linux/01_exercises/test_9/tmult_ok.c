#include <stdio.h>
#include <stdint.h>

int tmult_ok(int x, int y)
{
    int p = x * y;

    return !x || p / x == y;
}

int tmult_ok_64(int x, int y)
{
    // 关键：先将 x 强转为 int64_t，触发 C 语言的“类型提升”，在 64 位下做乘法
    // 绝对不能写成 int64_t p64 = (int64_t)(x * y)
    // 否则括号内的 x * y 会先按照 32 位做乘法（此时已经触发溢出截断），然后再把截断后的垃圾值提升为 64 位，检测逻辑会完全失效
    int64_t p64 = (int64_t)x * y;

    // 将 64 位真值截断为 int (32 位)，比较截断后的值与 64 位真值是否相等
    return p64 == (int)p64;
}

int main()
{
    return 0;
}