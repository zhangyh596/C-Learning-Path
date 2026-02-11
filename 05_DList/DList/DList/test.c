#define _CRT_SECURE_NO_WARNINGS 1

#include "DList.h"

void testDList01()
{
	DListNode* plist = DListInit();
	DListPrint(plist);
}
int main()
{
	testDList01();
	return 0;
}