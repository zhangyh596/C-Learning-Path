#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	int flag = 1;//标记是否输出了第一项
//	for (int i = n; i >= 0; i--)
//	{
//		int a = 0;
//		scanf("%d", &a);
//
//		if (a == 0)
//		{
//			continue;
//		}
//		else if (a < 0)
//		{
//			printf("-");
//		}
//		else
//		{
//			if (flag == 0)
//			{
//				printf("+");
//			}
//		}
//		flag = 0;
//
//		a = abs(a);
//		if (a != 1 || (a == 1 && i == 0))
//		{
//			printf("%d", a);
//		}
//
//		if (i == 0)
//		{
//			continue;
//		}
//		else if (i == 1)
//		{
//			printf("x");
//		}
//		else
//		{
//			printf("x^%d", i);
//		}
//	}
//	return 0;
//}

#include "poly.h"

int main()
{
	PolyNode* head = NULL;

	// 测试用例 1: 乱序插入，测试你的排序是否正确
	// 我们要构造: 5x^5 + 3x^2 - x + 4
	appendNode(&head, 3, 2);
	appendNode(&head, 5, 5);
	appendNode(&head, -1, 1);
	appendNode(&head, 4, 0);

	printf("预期输出: 5x^5+3x^2-x+4\n");
	printf("实际输出: ");
	printPoly(head);
	printf("\n\n");

	// 测试用例 2: 合并同类项与零次项抵消
	printf("--- 插入 -3x^2 进行抵消测试 ---\n");
	appendNode(&head, -3, 2);

	printf("预期输出: 5x^5-x+4\n"); // 3x^2 应该被彻底删除了
	printf("实际输出: ");
	printPoly(head);
	printf("\n\n");

	printf("--- 清理内存 ---\n");
	freePoly(&head);
	if (head == NULL)
	{
		printf("测试通过：内存释放完毕，且头指针已安全置空！\n");
	}
	else
	{
		printf("警告：头指针未被置空，可能产生悬挂指针！\n");
	}
	return 0;
}