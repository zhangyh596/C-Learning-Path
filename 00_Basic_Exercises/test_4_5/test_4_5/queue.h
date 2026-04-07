#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
	int x;
	int y;
	//int step;
}Node;

typedef struct
{
	Node* data;      // 指向动态分配的连续内存
	int head;       // 队头索引
	int tail;       // 队尾索引（指向下一个可插入的位置）
	int capacity;   // 队列的最大容量
} NodeQueue;

// 你需要实现的接口：
NodeQueue* queue_create(int capacity);
bool queueIsEmpty(NodeQueue* q);
bool queueIsFull(NodeQueue* q);
bool queue_push(NodeQueue* q, Node value);
bool queue_pop(NodeQueue* q, Node* out_value);
void queueDestroy(NodeQueue* q);