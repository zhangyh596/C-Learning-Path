#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
	int capacity;//薯片桶的长度（最大容量）
	int top;//记录当前位置
	int* data;//真正放薯片的空间（指针）
}Stack;

//初始化栈
void stackInit(Stack* s, int capacity);
//判断栈是否已满(辅助函数)
bool stackIsFull(Stack* s);
//