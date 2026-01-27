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
void SLDestroy(SL* ps)
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

//顺序表容量检查
void SLCheckCapacity(SL* ps)
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		int newCapacity = (ps->capacity == 0) ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newCapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);//申请失败直接退出
		}
		ps->a = tmp;//更新指针
		ps->capacity = newCapacity;
	}
}

//顺序表尾插
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

//顺序表头插
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);
	for (int i = ps->size; i > 0; i--)
	{
		ps->a[i] = ps->a[i - 1];//从后往前移动使整体向后移动
	}
	ps->a[0] = x;
	ps->size++;
}

//顺序表尾删
void SLPopback(SL* ps)
{
	assert(ps);
	assert(ps->size > 0);
	ps->size--;
}

//顺序表头删
void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size > 0);
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

//顺序表任意位置之前插入
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	SLCheckCapacity(ps);
	for (int i = ps->size; i > pos; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos] = x;
	ps->size++;
}

//顺序表任意位置删除
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}