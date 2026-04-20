#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Point
{
	int x;
	int y;
}Point;

typedef struct Stack
{
	Point* data;
	int top;
	int capacity;
}Stack;

void initStack(Stack* s, int initial_cap);
bool isEmptyStack(Stack* s);
void pushStack(Stack* s, Point p);
Point popStack(Stack* s);
void freeStack(Stack* s);