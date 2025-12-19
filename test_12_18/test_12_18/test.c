#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int n = 5;
//	int* arr = (int*)malloc(n * sizeof(int));
//	if (arr == NULL)//检查是否为空指针
//	{
//		printf("内存分配失败\n");
//		return 1;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		arr[i] = i + 1;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	free(arr);
//	arr = NULL;
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int n = 5;
//	int* arr = (int*)calloc(n, sizeof(int));
//	if (NULL == arr)
//	{
//		printf("内存分配失败\n");
//		return 1;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	free(arr);
//	arr = NULL;
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n = 3;
	int* arr = (int*)malloc(n * sizeof(int));
	if (NULL == arr)
	{
		printf("内存分配失败\n");
		return 1;
	}
	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}
	printf("扩容前的数组：");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	int new_n = 5;
	//错误写法
	//int* arr = (int*)realloc(arr,new_n*sizeof(int));
	
	//正确写法
	int* new_arr = (int*)realloc(arr, new_n * sizeof(int));
	if (NULL == new_arr)
	{
		printf("内存分配失败\n");
		free(arr);//原内存手动释放
		arr = NULL;
		return 1;
	}
	arr = new_arr;
	for (int i = n; i < new_n; i++)
	{
		arr[i] = i + 1;
	}
	printf("扩容后的数组：");
	for (int i = 0; i < new_n; i++)
	{
		printf("%d ", arr[i]);
	}
	free(arr);
	arr = NULL;
	return 0;
}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int* p = (int*)malloc(INT_MAX);
//	*p = 20;
//	free(p);
//	return 0;
//}

//void test()
//{
//	int i = 0;
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (NULL == p)
//	{
//		printf("内存分配失败\n");
//	}
//	for (int i = 0; i <= 10; i++)//多访问了一个元素
//	{
//		p[i] = i;
//	}
//	free(p);
//	p = NULL;
//}

//void test()
//{
//	int a = 10;
//	int* p = &a;
//	free(p);
//}

//void test()
//{
//	int* p = (int*)malloc(100);
//	p++;
//	free(p);//p不再指向动态内存的起始地址
//}

//void test()
//{
//	int* p = (int*)malloc(100);
//	free(p);
//	free(p);
//}

//void test()
//{
//	int* p = (int*)malloc(100);
//	if (NULL != p)
//	{
//		*p = 20;
//	}
//}