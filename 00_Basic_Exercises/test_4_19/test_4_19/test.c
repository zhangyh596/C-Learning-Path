#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int val;
	struct Node* next;
	struct Node* random;
};

struct Node* copyRandomList(struct Node* head) {
	if (head == NULL)
	{
		return NULL;
	}

	struct Node* pcur = head;
	while (pcur)
	{
		struct Node* next = pcur->next;
		struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
		newnode->val = pcur->val;

		newnode->next = next;
		pcur->next = newnode;
		pcur = next;
	}

	pcur = head;
	while (pcur)
	{
		if (pcur->random == NULL)
		{
			pcur->next->random = NULL;
		}
		else
		{
			pcur->next->random = pcur->random->next;
		}
		pcur = pcur->next->next;
	}

	pcur = head;
	struct Node* newhead = head->next;
	struct Node* newpcur = newhead;
	while (pcur)
	{
		pcur->next = pcur->next->next;
		if (newpcur->next != NULL)
		{
			newpcur->next = newpcur->next->next;
		}

		pcur = pcur->next;
		newpcur = newpcur->next;
	}
	return newhead;
}