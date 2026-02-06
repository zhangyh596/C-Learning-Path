#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

struct ListNode 
{
	int val;
	struct ListNode* next;
};


struct ListNode* removeElements(struct ListNode* head, int val) {
	struct ListNode* newhead = NULL, * newtail = NULL;
	struct ListNode* pcur = head;
	while (pcur)
	{
		if (pcur->val != val)
		{
			if (newhead == NULL)
			{
				newhead = newtail = pcur;
			}
			else
			{
				newtail->next = pcur;
				newtail = newtail->next;
			}
		}
		pcur = pcur->next;
	}
	if (newtail != NULL)
	{
		newtail->next = NULL;
	}
	return newhead;
}

int main()
{

	return 0;
}