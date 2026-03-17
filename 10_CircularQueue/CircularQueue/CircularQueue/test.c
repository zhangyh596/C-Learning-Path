#define _CRT_SECURE_NO_WARNINGS 1

#include "CircularQueue.h"

int main()
{
	CircularQueue MyQueue;
	queueInit(&MyQueue, 5);
	return 0;
}