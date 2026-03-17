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

void queuePush(CircularQueue* q, int value)
{
	if (queueIsFull(q))
	{
		printf("队列已满，入列失败\n");
		return;
	}

	//把value装进下标为q->value的位置
	q->data[q->rear] = value;
	//【核心】：工人 (rear) 往前走一步，寻找下一个空位
	//如果走到了数组的尽头，% 取模运算会把他瞬间传送回下标 0
	q->rear = (q->rear + 1) % q->capacity;

	printf("%d入队成功\n", value);
}

int queuePop(CircularQueue* q)
{
	if (queueIsEmpty(q))
	{
		printf("出列失败，队列为空\n");
		return -1;
	}

	//拿到即将删除的那个值
	int popValue = q->data[q->front];

	//核心：旅客(front) 拿完行李，往前走一步，准备接下一个。
	//同样，走到要 % 传送回起点。
	q->front = (q->front + 1) % q->capacity;

	printf("%d出列成功\n", popValue);
	return popValue;
}

void queueDestroy(CircularQueue* q)
{
	if (q->data != NULL)
	{
		free(q->data);
		q->data = NULL;
	}

	q->front = 0;
	q->rear = 0;
	q->capacity = 0;
	printf("队列成功被销毁\n");
}