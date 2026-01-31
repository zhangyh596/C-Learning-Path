#define _CRT_SECURE_NO_WARNINGS 1

#include "Seqlist.h"

//顺序表初始化
void SLInit(SL* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

//顺序表销毁
void SLDeatroy(SL* ps)
{
	assert(ps);
	if (ps->a != NULL)
	{
		free(ps->a);
	}
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

//顺序表的打印
void SLPrint(SL s)
{
	for (int i = 0; i < s.size; i++)
	{
		printf("%d ", s.a[i]);
	}
	printf("\n");
}