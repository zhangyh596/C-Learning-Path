#pragma once

#include <stdio.h>

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;
	int size;//有效数据个数
	int capacity;//空间容量
}SL;

void SLInit(SL* ps);