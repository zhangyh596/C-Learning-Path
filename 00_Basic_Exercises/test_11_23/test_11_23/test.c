#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
////创建结构体
//struct stu
//{
//	char name[20];
//	int age;
//};
////创建通过name比较的回调函数
//int compar_by_name(const void* p1,const void* p2)
//{
//	return strcmp(((struct stu*)p1)->name, ((struct stu*)p2)->name);
//}
//int main()
//{
//	struct stu s[] = { {"张三",20},{"李四",30},{"王五",18} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	qsort(s, sz, sizeof(s[0]), compar_by_name);
//	return 0;
//}

#include <stdio.h>

//回调函数
int compar(const void* p1, const void* p2)
{
	//将void*强制转换为比较的类型
	return (*(int*)p1 - *(int*)p2);
}
//交换函数（任意类型都可以，所以用char类型逐字节交换）
//size用于接收每个元素的大小
void swap(void* p1, void* p2, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		char tmp = *((char*)p1 + i);
		*((char*)p1 + i) = *((char*)p2 + i);
		*((char*)p2 + i) = tmp;
	}
}
//参数类型和qsort一样
void my_qsort(void* base, size_t count, size_t size, int(*cmp)(void*, void*))
{
	//排序轮数
	for (int i = 0; i < count - 1; i++)
	{
		//比较相邻元素
		for(int j = 0;j<count-1-i;j++)
		{
			//(char *)base + j*size 是第j个元素的地址
			//(char *)base + (j + 1)*size 是第j+1个元素的地址

			//使用比较函数判断是否需要交换
			if (cmp((char*)base + j * size, (char*)base + (j + 1) * size) > 0)
			{
				//需要交换则手动交换
				swap((char*)base + j * size, (char*)base + (j + 1) * size, size);
			}
		}
	}
}
int main()
{
	//排序一个整型数组
	int arr[] = { 4,5,3,2,8,9,6,1,10,7 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	my_qsort(arr, sz, sizeof(arr[0]), compar);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}