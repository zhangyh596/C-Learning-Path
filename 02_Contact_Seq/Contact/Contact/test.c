#define _CRT_SECURE_NO_WARNINGS 1

#include "Seqlist.h"

//void ContactTest01()
//{
//	Contact con;
//	ContactInit(&con);
//	ContactAdd(&con);
//	ContactAdd(&con);
//	ContactShow(&con);
//	//ContactDel(&con);
//	//ContactModify(&con);
//	ContactShow(&con);
//	ContactFind(&con);
//    ContactDestroy(&con);
//}

void menu()
{
	printf("********************  通讯录  ********************\n");
	printf("**********1.增加联系人  2.删除联系人 *************\n");
	printf("**********3.修改联系人  4.查找联系人**************\n");
	printf("**********5.展示联系人  0.   退出  ***************\n");
	printf("**************************************************\n");

}
int main()
{
	int op = 0;
	Contact con;
	ContactInit(&con);

	do
	{
		menu();
		printf("请选择操作:\n");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			ContactAdd(&con);
			break;
		case 2:
			ContactDel(&con);
			break;
		case 3:
			ContactModify(&con);
			break;
		case 4:
			ContactFind(&con);
			break;
		case 5:
			ContactShow(&con);
			break;
		case 0:
			printf("退出通讯录\n");
			break;
		default:
			printf("输入错误，请重新选择正确的数字\n");
			break;
		}
	} while (op);
	ContactDestroy(&con);
	return 0;
}