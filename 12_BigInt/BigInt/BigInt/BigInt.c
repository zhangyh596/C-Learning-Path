#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BigInt.h"

void InitBigInt(BigInt* b, const char* str)
{
	int str_len = 0;
	while (str[str_len] != '\0')
	{
		str_len++;
	}
	b->cap = str_len + 2;
	b->digits = (int*)malloc(b->cap * sizeof(int));
	if (b->digits == NULL)
	{
		return;
	}
	b->len = str_len;

	// 倒序将字符存入整型数组里面
	for (int i = 0; i < str_len; i++)
	{
		b->digits[i] = str[str_len - 1 - i] - '0';
	}
}

void AddBigInt(const BigInt* b1, const BigInt* b2, BigInt* result)
{
	int len = b1->len > b2->len ? b1->len : b2->len;
	result->cap = len + 1;
	result->digits = (int*)calloc(len + 1, sizeof(int));

	for (int i = 0; i < len; i++)
	{
		int num1 = i < b1->len ? b1->digits[i] : 0;
		int num2 = i < b2->len ? b2->digits[i] : 0;
		result->digits[i] += num1 + num2;
		result->digits[i + 1] += result->digits[i] / 10;
		result->digits[i] = result->digits[i] % 10;
	}
	if (result->digits[len] > 0)
	{
		result->len = len + 1; // 发生了进位，比如 99+1=100
	}
	else
	{
		result->len = len;
	}
}

void MultiplyBigInt(const BigInt* b1, const BigInt* b2, BigInt* result)
{
	if (b1->len == 0 || b2->len == 0)
	{
		return;
	}

	result->cap = b1->len + b2->len;
	result->len = b1->len + b2->len;
	result->digits = (int*)calloc(result->cap, sizeof(int));
	for (int i = 0; i < b1->len; i++)
	{
		for (int j = 0; j < b2->len; j++)
		{
			result->digits[i + j] += b1->digits[i] * b2->digits[j];
		}
	}

	for (int i = 0; i < result->cap - 1; i++)
	{
		result->digits[i + 1] += result->digits[i] / 10;
		result->digits[i] = result->digits[i] % 10;
	}

	while (result->len > 1 && result->digits[result->len - 1] == 0)
	{
		(result->len)--;
	}
}

int CompareBigInt(const BigInt* b1, const BigInt* b2)
{
	if (b1->len < b2->len)
	{
		return -1;
	}
	else if (b1->len > b2->len)
	{
		return 1;
	}
	else
	{
		for (int i = b1->len - 1; i >= 0; i--)
		{
			if (b1->digits[i] < b2->digits[i])
			{
				return -1;
			}
			else if (b1->digits[i] > b2->digits[i])
			{
				return 1;
			}
		}
	}
	return 0;
}

void SubBigInt(const BigInt* b1, const BigInt* b2, BigInt* result)
{
	const BigInt* larger = b1;
	const BigInt* smaller = b2;

	if (CompareBigInt(b1, b2) == -1)
	{
		larger = b2;
		smaller = b1;
	}

	result->cap = larger->len;
	result->len = larger->len;
	result->digits = (int*)calloc(result->cap, sizeof(int));

	int borrow = 0;// 记录借位
	for (int i = 0; i < larger->len; i++)
	{
		int num1 = larger->digits[i];
		int num2 = i < smaller->len ? smaller->digits[i] : 0;

		int tmp = num1 - num2 - borrow;

		if (tmp < 0)
		{
			tmp += 10;
			borrow = 1;
		}
		else
		{
			borrow = 0;
		}
		result->digits[i] = tmp;
	}

	// 去除前导零
	while (result->len > 1 && result->digits[result->len - 1] == 0)
	{
		(result->len)--;
	}
}

void DivBigIntByInt(const BigInt* b, int divisor, BigInt* result, int* remainder)
{
	if (divisor == 0)
	{
		return;
	}

	result->cap = b->cap;
	result->len = b->len;
	result->digits = (int*)calloc(result->cap, sizeof(int));

	long long rem = 0;// 记录过程中的余数
	//从最高位开始除，同时逆序存入了result->digits里面
	for (int i = b->len - 1; i >= 0; i--)
	{
		long long cur = rem * 10 + b->digits[i];

		result->digits[i] = cur / divisor;
		rem = cur % divisor;
	}

	while (result->len > 1 && result->digits[result->len - 1] == 0)
	{
		(result->len)--;
	}

	if (remainder != NULL)
	{
		*remainder = (int)rem;
	}
}

void PrintBigInt(const BigInt* b)
{
	for (int i = b->len - 1; i >= 0; i--)
	{
		printf("%d", b->digits[i]);
	}
	printf("\n");
}

void DestroyBigInt(BigInt* b)
{
	if (b->digits != NULL)
	{
		free(b->digits);
		b->digits = NULL;
	}
	b->len = 0;
	b->cap = 0;
}