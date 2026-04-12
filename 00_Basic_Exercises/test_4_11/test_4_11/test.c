#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

int main()
{
	SListNode* head = NULL;
	SListNodePushBack(&head, 1);
	SListNodePushBack(&head, 2);
	SListNodePushBack(&head, 3);

	SListNodePrint(head);

	SListNodePushFront(&head, 4);
	SListNodePushFront(&head, 5);
	SListNodePushFront(&head, 6);

	SListNodePrint(head);

	//SListNodePopBack(&head);
	//SListNodePopBack(&head);
	//SListNodePopBack(&head);

	//SListNodePrint(head);

	//SListNodePopFront(&head);
	//SListNodePopFront(&head);
	//SListNodePopFront(&head);

	//SListNodePrint(head);

	SListNode* find = SListNodeFind(head, 1);
	SListNodeInsert(&head, find, 100);

	SListNodePrint(head);

	SListNodeInsertAfter(find, 200);

	SListNodePrint(head);

	//SListNodeErase(&head, find);

	//SListNodePrint(head);

	SListNodeEraseAfter(find);

	SListNodePrint(head);

	SListNodeDestroy(&head);
	return 0;
}