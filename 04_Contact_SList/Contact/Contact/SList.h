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
//单链表头插
void SLTPushFront(SLTNode** pphead, SLTDataType x);
//单链表尾删
void SLTPopBack(SLTNode** pphead);
//单链表头删
void SLTPopFront(SLTNode** pphead);
//单链表查找
SLTNode* SLTFind(SLTNode* phead, SLTDataType x);