#define _CRT_SECURE_NO_WARNINGS 1

#include "poly.h"

PolyNode* createNode(int coef, int exp)
{
	PolyNode* newnode = (PolyNode*)malloc(sizeof(PolyNode));
	newnode->coef = coef;
	newnode->exp = exp;
	newnode->next = NULL;

	return newnode;
}

void appendNode(PolyNode** head, int coef, int exp)
{
	if (coef == 0)
		return;

	PolyNode* prev = NULL;// 指向pcur的前一个指针
	PolyNode* pcur = *head;

	// 只要 curr 还没走到尽头，且 curr 的指数大于我们要处理的指数，就继续往后走
	while (pcur != NULL && pcur->exp > exp)
	{
		prev = pcur;
		pcur = pcur->next;
	}

	// 发现指数完全一样的项，直接合并同类项（需要先检查pcur不为空）
	if (pcur != NULL && pcur->exp == exp)
	{
		pcur->coef += coef;
		//检查一下当前pcur->coef是否变成了0
		if (pcur->coef == 0)
		{
			// 情况1：被删除的节点是头节点（即第一个节点就抵消了）
			if (prev == NULL)
			{
				*head = pcur->next;
			}
			// 情况2：被删除的节点是中间或尾部节点
			else
			{
				prev->next = pcur->next;
			}
			free(pcur);
			pcur = NULL;
		}
		return;
	}
	// 指数不存在（pcur == NULL 或 pcur->exp < exp），需要插入新节点
	PolyNode* newnode = createNode(coef, exp);

	//pcur还指向头指针时，意味着newnode的指数最大
	if (prev == NULL)
	{
		newnode->next = *head;
		*head = newnode;
	}
	else
	{
		prev->next = newnode;
		newnode->next = pcur;
	}
}

void printPoly(PolyNode* head)
{
	if (head == NULL)
		return;

	PolyNode* pcur = head;
	while (pcur != NULL)
	{
		// 处理符号
		if (pcur->coef > 0)
		{
			if (pcur != head)
			{
				printf("+");
			}
		}
		else if (pcur->coef < 0)
		{
			printf("-");
		}

		// 处理系数
		int printCoef = abs(pcur->coef);
		if (printCoef != 1 || (printCoef == 1 && pcur->exp == 0))
		{
			printf("%d", printCoef);
		}

		// 处理指数
		if (pcur->exp == 0)
		{

		}
		else if (pcur->exp == 1)
		{
			printf("x");
		}
		else
		{
			printf("x^%d", pcur->exp);
		}
		pcur = pcur->next;
	}
}

void freePoly(PolyNode** head)
{
	PolyNode* pcur = *head;
	while (pcur != NULL)
	{
		PolyNode* temp = pcur->next;// 保存pcur指向的下一个节点防止找不到
		free(pcur);
		pcur = temp;
	}
	*head = NULL;
}
