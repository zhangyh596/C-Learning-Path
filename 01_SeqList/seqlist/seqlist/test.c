#define _CRT_SECURE_NO_WARNINGS 1

#include "Seqlist.h"

void SLTest01()
{
	SL s1;
	SLInit(&s1);
	SLPushBack(&s1, 4);
	SLPushBack(&s1, 5);
	SLPrint(s1);
	SLPopback(&s1);
	SLPrint(s1);
	SLPushFront(&s1, 1);
	SLPushFront(&s1, 2);
	SLPrint(s1);
	SLPopFront(&s1);
	SLPrint(s1);
	SLDestroy(&s1);
}

void SLTest02()
{
	SL s2;
	SLInit(&s2);
	SLPushBack(&s2, 1);
	SLPushBack(&s2, 2);
	SLPushBack(&s2, 3);
	SLPushBack(&s2, 4);
	SLPrint(s2);
	SLInsert(&s2, 0, 5);
	SLInsert(&s2, s2.size, 6);
	SLPrint(s2);
	SLErase(&s2, 0);
	SLPrint(s2);
	SLErase(&s2, s2.size - 1);
	SLPrint(s2);
	int find = SLFind(&s2, 4);
	if (find < 0)
	{
		printf("没有找到\n");
	}
	else
	{
		printf("找到了，下标是%d\n", find);
	}
	SLDestroy(&s2);
}
int main()
{
	//SLTest01();
	SLTest02();
	return 0;
}