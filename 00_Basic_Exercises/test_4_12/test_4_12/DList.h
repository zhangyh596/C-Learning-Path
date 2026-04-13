#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct DListNode
{
	int data;
	struct DListNode* next;
	struct DListNode* prev;
}DListNode;

DListNode* DListInit();
void DListPrint(DListNode* phead);
void DListPushBack(DListNode* phead, int x);
void DListPushFront(DListNode* phead, int x);
bool DListIsEmpty(DListNode* phead);
void DListPopBack(DListNode* phead);
void DListPopFront(DListNode* phead);
DListNode* DListFind(DListNode* phead, int x);
void DListInsert(DListNode* pos, int x);
void DListErase(DListNode* pos);
void DListDestroy(DListNode* phead);

