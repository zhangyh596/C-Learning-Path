#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

int main()
{
	Stack myStack;
	stackInit(&myStack, 3);

	stackPush(&myStack, 10);
	stackPush(&myStack, 20);
	stackPush(&myStack, 30);

	//多塞一个，测试一下
	stackPush(&myStack, 40);

	printf("拿出的数据是%d\n", stackPop(&myStack));
	printf("拿出的数据是%d\n", stackPop(&myStack));

	//测试是否有可以入栈了
	stackPush(&myStack, 50);

	//清空栈并测试栈为空是否会拦截
	printf("拿出的数据是%d\n", stackPop(&myStack));
	printf("拿出的数据是%d\n", stackPop(&myStack));
	stackPop(&myStack);

	stackDestroy(&myStack);
	return 0;
}