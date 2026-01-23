#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//
//union 
//{
//	int i;
//	char c;
//}un;
//int main()
//{
//	un.i = 1;
//	if (un.c == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	return 0;
//}
#include <stdio.h>

struct student
{
	char name[20];//名字
	int age;//年龄
	char sex[5];//性别
	char id[20];//学号
};

int main()
{
	struct student s = { .age = 20,.name = "zhangsan",.id = "2025",.sex = "男" };
	struct student* ps = &s;
	printf("name:%s\n", ps->name);
	printf("age:%d\n", ps->age);
	printf("sex:%s\n", ps->sex);
	printf("id:%s\n", ps->id);
	return 0;
}