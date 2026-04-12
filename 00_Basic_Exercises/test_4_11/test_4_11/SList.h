#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct SListNode
{
	int data;
	struct SListNode* next;
}SListNode;

SListNode* CreateSListNode(int x);
void SListNodePrint(SListNode* phead);
void SListNodePushBack(SListNode** pphead, int x);
void SListNodePushFront(SListNode** pphead, int x);
void SListNodePopBack(SListNode** pphead);
void SListNodePopFront(SListNode** pphead);
SListNode* SListNodeFind(SListNode* phead, int x);
void SListNodeInsert(SListNode** pphead, SListNode* pos, int x);
void SListNodeInsertAfter(SListNode* pos, int x);
void SListNodeErase(SListNode** pphead, SListNode* pos);
void SListNodeEraseAfter(SListNode* pos);
void SListNodeDestroy(SListNode** pphead);
