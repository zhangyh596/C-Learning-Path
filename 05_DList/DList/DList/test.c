#define _CRT_SECURE_NO_WARNINGS 1

#include "DList.h"

void testDList01()
{
	DListNode* plist = DListInit();
	DListPushBack(plist, 1);
	DListPushBack(plist, 2);
	DListPushBack(plist, 3);
	DListPrint(plist);
}
int main()
{
	testDList01();
	return 0;
}