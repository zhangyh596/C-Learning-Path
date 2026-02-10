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
	ContactFind(con);
	ContactShow(con);
	ContactDestroy(&con);
}

void menu()
{
	printf("***********************\n");
	printf("*****1.add   2.del*****\n");
	printf("*****3.find  4.modify**\n");
	printf("*****5.show  0.exit****\n");
	printf("***********************\n");
}

int main()
{
	//testSList01();
	//testContact02();
	Contact* con = NULL;
	ContactInit(&con);

	int input = 0;
	do
	{
		menu();
		printf("请选择要进行的操作：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			ContactAdd(&con);
			break;
		case 2:
			ContactDel(&con);
			break;
		case 3:
			ContactFind(con);
			break;
		case 4:
			ContactModify(con);
			break;
		case 5:
			ContactShow(con);
			break;
		case 0:
			ContactDestroy(&con);
			printf("退出通讯录！\n");
			break;
		default:
			printf("输入错误，请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}