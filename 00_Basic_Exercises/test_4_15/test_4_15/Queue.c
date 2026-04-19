#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

void queueInit(Queue* q)
{
	q->front = NULL;
	q->rear = NULL;
}

bool queueIsEmpty(Queue* q)
{
	if (q->front == NULL)
	{
		return true;
	}
	return false;
}

Node* createNode(int val)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return NULL;
	}

	newnode->data = val;
	newnode->next = NULL;

	return newnode;
}

void queuePush(Queue* q, int val)
{
	Node* newnode = createNode(val);

	if (queueIsEmpty(q))
	{
		q->front = q->rear = newnode;
	}
	else
	{
		q->rear->next = newnode;
		q->rear = newnode;
	}
}

int queuePop(Queue* q)
{
	if (queueIsEmpty(q))
	{
		printf("队列为空，出队失败\n");
		return -1;
	}

	Node* popNode = q->front;
	int popVal = popNode->data;

	q->front = q->front->next;
	if (q->front == NULL)
	{
		q->rear = NULL;
	}

	free(popNode);

	return popVal;
}

void queueDestroy(Queue* q)
{
	while (!queueIsEmpty(q))
	{
		queuePop(q);
	}
}