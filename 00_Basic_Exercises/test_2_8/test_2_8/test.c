#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

 typedef struct ListNode
{
	int val;
	struct ListNode* next;
}ListNode;
 
struct ListNode* partition(struct ListNode* head, int x) {
	if (head == NULL)
	{
		return NULL;
	}
	ListNode* smallhead, * smalltail;
	ListNode* largehead, * largetail;
	smallhead = smalltail = (ListNode*)malloc(sizeof(ListNode));
	largehead = largetail = (ListNode*)malloc(sizeof(ListNode));

	ListNode* pcur = head;
	while (pcur)
	{
		if (pcur->val < x)
		{
			smalltail->next = pcur;
			smalltail = smalltail->next;
		}
		else
		{
			largetail->next = pcur;
			largetail = largetail->next;
		}
		pcur = pcur->next;
	}
	largetail->next = NULL;
	smalltail->next = largehead->next;

	ListNode* ret = smallhead->next;
	free(smallhead);
	free(largehead);
	smallhead = largehead = NULL;
	return ret;
}


int main()
{
	return 0;
}