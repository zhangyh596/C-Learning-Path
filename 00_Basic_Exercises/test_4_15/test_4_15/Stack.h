#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack
{
	int capacity;
	int top;
	int* data;
}Stack;

void stackInit(Stack* s, int capacity);
bool stackIsFull(Stack* s);
void stackPush(Stack* s, int val);
bool stackIsEmpty(Stack* s);
int stackPop(Stack* s);
void stackDestroy(Stack* s);