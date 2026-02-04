#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

void SListTest01()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPopBack(&plist);
	SLTPrint(plist);
	SLTPushFront(&plist, 6);
	SLTPrint(plist);
}

int main()
{
	SListTest01();
	return 0;
}