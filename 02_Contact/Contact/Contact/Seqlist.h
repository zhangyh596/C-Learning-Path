#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;

typedef struct Seqlist
{
	SLDataType* a;
	int size;//数据个数
	int capacity;//空间容量
};
