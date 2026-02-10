#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"
#include "Contact.h"

//void testSList01()
//{
//	SLTNode* plist = NULL;
//	SLTPushBack(&plist, 1);
//	SLTPushBack(&plist, 2);
//	SLTPushBack(&plist, 3);
//	SLTPushBack(&plist, 4);
//	SLTPushFront(&plist, 5);
//	SLTPopBack(&plist);
//	SLTNode* find = SLTFind(plist, 1);
//	SLTInsert(&plist, find, 6);
//	SLTInsertAfter(find, 7);
//	//SLTErase(&plist, find);
//	SLTEraseAfter(find);
//	SLTPrint(plist);
//	SLTDestroy(&plist);
//}

void testContact02()
{
	Contact* con = NULL;
	ContactInit(&con);
	ContactAdd(&con);
	//ContactDel(&con);
	ContactModify(con);
}

int main()
{
	//testSList01();
	testContact02();
	return 0;
}