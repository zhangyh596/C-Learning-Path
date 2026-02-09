#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

void testSList01()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPushFront(&plist, 5);
	SLTPopBack(&plist);
	SLTNode* find = SLTFind(plist, 1);
	if (find == NULL)
	{
		printf("没找到\n");
	}
	else
	{
		printf("找到了\n");
	}
	SLTPrint(plist);
}

int main()
{
	testSList01();
	return 0;
}