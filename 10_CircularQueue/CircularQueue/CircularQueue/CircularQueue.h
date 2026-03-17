#pragma once

#include <stdio.h>
#include <stdbool.h>

typedef struct CircularQueue
{
	int* data;//待会用malloc获取一块连续的数字空间
	int capacity;//记录这个队列的总容量
	int front;//队头游标，排在最前面的数据
	int rear;//队尾游标，永远指向下一个空位
}CircularQueue;

//初始化环形队列
void queueInit(CircularQueue* q, int maxSize);