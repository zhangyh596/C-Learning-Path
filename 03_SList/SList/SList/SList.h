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
 //单链表在指定位置之前插入
 void SLTInsert(SLTNode**pphead, SLTNode* pos, SLTDataType x);
 //单链表在指定位置之后插入
 void SLTInsertAfter(SLTNode* pos, SLTDataType x);
 //单链表删除指定位置的节点
 void SLTErase(SLTNode** pphead, SLTNode* pos);
 //单链表删除指定位置之后的节点
 void SLTEraseAfter(SLTNode* pos);