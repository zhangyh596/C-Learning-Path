#define _CRT_SECURE_NO_WARNINGS 1

#include "CircularQueue.h"

void queueInit(CircularQueue* q, int maxSize)
{
	//【核心心法】：你想装 maxSize 个人，我底层必须开辟 maxSize + 1 个位置！
	//那个多出来的位置，就是为了防止 front 追上 rear 时分不清是空还是满。
	q->capacity = maxSize + 1;

	//此时malloc一块空间之后不会再用malloc
	q->data = (int*)malloc(sizeof(int) * q->capacity);
	if (q->data == NULL)
	{
		perror("malloc failed");
		return;
	}

	q->front = 0;
	q->rear = 0;

	printf("环形队列初始化成功，真实容量为%d，可装载人数为%d\n", q->capacity, maxSize);
}