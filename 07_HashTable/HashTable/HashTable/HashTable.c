#define _CRT_SECURE_NO_WARNINGS 1

#include "HashTable.h"

unsigned int hash(const char* key, int table_size)
{
	unsigned long int value = 5381;//魔法初始数字
	unsigned int i = 0;
	unsigned int key_len = strlen(key);

	//核心
	for (int i = 0; i < key_len; i++)
	{
		value = value * 33 + key[i];
	}

	//挤进柜子里面
	return value % table_size;
}

HashTable* create_table(int size)
{
	//打造柜子的外框
	HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
	ht->size = size;

	//打造柜子里的一排抽屉（钩子）
	ht->entries = (Node**)malloc(sizeof(Node*) * size);

	//把所有钩子置空
	for (int i = 0; i < size; i++)
	{
		ht->entries[i] = NULL;
	}

	//结束
	return ht;
}