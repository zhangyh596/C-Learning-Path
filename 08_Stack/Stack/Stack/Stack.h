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
//判断栈是否已满（辅助函数）
bool stackIsFull(Stack* s);
//入栈
void stackPush(Stack* s, int value);
//判断栈是否为空（辅助函数）
bool stackIsEmpty(Stack* s);
//出栈
int stackPop(Stack* s);
//销毁栈
void stackDestroy(Stack* s);