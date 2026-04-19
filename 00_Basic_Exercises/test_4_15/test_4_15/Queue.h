#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

typedef struct Queue
{
	Node* front;
	Node* rear;
}Queue;

void queueInit(Queue* q);
bool queueIsEmpty(Queue* q);
Node* createNode(int val);
void queuePush(Queue* q, int val);
int queuePop(Queue* q);
void queueDestroy(Queue* q);