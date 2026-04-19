#define _CRT_SECURE_NO_WARNINGS 1

//#include "Stack.h"
//
//int main()
//{
//	Stack myStack;
//	stackInit(&myStack, 3);
//
//	stackPush(&myStack, 1);
//	stackPush(&myStack, 2);
//	stackPush(&myStack, 3);
//	stackPush(&myStack, 4);
//
//	stackPop(&myStack);
//
//	stackDestroy(&myStack);
//	return 0;
//}

#include "Queue.h"

int main()
{
	Queue myQueue;
	queueInit(&myQueue);

	queuePush(&myQueue, 1);
	queuePush(&myQueue, 2);
	queuePush(&myQueue, 3);
	queuePush(&myQueue, 4);

	int val = queuePop(&myQueue);
	printf("%d\n", val);

	queueDestroy(&myQueue);
	return 0;
}