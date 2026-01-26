#define _CRT_SECURE_NO_WARNINGS 1

#include "Seqlist.h"

//顺序表初始化
void SLInit(SL* ps)
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

//顺序表销毁
void SLDestroy(SL* ps)
{
	if (ps->a != NULL)
	{
		free(ps->a);
	}
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}


