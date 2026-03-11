#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	char* key;//你的名字（比如“apple”）
	int value;//你的存款（比如100）
	struct Node* next;//重点！用来挂下一个袋子
}Node;

typedef struct HashTable
{
	Node** entries;//重点！这是抽屉的集合
	int size;//记录柜子一共有多少个抽屉
	int count;//新增：检测当前挂了多少个袋子
}HashTable;

//辅助函数创建一个新节点
Node* create_node(const char* key, int value);
//动态扩容函数
void resize(HashTable* ht);
//哈希函数
unsigned int hash(const char* key, int table_size);
//初始化哈希表
HashTable* create_table(int size);
//插入（或更新）键值对
void insert(HashTable* ht, const char* key, int value);
//查找
int search(HashTable* ht, const char* key, int* out_value);
//删除
void delete_key(HashTable* ht, const char* key);
//清理和释放内存
void free_table(HashTable* ht);