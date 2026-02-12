#define _CRT_SECURE_NO_WARNINGS 1

#include "DList.h"

//辅助函数：创建新节点
DListNode* BuyDListNode(DLTDataType x)
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;

	return newnode;
}

//初始化
DListNode* DListInit()
{
	DListNode* phead = BuyDListNode(-1);
	phead->next = phead;//一定要指向自身
	phead->prev = phead;
	return phead;
}

//打印
void DListPrint(DListNode* phead)
{
	assert(phead);
	printf("哨兵<==>");
	DListNode* pcur = phead->next;
	while (pcur != phead)
	{
		printf("%d<==>", pcur->data);
		pcur = pcur->next;
	}
	printf("哨兵\n");
}

//尾插
void DListPushBack(DListNode* phead, DLTDataType x)
{
	assert(phead);
	DListNode* newnode = BuyDListNode(x);
	DListNode* ptail = phead->prev;

	newnode->next = phead;
	newnode->prev = ptail;
	ptail->next = newnode;
	phead->prev = newnode;
}

//头插
void DListPushFront(DListNode* phead, DLTDataType x)
{
	assert(phead);
	DListNode* newnode = BuyDListNode(x);
	DListNode* first = phead->next;

	newnode->next = first;
	newnode->prev = phead;
	phead->next = newnode;
	first->prev = newnode;
}

//判空（辅助）
bool DListEmpty(DListNode* phead)
{
	assert(phead);
	return phead->next == phead;
}

//尾删
void DListPopBack(DListNode* phead)
{
	assert(phead && !DListEmpty(phead));
	DListNode* ptail = phead->prev;
	DListNode* ptailPrev = ptail->prev;

	phead->prev = ptailPrev;
	ptailPrev->next = phead;
	free(ptail);
	ptail = NULL;
}

//头删
void DListPopFront(DListNode* phead)
{
	assert(phead && !DListEmpty(phead));
	DListNode* first = phead->next;
	DListNode* second = first->next;

	phead->next = second;
	second->prev = phead;
	free(first);
	first = NULL;
}

//查找
DListNode* DListFind(DListNode* phead, DLTDataType x)
{
	assert(phead);
	DListNode* pcur = phead->next;

	while (pcur != phead)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}