#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 第 1 个结构体：链表的节点 (相当于“火车车厢”)
typedef struct Node
{
	int data;//存放真正的数据 (乘客)
	struct Node* next;//指向下一节车厢的绳子 (钩子)
}Node;


// 第 2 个结构体：队列管理器 (相当于“火车站长”)
typedef struct Queue
{
	Node* front;//队头指针：永远指向排在最前面的人（出队的地方）
	Node* rear;//队尾指针：永远指向排在最后面的人（入队的地方）
}Queue;

//初始化队列
void queueInit(Queue* q);
//判空
bool queueIsEmpty(Queue* q);
//辅助函数（创建新节点）
Node* createNode(int value);
//入队
void queuePush(Queue* q, int value);
//出队
int queuePop(Queue* p);