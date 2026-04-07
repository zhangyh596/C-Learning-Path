#define _CRT_SECURE_NO_WARNINGS 1

#include "queue.h"

NodeQueue* queue_create(int capacity)
{
	NodeQueue* queue = (NodeQueue*)malloc(sizeof(NodeQueue));
	if (queue == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	queue->capacity = capacity + 1;

	queue->data = (Node*)malloc(sizeof(Node) * queue->capacity);
	if (queue->data == NULL)
	{
		perror("malloc fail");
		return NULL;
	}

	queue->head = 0;
	queue->tail = 0;

	return queue;
}

bool queueIsEmpty(NodeQueue* q)
{
	if (q->head == q->tail)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool queueIsFull(NodeQueue* q)
{
	if ((q->tail + 1) % q->capacity == q->head)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool queue_push(NodeQueue* q, Node value)
{
	if (queueIsFull(q))
	{
		return false;
	}

	q->data[q->tail] = value;
	q->tail = (q->tail + 1) % q->capacity;
	return true;
}

bool queue_pop(NodeQueue* q, Node* out_value)
{
	if (q == NULL || out_value == NULL || queueIsEmpty(q))
	{
		return false;
	}

	*out_value = q->data[q->head];

	q->head = (q->head + 1) % q->capacity;
	return true;
}

void queueDestroy(NodeQueue* q)
{
	if (q->data != NULL)
	{
		free(q->data);
		q->data = NULL;
	}

	free(q);
}