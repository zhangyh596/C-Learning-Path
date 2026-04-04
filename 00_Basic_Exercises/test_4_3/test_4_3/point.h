#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
}Point;

typedef struct {
	Point* data;
	int size;
	int capacity;
}Vector;

//初始化结构体
void init_vec(Vector* v);
//检查容量
void push_vec(Vector* v, Point p);
//回调函数
int compare_point(const void* a, const void* b);
//销毁
void destroy_vec(Vector* v);