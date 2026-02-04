#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

//辅助函数：申请新节点
SLTNode* SLTBuyNode(SLTDataType x)
{
	SLTNode *newnode
}

//单链表打印
void SListPrint(SLTNode* phead)
{
	SLTNode* pcur = phead;
	while (pcur)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next; 
	}
	printf("NULL\n");
}

//单链表尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{

	SLTNode* ptail = *pphead;
	while (ptail->next)
	{
		ptail = ptail->next;
	}

}