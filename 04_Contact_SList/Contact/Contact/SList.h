#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

//单链表打印
void SLTPrint(SLTNode* phead);
//单链表尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x);