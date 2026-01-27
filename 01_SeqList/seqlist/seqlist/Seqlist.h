#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;
	int size;//有效数据个数
	int capacity;//空间容量
}SL;

void SLInit(SL* ps);
void SLDestroy(SL* ps);
void SLPrint(SL s);
void SLCheckCapacity(SL* ps);
void SLPushBack(SL* ps, SLDataType x);
void SLPushFront(SL* ps, SLDataType x);
void SLPopback(SL* ps);
void SLPopFront(SL* ps);
void SLInsert(SL* ps, int pos, SLDataType x);
void SLErase(SL* ps, int pos);
int SLFind(SL* ps, SLDataType x);