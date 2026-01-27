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

int main()
{
	SLTest01();
	return 0;
}