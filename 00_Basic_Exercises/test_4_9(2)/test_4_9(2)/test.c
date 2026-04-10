#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "MyString.h"

int main() {
    MyString s;

    // 【测试用例 1】极小容量初始化
    Init(&s, 2);
    printf("[Init] cap=2, len=0\n");

    // 【测试用例 2】正常拼接（恰好未满）
    append(&s, "A");
    printf("[Append 'A'] str=%s | len=%d, cap=%d\n", s.str, s.len, s.cap);
    // 预期：str=A, len=1, cap=2 (合法，1个字符 + 1个'\0' 刚好占满 2 字节)

    // 【测试用例 3】极限边界攻击（触发 Bug 处！）
    printf("\n--- 准备触发越界 Bug ---\n");
    append(&s, "B");
    printf("[Append 'B'] str=%s | len=%d, cap=%d\n", s.str, s.len, s.cap);

    // 【测试用例 4】大量数据扩容测试
    append(&s, "Hello World Matrix!");
    printf("[Append Long] str=%s | len=%d, cap=%d\n", s.str, s.len, s.cap);

    Destroy(&s);
    printf("Memory Freed Successfully.\n");
    return 0;
}