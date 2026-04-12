#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

SListNode* CreateSListNode(int x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

void SListNodePrint(SListNode* phead)
{
	SListNode* pcur = phead;
	while (pcur != NULL)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}

void SListNodePushBack(SListNode** pphead, int x)
{
	if (pphead == NULL)
	{
		return;
	}

	SListNode* newnode = CreateSListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SListNode* pcur = *pphead;
		while (pcur->next != NULL)
		{
			pcur = pcur->next;
		}
		pcur->next = newnode;
	}
}

void SListNodePushFront(SListNode** pphead, int x)
{
	if (pphead == NULL)
	{
		return;
	}

	SListNode* newnode = CreateSListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SListNodePopBack(SListNode** pphead)
{
	if (pphead == NULL || *pphead == NULL)
	{
		return;
	}

	SListNode* pcur = *pphead;
	if (pcur->next == NULL)
	{
		free(pcur);
		*pphead = NULL;
		return;
	}

	SListNode* prev = NULL;
	while (pcur->next != NULL)
	{
		prev = pcur;
		pcur = pcur->next;
	}

	prev->next = NULL;
	free(pcur);
	pcur = NULL;
}

void SListNodePopFront(SListNode** pphead)
{
	if (pphead == NULL || *pphead == NULL)
	{
		return;
	}

	SListNode* newhead = (*pphead)->next;
	free(*pphead);
	*pphead = newhead;
}

SListNode* SListNodeFind(SListNode* phead, int x)
{
	SListNode* pcur = phead;
	while (pcur != NULL)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
		assert(pcur != NULL); // 如果找到底还没找到 pos，说明 pos 给错了，报错！
	}
	return NULL;
}

void SListNodeInsert(SListNode** pphead, SListNode* pos, int x)
{
	if (pphead == NULL)
	{
		return;
	}

	SListNode* newnode = CreateSListNode(x);

	if (*pphead == pos)
	{
		newnode->next = *pphead;
		*pphead = newnode;
		return;
	}

	SListNode* prev = NULL;
	SListNode* pcur = *pphead;
	while (pcur != pos)
	{
		prev = pcur;
		pcur = pcur->next;
	}

	prev->next = newnode;
	newnode->next = pcur;
}

void SListNodeInsertAfter(SListNode* pos, int x)
{
	if (pos == NULL)
	{
		return;
	}

	SListNode* newnode = CreateSListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SListNodeErase(SListNode** pphead, SListNode* pos)
{
	if (pphead == NULL || *pphead == NULL)
	{
		return;
	}

	if (pos == *pphead)
	{
		SListNode* newhead = (*pphead)->next;
		free(*pphead);
		*pphead = newhead;
		return;
	}

	SListNode* pcur = *pphead;
	while (pcur->next != pos)
	{
		pcur = pcur->next;
	}
	pcur->next = pos->next;
	free(pos);
	pos = NULL;
}

void SListNodeEraseAfter(SListNode* pos)
{
	if (pos == NULL || pos->next == NULL)
	{
		return;
	}

	SListNode* next = pos->next;
	pos->next = next->next;
	free(next);
	next = NULL;
}

void SListNodeDestroy(SListNode** pphead)
{
	if (pphead == NULL || *pphead == NULL)
	{
		return;
	}

	SListNode* pcur = *pphead;
	while (pcur != NULL)
	{
		SListNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}

	*pphead = NULL;
}