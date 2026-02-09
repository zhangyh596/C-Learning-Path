#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

//单链表打印
void SListPrint(SListNode* phead)
{
	SListNode* pcur = phead;
	while (pcur != NULL)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}

//创建新节点
SListNode* BuySListNode(SLTDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

