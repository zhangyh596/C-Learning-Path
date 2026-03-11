#pragma once

#include <stdio.h>

typedef struct Node
{
	char* key;//你的名字（比如“apple”）
	int value;//你的存款（比如100）
	struct Node* next;//重点！用来挂下一个袋子
}Node;

typedef struct HashTable
{
	int size;//记录柜子一共有多少个抽屉
	Node** enties;//重点！这是抽屉的集合
}HashTable;