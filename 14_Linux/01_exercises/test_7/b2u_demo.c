// b2u_demo.c
#include <stdio.h>
#include <stdint.h>

int main() {
    // 8 位无符号数 (B2U_8) 的物理极限
    uint8_t u8_max = 0xFF; // 二进制 11111111
    printf("B2U_8([11111111]) = %u (理论 2^8 - 1 = %d)\n", u8_max, (1 << 8) - 1);

    // 模拟 4 位无符号数 (B2U_4) 掩码截断
    uint8_t b2u_4_max = 0b1111;
    printf("B2U_4([1111])     = %u (理论 2^4 - 1 = %d)\n", b2u_4_max, (1 << 4) - 1);

    return 0;
}
