#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int main()
//{
//	char ch = 'a';
//	char* pc = &ch;
//	*pc = 'b';
//	printf("%c", ch);
//	return 0;
//}
//
//int main()
//{
//	const char* pstr = "hello,world";
//	printf("%s\n", pstr);
//	return 0;
//}
//
//void test(int (*p)[5], int row, int col)
//{
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < col; j++)
//		{
//			printf("%d ", *(*(p + i) + j));
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[5][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7},{4,5,6,7,8},{5,6,7,8,9} };
//	test(arr, 5, 5);
//	return 0;
//}


//void test()
//{
//	printf("hello");
//}
//int main()
//{
//	printf("%p\n", test);
//	printf("%p\n", &test);
//	return 0;
//}

//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int(*pf1)(int x, int y) = Add;//x y 也可以不用写进去 
//	printf("%d\n", (*pf1)(2, 3));
//	printf("%d\n", pf1(2, 3));
//	return 0;
//}
//
//int add(int x, int y)
//{
//	return x + y;
//}
//int sub(int x, int y)
//{
//	return x - y;
//}
//int mul(int x, int y)
//{
//	return x * y;
//}
//int div(int x, int y)
//{
//	return x / y;
//}
//int main()
//{
//	int x, y;//操作数
//	int input = 1;//进行选择
//	int ret = 0;//存放结果
//	int (*p[5])(int x, int y) = { 0,add,sub,mul,div };//转移表
//	do
//	{
//		//打印菜单
//		printf("***************************\n");
//		printf("**1.add   2.sub  **********\n");
//		printf("**3.mul   4.div  **********\n");
//		printf("**0.exit         **********\n");
//		printf("***************************\n");
//		printf("请选择:");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("输入操作数：");
//			scanf("%d %d", &x, &y);
//			ret = add(x, y);
//			printf("ret = %d\n", ret);
//			break;
//		case 2:
//			printf("输入操作数：");
//			scanf("%d %d", &x, &y);
//			ret = sub(x, y);
//			printf("ret = %d\n", ret);
//			break;
//		case 3:
//			printf("输入操作数：");
//			scanf("%d %d", &x, &y);
//			ret = mul(x, y);
//			printf("ret = %d\n", ret);
//			break;
//		case 4:
//			printf("输入操作数：");
//			scanf("%d %d", &x, &y);
//			ret = div(x, y);
//			printf("ret = %d\n", ret);
//			break;
//		case 0:
//			printf("退出\n");
//			break;
//		default:
//			printf("请重新选择\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}



int add(int x, int y)
{
	return x + y;
}
int sub(int x, int y)
{
	return x - y;
}
int mul(int x, int y)
{
	return x * y;
}
int div(int x, int y)
{
	return x / y;
}
int main()
{
	int x, y;//操作数
	int input = 1;//进行选择
	int ret = 0;//存放结果
	int (*p[5])(int x, int y) = { 0,add,sub,mul,div };//转移表
	do
	{
		//打印菜单
		printf("***************************\n");
		printf("**1.add   2.sub  **********\n");
		printf("**3.mul   4.div  **********\n");
		printf("**0.exit         **********\n");
		printf("***************************\n");
		printf("请选择:");
		scanf("%d", &input);
		if (input <= 4 && input >= 1)
		{
			printf("请输入操作数：");
			scanf("%d %d", &x, &y);
			ret = (*p[input])(x, y);
			printf("ret = %d\n", ret);
		}
		else if (input == 0)
		{
			printf("退出\n");
		}
		else
		{
			printf("请重新输入\n");
		}
	} while (input);
	return 0;
}
