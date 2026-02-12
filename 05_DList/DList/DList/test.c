#define _CRT_SECURE_NO_WARNINGS 1

#include "DList.h"

void testDList01()
{
	DListNode* plist = DListInit();
	DListPushBack(plist, 1);
	DListPushBack(plist, 2);
	DListPushBack(plist, 3);
	DListPrint(plist);
	DListPushFront(plist, 4);
	DListPrint(plist);
	DListPopBack(plist);
	DListPrint(plist);
	DListPopFront(plist);
	DListPrint(plist);
	/*bool ret = DListEmpty(plist);
	if (ret == false)
	{
		printf("链表不为空！\n");
	}*/

}

int main()
{
	testDList01();
	return 0;
}