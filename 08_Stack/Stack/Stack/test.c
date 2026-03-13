#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

int main()
{
	Stack myStack;
	stackInit(&myStack, 3);

	stackPush(&myStack, 10);
	stackPush(&myStack, 20);
	stackPush(&myStack, 30);
	stackPush(&myStack, 40);

	while (!stackIsEmpty(&myStack))
	{
		printf("出栈数据：%d\n", stackPop(&myStack));
	}
	stackPop(&myStack);

	stackDestroy(&myStack);
	return 0;
}