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
}

//初始化
DListNode* DListInit()
{
	DListNode* phead = BuyDListNode(-1);
	phead->next = phead;
	phead->prev = phead;
}