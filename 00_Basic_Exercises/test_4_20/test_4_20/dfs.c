#define _CRT_SECURE_NO_WARNINGS 1

#include "dfs.h"

void initStack(Stack* s, int initial_cap)
{
	s->data = (Point*)malloc(sizeof(Point) * initial_cap);
	if (s->data == NULL)
	{
		return;
	}

	s->top = -1;
	s->capacity = initial_cap;
}

bool isEmptyStack(Stack* s)
{
	if (s->top == -1)
	{
		return true;
	}
	return false;
}

void pushStack(Stack* s, Point p)
{
	if (s->top + 1 == s->capacity)
	{
		int newCapacity = s->capacity == 0 ? 4 : s->capacity * 2;
		Point* tmp = (Point*)realloc(s->data, sizeof(Point) * newCapacity);
		if (tmp == NULL)
		{
			return;
		}

		s->data = tmp;
		s->capacity = newCapacity;
	}

	s->top++;
	s->data[s->top] = p;
}

Point popStack(Stack* s)
{
	Point p = s->data[s->top];
	s->top--;
	return p;
}

void freeStack(Stack* s)
{
	if (s->data != NULL)
	{
		free(s->data);
		s->data = NULL;
	}
	s->top = -1;
	s->capacity = 0;
}