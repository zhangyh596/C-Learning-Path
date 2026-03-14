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
	//只要队头没有指向任何车厢，说明队列是空的
	if (q->front == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//辅助函数（创建新节点）
Node* createNode(int value)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	//检测是否malloc成功
	if (newNode == NULL)
	{
		perror("malloc failed");
		return NULL;
	}

	newNode->data = value;
	newNode->next = NULL;

	return newNode;
}

void queuePush(Queue* q, int value)
{
	Node* newNode = createNode(value);
	if (newNode == NULL)
	{
		return;
	}

	//入队情况要分类讨论
	if (queueIsEmpty(q))
	{
		// 【情况 A：站台里空无一人，他是第一个来的！】
		// 既然只有他一个人，那他既是排在最前面的 (队头)，也是排在最后面的 (队尾)
		q->front = newNode;
		q->rear = newNode;
	}
	else
	{
		// 【情况 B：队伍里已经有其他人了】
		// 让原来排在队伍最后的那个人 (q->rear)，向后扔出绳子 (next)，挂住这个新车厢
		q->rear->next = newNode;
		q->rear = newNode;
	}
}