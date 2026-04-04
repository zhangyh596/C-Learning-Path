#define _CRT_SECURE_NO_WARNINGS 1

#include "Point.h"

void init_vec(Vector* v)
{
	v->data = (Point*)malloc(sizeof(Point) * 2);
	v->size = 0;
	v->capacity = 2;
}

void push_vec(Vector* v, Point p)
{
	if (v->size == v->capacity)
	{
		int newCapacity = v->capacity * 2;
		Point* temp = (Point*)realloc(v->data, newCapacity * sizeof(Point));
		if (temp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		v->data = temp;
		v->capacity = newCapacity;
	}

	v->data[v->size] = p;
	(v->size)++;
}

int compare_point(const void* a, const void* b)
{
	const Point* p1 = (const Point*)a;
	const Point* p2 = (const Point*)b;

	int l1 = abs(p1->x) + abs(p1->y);
	int l2 = abs(p2->x) + abs(p2->y);
	if (l1 > l2)
	{
		return 1;
	}
	else if (l1 < l2)
	{
		return -1;
	}
	else
	{
		if (p1->x > p2->x)
		{
			return 1;
		}
		else if (p1->x < p2->x)
		{
			return -1;
		}
		else
		{
			if (p1->y > p2->y)
			{
				return 1;
			}
			else if (p1->y < p2->y)
			{
				return -1;
			}
			else
			{
				return 0;
			}
		}
	}
}

void destroy_vec(Vector* v)
{
	free(v->data);
	v->data = NULL;
	v->size = 0;
	v->capacity = 0;
}