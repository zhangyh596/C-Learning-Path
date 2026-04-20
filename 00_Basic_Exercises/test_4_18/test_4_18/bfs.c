#define _CRT_SECURE_NO_WARNINGS 1

#include "bfs.h"

void initQueue(Queue* q)
{
	q->head = NULL;
	q->tail = NULL;
}

bool isEmpty(Queue* q)
{
	if (q->head == NULL)
	{
		return true;
	}
	return false;
}

void pushQueue(Queue* q, Point p)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = p;
	newnode->next = NULL;

	if (q->head == NULL)
	{
		q->head = q->tail = newnode;
	}
	else
	{
		q->tail->next = newnode;
		q->tail = newnode;
	}
}

Point popQueue(Queue* q)
{
	Node* tmp = q->head;
	Point p = tmp->data;
	q->head = q->head->next;

	if (q->head == NULL)
	{
		q->tail = NULL;
	}
	free(tmp);
	return p;
}

void freeQueue(Queue* q)
{
	while (!isEmpty(q))
	{
		popQueue(q);
	}
}