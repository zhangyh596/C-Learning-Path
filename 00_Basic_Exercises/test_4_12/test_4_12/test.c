#define _CRT_SECURE_NO_WARNINGS 1

#include "DList.h"

int main()
{
	DListNode* head = DListInit();
	DListPushBack(head, 1);
	DListPushBack(head, 2);
	DListPushBack(head, 3);

	DListPrint(head);

	DListPushFront(head, 4);
	DListPushFront(head, 5);
	DListPushFront(head, 6);

	DListPrint(head);

	DListPopBack(head);

	DListPrint(head);

	DListPopFront(head);

	DListPrint(head);

	DListNode* find = DListFind(head, 1);
	DListInsert(find, 100);

	DListPrint(head);

	DListErase(find);

	DListPrint(head);

	DListDestroy(head);
	head = NULL;
	return 0;
}