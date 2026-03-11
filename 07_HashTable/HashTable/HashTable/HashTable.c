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