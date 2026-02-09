#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;

typedef struct SListNode
{
	int data;
	struct Node* next;
}SLTNode;

//单链表打印
void SListPrint(SLTNode* phead);
//单链表尾插
SLTNode* SLTPushBack(SLTNode** phead, SLTDataType x);