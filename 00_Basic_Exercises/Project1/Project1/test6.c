//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <stdlib.h>
//
//struct ListNode
//{
//	int val;
//	struct ListNode* next;
//};
//
//void move_odd_before_even(struct ListNode* phead)
//{
//	if (phead == NULL)
//	{
//		return;
//	}
//
//	struct ListNode* odd = phead;
//	struct ListNode* even = phead->next;
//	struct ListNode* even_head = even;
//
//	while (even && even->next)
//	{
//		odd->next = even->next;
//		odd = odd->next;
//
//		even->next = odd->next;
//		even = even->next;
//	}
//	odd->next = even_head;
//}
//
//void reverse_range(struct ListNode** phead, int a, int b)
//{
//	if (phead == NULL || *phead == NULL)
//	{
//		return;
//	}
//
//	struct ListNode dummy;
//	dummy.val = -1;
//	dummy.next = *phead;
//
//	struct ListNode* prev = &dummy;//找翻转区间的前一个节点
//	for (int i = 0; i < a - 1; i++)
//	{
//		prev = prev->next;
//	}
//
//	struct ListNode* pcur = prev->next;
//	struct ListNode* node1 = pcur;// 翻转前区间的第一个节点，翻转后区间的最后一个节点
//	struct ListNode* curr_prev = NULL;
//	for (int i = 0; i <= b - a; i++)
//	{
//		struct ListNode* next = pcur->next;
//		pcur->next = curr_prev;
//
//		curr_prev = pcur;
//		pcur = next;
//	}
//
//	prev->next = curr_prev;
//	node1->next = pcur;
//
//	*phead = dummy.next;
//}
//
//int main()
//{
//	struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	node1->val = 10;
//	struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	node2->val = 20;
//	struct ListNode* node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	node3->val = 30;
//	struct ListNode* node4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	node4->val = 40;
//	struct ListNode* node5 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	node5->val = 50;
//
//	node1->next = node2;
//	node2->next = node3;
//	node3->next = node4;
//	node4->next = node5;
//	node5->next = NULL;
//
//	move_odd_before_even(node1);
//	reverse_range(&node1, 2, 4);
//	return 0;
//}