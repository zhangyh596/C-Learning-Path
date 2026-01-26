#define _CRT_SECURE_NO_WARNINGS 1

#include "Seqlist.h"

void SLTest01()
{
	SL s1;
	SLInit(&s1);
	SLPushBack(&s1, 5);
	SLDestroy(&s1);
}

int main()
{
	SLTest01();
	return 0;
}