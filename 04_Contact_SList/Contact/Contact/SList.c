#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

//单链表打印
void SListPrint(SLTNode* phead)
{
	SLTNode* pcur = phead;
	while (pcur != NULL)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}

//创建新节点（辅助函数）
 static SLTNode* BuySLTNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

