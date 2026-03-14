#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

void queueInit(Queue* q)
{
	// 刚开始的时候，站台是空的，一节车厢（乘客）都没有
	// 所以队头 (front) 和队尾 (rear) 都指向 NULL（空）
	q->front = NULL;
	q->rear = NULL;

	printf("初始化成功，队列目前为空\n");
}

bool queueIsEmpty(Queue* q)
{
	if (q->front == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}