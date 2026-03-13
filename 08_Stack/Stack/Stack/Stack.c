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
	printf("成功初始化栈\n");
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

void stackPush(Stack* s, int value)
{
	if (stackIsFull(s))
	{
		int newCapacity = s->capacity * 2;
		//我们要先用一个临时钥匙 (newData) 来接新房子的钥匙
		int* newData = (int*)realloc(s->data, newCapacity * sizeof(int));

		if (newData == NULL)
		{
			perror("realloc failed");
			return;//放弃这次入栈
		}

		s->data = newData;
		s->capacity = newCapacity;
		printf("栈已扩容，新容量为:%d\n", s->capacity);
	}

	//移动游标并赋值
	s->top++;
	s->data[s->top] = value;
	printf("入栈成功:%d\n", value);
}

bool stackIsEmpty(Stack* s)
{
	// 逻辑：如果游标 top 还是当初初始化的 -1，说明里面一个数据都没有
	if (s->top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int stackPop(Stack* s)
{
	if (stackIsEmpty(s))
	{
		printf("出栈失败，栈是空的\n");
		return -1;
	}

	//先把栈顶的数据拿出来存到一个临时变量里
	int popValue = s->data[s->top];
	s->top--;//游标往下走一格，代表原来的栈顶元素被“抛弃”了
	return popValue;//把取出的数据返回给调用者
}

void stackDestroy(Stack* s)
{
	if (s->data != NULL)
	{
		free(s->data);
		s->data = NULL;
	}

	//把游标和容量都恢复到初始状态
	s->top = -1;
	s->capacity = 0;
	printf("栈成功销毁\n");
}