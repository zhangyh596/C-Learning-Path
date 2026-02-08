#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

void SListTest01()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	//SLTPopBack(&plist);
	//SLTPrint(plist);
	//SLTPushFront(&plist, 6);
	//SLTPrint(plist);
	//SLTPopFront(&plist);
	//SLTPrint(plist);
	SLTNode* find = SLTFind(plist, 1);
	SLTInsert(&plist, find, 5);
	SLTInsertAfter(find, 5);
	//SLTErase(&plist, find);
	SLTEraseAfter(find);
	SLTPrint(plist);
	SLTDestroy(&plist);
	//if (find == NULL)
	//{
	//	printf("没有找到\n");
	//}
	//else
	//{
	//	printf("找到了\n");
	//}
}

int main()
{
	SListTest01();
	return 0;
}