#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "BigInt.h"

int main()
{
	BigInt a, b;
	InitBigInt(&a, "999");
	InitBigInt(&b, "1");

	BigInt ret1;
	AddBigInt(&a, &b, &ret1);

	PrintBigInt(&ret1);

	BigInt ret2;
	MultiplyBigInt(&a, &b, &ret2);

	PrintBigInt(&ret2);

	BigInt ret3;
	SubBigInt(&a, &b, &ret3);

	PrintBigInt(&ret3);

	BigInt ret4;
	int rem = 0;
	DivBigIntByInt(&a, 100, &ret4, &rem);

	PrintBigInt(&ret4);
	printf("余数是%d\n", rem);
	return 0;
}