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

bool stackIsFull(Stack* s)
{ 
	// 逻辑：如果游标 top 已经到了数组的最后一个合法下标，就是满了。
	// 因为数组下标从 0 开始，所以最大容量为 capacity 时，最后一个下标是 capacity - 1。
	if (s->top == s->capacity - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}