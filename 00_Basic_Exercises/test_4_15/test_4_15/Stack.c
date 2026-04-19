#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

void stackInit(Stack* s, int capacity)
{
	s->data = (int*)malloc(capacity * sizeof(int));
	if (s->data == NULL)
	{
		perror("malloc fail");
		return;
	}

	s->top = -1;
	s->capacity = capacity;
}

bool stackIsFull(Stack* s)
{
	if (s->top == s->capacity - 1)
	{
		return true;
	}
	return false;
}

void stackPush(Stack* s, int val)
{
	if (stackIsFull(s))
	{
		int newCapacity = s->capacity == 0 ? 4 : s->capacity * 2;
		int* tmp = (int*)realloc(s->data, newCapacity * sizeof(int));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}

		s->data = tmp;
		s->capacity = newCapacity;
	}

	s->top++;
	s->data[s->top] = val;
}

bool stackIsEmpty(Stack* s)
{
	if (s->top == -1)
	{
		return true;
	}
	return false;
}

int stackPop(Stack* s)
{
	if (stackIsEmpty(s))
	{
		printf("栈是空的，出栈失败\n");
		return -1;
	}

	int popVal = s->data[s->top];
	s->top--;
	return popVal;
}

void stackDestroy(Stack* s)
{
	if (s->data != NULL)
	{
		free(s->data);
		s->data = NULL;
	}

	s->top = -1;
	s->capacity = 0;
}