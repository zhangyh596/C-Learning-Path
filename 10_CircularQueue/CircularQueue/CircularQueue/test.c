#define _CRT_SECURE_NO_WARNINGS 1

#include "CircularQueue.h"

int main()
{
	CircularQueue MyQueue;
	queueInit(&MyQueue, 5);

	queuePush(&MyQueue, 1);
	queuePush(&MyQueue, 2);
	queuePush(&MyQueue, 3);
	queuePush(&MyQueue, 4);
	queuePush(&MyQueue, 5);

	queuePush(&MyQueue, 1);

	queuePop(&MyQueue);
	queuePop(&MyQueue);
	queuePop(&MyQueue);
	queuePop(&MyQueue);
	queuePop(&MyQueue);

	queuePop(&MyQueue);


	return 0;
}