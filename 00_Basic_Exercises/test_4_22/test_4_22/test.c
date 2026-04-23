#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

//struct ListNode* reverseKGroup(struct ListNode* head, int k)
//{
//	struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//	dummy->next = head;
//
//	struct ListNode* prev = dummy;
//	struct ListNode* pcur = dummy->next;
//	
//	int count = 0;
//	while (pcur)
//	{
//		pcur = pcur->next;
//		count++;
//	}
//
//	pcur = dummy->next;
//	for (int i = 0; i < count / k; i++)
//	{
//		struct ListNode* groupPrev = NULL;
//		struct ListNode* start = pcur;
//
//		for (int j = 0; j < k; j++)
//		{
//			struct ListNode* next = pcur->next;
//			pcur->next = groupPrev;
//			groupPrev = pcur;
//			pcur = next;
//		}
//
//		start->next = pcur;
//		prev->next = groupPrev;
//
//		prev = start;
//	}
//	return dummy->next;
//}


struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
	struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
	dummy->next = head;

	struct ListNode* prev = dummy;
	struct ListNode* pcur = dummy->next;

	int count = 0;
	while (pcur)
	{
		count++;
		pcur = pcur->next;
	}

	pcur = dummy->next;
	for (int i = 0; i < count / k; i++)
	{
		struct ListNode* groupPrev = NULL;
		struct ListNode* start = pcur;

		for (int j = 0; j < k; j++)
		{
			struct ListNode* next = pcur->next;
			pcur->next = groupPrev;
			groupPrev = pcur;
			pcur = next;
		}

		prev->next = groupPrev;
		start->next = pcur;

		prev = start;
	}
	return dummy->next;
}