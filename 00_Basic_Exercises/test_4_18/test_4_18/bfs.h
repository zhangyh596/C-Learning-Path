#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Point
{
	int step;
	int x;
	int y;
}Point;

typedef struct Node
{
	Point data;
	struct Node* next;
}Node;

typedef struct Queue
{
	Node* head;
	Node* tail;
}Queue;

void initQueue(Queue* q);
bool isEmpty(Queue* q);
void pushQueue(Queue* q, Point p);
Point popQueue(Queue* q);
void freeQueue(Queue* q);