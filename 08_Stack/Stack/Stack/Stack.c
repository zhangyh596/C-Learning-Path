#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

// s 代表我们要操作的那个栈（通过指针传进来）
// capacity 是用户告诉我们，这个栈要多大
void stackInit(Stack* s, int capacity)
{
	s->data = (int*)malloc(capacity * sizeof(int));

	if (s->data == NULL)
	{
		perror("malloc failed");
		exit(1);//强行退出
	}

	s->top = -1;//说明现在是空的
	s->capacity = capacity;//记住最大容量
}