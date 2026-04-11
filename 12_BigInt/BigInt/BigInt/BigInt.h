#pragma once

typedef struct
{
	int* digits;  // 动态数组，存储每一位数字（注意：这里存的是真实的数字 0-9，而不是字符 '0'-'9'）
	int len;      // 当前数字的位数
	int cap;      // 数组容量
} BigInt;

// 初始化大整数，并根据传入的字符串直接进行倒序赋值
void InitBigInt(BigInt* b, const char* str);

// 大数相加：将 b1 和 b2 相加，结果存入 result 中
void AddBigInt(const BigInt* b1, const BigInt* b2, BigInt* result);

// 大数相乘：将 b1 和 b2 相乘，结果存入 result（内部必须用 calloc 分配）
void MultiplyBigInt(const BigInt* b1, const BigInt* b2, BigInt* result);

// 比较大整数：b1 > b2 返回 1；b1 < b2 返回 -1；相等返回 0
int CompareBigInt(const BigInt* b1, const BigInt* b2);

// 大数相减：b1 - b2，结果存入 result（要求：调用前须通过 CompareBigInt 确保 b1 >= b2）
void SubBigInt(const BigInt* b1, const BigInt* b2, BigInt* result);

// 高精除以低精：b / divisor，商存入 result，余数通过指针返回给 remainder
void DivBigIntByInt(const BigInt* b, int divisor, BigInt* result, int* remainder);

//打印数组
void PrintBigInt(const BigInt* b);

// 释放内存
void DestroyBigInt(BigInt* b);
