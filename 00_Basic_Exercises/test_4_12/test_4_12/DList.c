#define _CRT_SECURE_NO_WARNINGS 1

#include "DList.h"

DListNode* CreateDListNode(int x)
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->data = x;
	newnode->prev = NULL;
	newnode->next = NULL;

	return newnode;
}

DListNode* DListInit()
{
	DListNode* dummy = (DListNode*)malloc(sizeof(DListNode));
	if (dummy == NULL)
	{
		return NULL;
	}

	dummy->data = -1;
	dummy->next = dummy;
	dummy->prev = dummy;

	return dummy;
}

void DListPrint(DListNode* phead)
{
	if (phead == NULL)
	{
		return;
	}

	printf("哨兵<=>");
	DListNode* pcur = phead->next;
	while (pcur != phead)
	{
		printf("%d<=>", pcur->data);
		pcur = pcur->next;
	}
	printf("哨兵\n");
}

void DListPushBack(DListNode* phead, int x)
{
	if (phead == NULL)
	{
		return;
	}

	DListNode* newnode = CreateDListNode(x);
	newnode->next = phead;
	newnode->prev = phead->prev;

	phead->prev->next = newnode;
	phead->prev = newnode;
}

void DListPushFront(DListNode* phead, int x)
{
	if (phead == NULL)
	{
		return;
	}

	DListNode* newnode = CreateDListNode(x);
	newnode->next = phead->next;
	newnode->prev = phead;

	phead->next->prev = newnode;
	phead->next = newnode;
}

bool DListIsEmpty(DListNode* phead)
{
	if (phead == NULL)
	{
		return false;
	}

	if (phead->next == phead)
	{
		return true;
	}
	return false;
}

void DListPopBack(DListNode* phead)
{
	if (phead == NULL || DListIsEmpty(phead))
	{
		return;
	}

	DListNode* del = phead->prev;
	phead->prev = del->prev;
	del->prev->next = phead;

	free(del);
}

void DListPopFront(DListNode* phead)
{
	if (phead == NULL || DListIsEmpty(phead))
	{
		return;
	}

	DListNode* del = phead->next;
	phead->next = del->next;
	del->next->prev = phead;

	free(del);
}

DListNode* DListFind(DListNode* phead, int x)
{
	if (phead == NULL || DListIsEmpty(phead))
	{
		return NULL;
	}

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

void DListInsert(DListNode* pos, int x)
{
	if (pos == NULL)
	{
		return;
	}

	DListNode* newnode = CreateDListNode(x);
	newnode->next = pos;
	newnode->prev = pos->prev;

	pos->prev->next = newnode;
	pos->prev = newnode;
}

void DListErase(DListNode* pos)
{
	if (pos == NULL)
	{
		return;
	}

	DListNode* node1 = pos->prev;
	DListNode* node2 = pos->next;

	node1->next = node2;
	node2->prev = node1;
	free(pos);
}

void DListDestroy(DListNode* phead)
{
	if (phead == NULL)
	{
		return;
	}

	DListNode* pcur = phead->next;
	while (pcur != phead)
	{
		DListNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}

	free(phead);
}