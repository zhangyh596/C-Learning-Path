#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DLTDataType;

typedef struct DListNode
{
	DLTDataType data;
	struct DListNode* next;
	struct DListNode* prev;
}DListNode;

//初始化（创建哨兵位）
DListNode* DListInit();
//打印
void DListPrint(DListNode* phead);
//尾插
void DListPushBack(DListNode* phead, DLTDataType x);
//头插
void DListPushFront(DListNode* phead, DLTDataType x);