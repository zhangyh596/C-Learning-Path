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

bool queueIsEmpty(CircularQueue* q)
{
	//当front和rear重合即一个人也没有为空
	if (q->front == q->rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool queueIsFull(CircularQueue* q)
{
	//【核心心法】：让rear在脑海里往前“试探性”地走一步。
	//如果往前走一步刚好撞上了front，说明转盘只剩最后那个“必须浪费的空位”了，队列已满！
	int nextRear = (q->rear + 1) % q->capacity;

	if (nextRear == q->front)
	{
		return true;
	}
	else
	{
		return false;
	}
}