#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int main()
//{
//	char src[] = "hello,world";
//	char dest[20];
//	memcpy(dest, src, strlen(src) + 1);
//	printf("%s", dest);
//	return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//	int src[5] = { 1,2,3,4,5 };
//	int dest[5];
//	memcpy(dest, src, sizeof(src));
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d ", dest[i]);
//	}
//	return 0;
//}

//#include <stdio.h>
//
//typedef struct 
//{
//	int id;
//	char name[20];
//	int age;
//}student;
//
//int main()
//{
	//student s1 = { 2530,"zhangsan",18 };
	//student s2;
	//memcpy(&s2, &s1, sizeof(student));
	//printf("%d %s %d", s2.id, s2.name, s2.age);//学生2复制成功
//	return 0;
//}
//
//#include <stdio.h>
//void* my_memcpy(void* dest, const void* src, size_t n)
//{
//	void* ret = dest;
//	while (n--)
//	{
//		*(char*)dest = *(char*)src;
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//	return ret;
//}
//
//typedef struct 
//{
//	int id;
//	char name[20];
//	int age;
//}student;
//
//int main()
//{
//	student s1 = { 2530,"zhangsan",18 };
//	student s2;
//	my_memcpy(&s2, &s1, sizeof(student));
//	printf("%d %s %d", s2.id, s2.name, s2.age);//学生2复制成功
//	return 0;
//}
//
//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	memmove(arr1 + 2, arr1, 20);//在arr1+2的位置向后复制初始arr1的后20个字节
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr1[i]);//得到1 2 1 2 3 4 5 8 9 10
//	}
//	return 0;
//}

//#include <stdio.h>
//
//void* my_memmove(void* dest, const void* src, size_t n)
//{
//	void* ret = dest;
//	if (dest <= src)//如果dest的地址在src前面，从前向后复制（重叠时）
//	{
//		while (n--)
//		{
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else//如果dest的地址在src后面，从后面往前面复制（重叠时）由于不重叠时两种方式都可以，所以归类到else里面
//	{
//		dest = (char*)dest + n - 1;
//		src = (char*)src + n - 1;
//		while (n--)
//		{
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest - 1;
//			src = (char*)src - 1;
//		}
//	}
//	return ret;
//}
//int main()
//{
//
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	memmove(arr1 + 2, arr1, 20);//在arr1+2的位置向后复制初始arr1的后20个字节
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr1[i]);//得到1 2 1 2 3 4 5 8 9 10
//	}
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int arr[10];
//	memset(arr, 0, sizeof(arr));
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 1,2,3,4,6 };
//
//	int ret = memcmp(arr1, arr2, sizeof(arr1));
//	printf("%d", ret);
//	return 0;
//}

#include <stdio.h>

int my_memcmp(const void* ptr1, const void* ptr2, size_t n)
{
	if (n == 0)
	{
		return 0;
	}
	const char* p1 = (const char*)ptr1;
	const char* p2 = (const char*)ptr2;
	for (int i = 0; i < n; i++)
	{
		if (p1[i] != p2[i])
		{
			return (int)(p1[i]) - (int)(p2[i]);
		}
	}
	return 0;
}
int main()
{
		int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 1,2,3,4,6 };

	int ret = my_memcmp(arr1, arr2, sizeof(arr1));
	printf("%d", ret);
	return 0;
}