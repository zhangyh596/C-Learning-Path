#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode* next;
};


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
	if (list1 == NULL)
	{
		return list2;
	}
	if (list2 == NULL)
	{
		return list1;
	}
	struct ListNode* l1 = list1;
	struct ListNode* l2 = list2;

	struct ListNode* newhead = NULL;
	struct ListNode* newtail = NULL;
	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			if (newhead == NULL)
			{
				newhead = l1;
				newtail = l1;
			}
			else
			{
				newtail->next = l1;
				newtail = newtail->next;
			}
			l1 = l1->next;
		}
		else
		{
			if (newhead == NULL)
			{
				newhead = l2;
				newtail = l2;
			}
			else
			{
				newtail->next = l2;
				newtail = newtail->next;
			}
			l2 = l2->next;
		}
	}
	if (l1)
	{
		newtail->next = l1;
	}
	if (l2)
	{
		newtail->next = l2;
	}
	return newhead;
}


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
	if (list1 == NULL)
	{
		return list2;
	}
	if (list2 == NULL)
	{
		return list1;
	}
	struct ListNode* l1 = list1;
	struct ListNode* l2 = list2;

	struct ListNode* newhead, * newtail;
	newhead = newtail = (struct ListNode*)malloc(sizeof(struct ListNode));

	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			newtail->next = l1;
			newtail = newtail->next;
			l1 = l1->next;
		}
		else
		{
			newtail->next = l2;
			newtail = newtail->next;
			l2 = l2->next;
		}
	}
	if (l1)
	{
		newtail->next = l1;
	}
	if (l2)
	{
		newtail->next = l2;
	}

	struct ListNode* ret = newhead->next;
	free(newhead);
	newhead = NULL;
	return ret;
}


typedef struct ListNode
{
	int val;
	struct ListNode* next;
}ListNode;

ListNode* BuyNode(int x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->val = x;
	node->next = NULL;
	return node;
}

ListNode* createCircle(int n)
{
	ListNode* phead = BuyNode(1);
	ListNode* ptail = phead;
	for (int i = 2; i <= n; i++)
	{
		ptail->next = BuyNode(i);
		ptail = ptail->next;
	}
	ptail->next = phead;
	return ptail;
}
 
int ysf(int n, int m) 
{
	ListNode* prev = createCircle(n);
	ListNode* pcur = prev->next;
	int count = 1;
	while (pcur->next != pcur)
	{
		if (count == m)
		{
			prev->next = pcur->next;
			free(pcur);
			pcur = prev->next;
			count = 1;
		}
		else
		{
			prev = pcur;
			pcur = pcur->next;
			count++;
		}
	}
	return pcur->val;
}