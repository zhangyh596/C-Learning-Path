#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void bubble_sort(int arr[], int sz)
{
	int i = 0;
	for (int i = 0; i < sz - 1; i++)//只需要进行sz-1趟即可完成
	{
		int flag = 1;//假设已经有序
		for (int j = 0; j < sz - 1 - i; j++)//j只需要后面的sz-1-i个数比,前面的数已经有序
		{
			if (arr[j] > arr[j + 1])
			{
				flag = 0;//发送交换就把flag值赋成0，无序
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
		if (flag)//如果flag是1，即flag为真表示已经有序
			break;
	}
}
int main()
{
	int arr[10] = { 2,5,9,7,8,6,4,3,1,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	printf("交换前:");
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	bubble_sort(arr, sz);//冒泡排序
	printf("交换后:");
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

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
//void calc(int(*pf)(int x, int y))
//{
//	int ret = 0;
//	int x, y;
//	printf("输入操作数：");
//	scanf("%d %d", &x, &y);
//	ret = (*pf)(x, y);
//	printf("ret = %d\n", ret);
//}
//int main()
//{
//	int x, y;//操作数
//	int input = 1;//进行选择
//	int ret = 0;//存放结果
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
//			calc(add);
//			break;
//		case 2:
//			calc(sub);
//			break;
//		case 3:
//			calc(mul);
//			break;
//		case 4:
//			calc(div);
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


//#include <stdio.h>
//
//int compar(const void* p1, const void* p2)
//{
//	return (*(int*)p1) - (*((int*)p2));
//}
//int main()
//{
//	int arr[] = { 5,4,6,2,3,7,8,9,1,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]),compar);
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//
// }
