#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

struct ListNode 
{
	int val;
	struct ListNode* next;
};

struct ListNode* middleNode(struct ListNode* head) {
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

struct ListNode* reverseList(struct ListNode* head) {
	if (head == NULL)
	{
		return head;
	}
	struct ListNode* n1;
	struct ListNode* n2;
	struct ListNode* n3;
	n1 = NULL, n2 = head, n3 = n2->next;
	while (n2)
	{
		n2->next = n1;
		n1 = n2;
		n2 = n3;
		if (n3 != NULL)
		{
			n3 = n3->next;
		}
	}
	return n1;
}

struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode* prev = NULL;
	struct ListNode* pcur = head;
	while (pcur)
	{
		struct ListNode* next = pcur->next;
		pcur->next = prev;
		prev = pcur;
		pcur = next;
	}
	return prev;
}

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