#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

int main()
{
	Queue myQueue;
	
	queueInit(&myQueue);

	if (queueIsEmpty(&myQueue))
	{
		printf("队列为空\n");
	}
	else
	{
		printf("队列不为空\n");
	}

	queuePush(&myQueue, 1);

	queuePop(&myQueue);

	queueDestroy(&myQueue);
	return 0;
}