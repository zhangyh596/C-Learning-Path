#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//struct s1
//{
//	char c1;//偏移0，占1字节
//	int i;//偏移到4，（中间浪费了三个字节），占4个字节
//	char c2;//偏移8，占1字节
//};//最终需是最大对齐数的整数倍，故结构体大小是12（再次浪费了三个字节）
//struct s2
//{
//	char c1;//偏移0，占1字节
//	struct s1 s;//偏移到4，（中间浪费了三个字节），占12个字节
//	double d;//偏移16，占8字节
//};//24是最大对齐数的整数倍，故结构体大小是24
//int main()
//{
//	printf("%d\n", sizeof(struct s1));
//	printf("%d\n", sizeof(struct s2));
//	return 0;
//}

//#include <stdio.h>
//#pragma pack(1)//设置默认对齐数为1
//struct s
//{
//	char c1;//偏移0，占1字节
//	int i;//偏移1，占4字节
//	char c2;//偏移5，占1字节
//};//结构体总大小6是1的整数倍
//int main()
//{
//	printf("%d", sizeof(struct s));
//	return 0;
//}

//#include <stdio.h>
//
//struct s
//{
//	int arr[1000];
//	int num;
//};
//struct s s1 = { {1,2,3,4},1000 };//给结构体初始化
////结构体传参
//void print1(struct s s1)
//{
//	printf("%d\n", s1.num);
//}
////结构体传址
//void print2(struct s* ps)
//{
//	printf("%d\n", ps->num);
//}
//int main()
//{
//	print1(s1);
//	print2(&s1);
//	return 0;
//}
//
//#include <stdio.h>
//
//struct S
//{
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 6;	
//};
//struct S s = { 0 };
//
//int main()
//{
//	s.a = 10;
//	s.b = 12;
//	s.c = 3;
//	s.d = 4;
//	return 0;
//}

#include <stdio.h>

struct A
{
	int a : 2;
	int b : 5;
	int c : 10;
	int d : 30;
};
int main()
{
	struct A s = { 0 };
	//错误示范
	//scanf("%d", &s.a);
	//正确写法
	int a = 0;
	scanf("%d", &a);
	s.a = a;
	return 0;
}