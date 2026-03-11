#define _CRT_SECURE_NO_WARNINGS 1

#include "HashTable.h"

//辅助函数（创建一个新节点）
Node* create_node(const char* key, int value)
{
	//做一个空袋子
	Node* new_node = (Node*)malloc(sizeof(Node));

	//准备写上名字
	new_node->key = (char*)malloc(strlen(key) + 1);
	strcpy(new_node->key, key);

	//把钱放进去
	new_node->value = value;

	//袋子下面的钩子暂时没有东西
	new_node->next = NULL;

	return new_node;
}

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

void insert(HashTable* ht, const char* key, int value)
{
	//询问前台去几号抽屉
	unsigned int slot = hash(key, ht->size);

	//走到那个抽屉看看现在的挂钩挂着什么
	Node* entry = ht->entries[slot];

	//顺着挂钩往下翻看看有没有同一个名字的（处理冲突/更新）
	while (entry)
	{
		if (strcmp(entry->key, key) == 0)
		{
			//找到同名的袋子
			entry->value = value;//直接更新值
			return;
		}
		entry = entry->next;
	}

	//翻到底都没有同名的，那就拿一个新袋子
	Node* new_node = create_node(key, value);

	//采用头插法，尾插还得遍历到尾节点和分类讨论
	new_node->next = ht->entries[slot];
	ht->entries[slot] = new_node;
}

int search(HashTable* ht, const char* key, int* out_value)
{
	//问前台要去几号柜子找
	unsigned int slot = hash(key, ht->size);

	//走到抽屉前，抓住最上面的第一个袋子
	Node* entry = ht->entries[slot];

	//开始顺着钩子往下找
	while (entry)
	{
		if (strcmp(entry->key, key) == 0)
		{
			*out_value = entry->value;
			return 1;//1代表找到了
		}
		entry = entry->next;
	}
	return 0;//0代表没找到
}

void delete_key(HashTable* ht, const char* key)
{
	unsigned int slot = hash(key, ht->size);
	Node* entry = ht->entries[slot];//当前正在看的袋子
	Node* prev = NULL;//上一个看过的袋子（关键）

	while (entry)
	{
		if (strcmp(entry->key, key) == 0)
		{
			//分类讨论删除情况
			if (prev == NULL)
			{
				// 情况一：它是抽屉上的第一个袋子！
			    // 直接把抽屉的主挂钩，挂到它的下一个袋子上。
				ht->entries[slot] = entry->next;
			}
			else
			{
				// 情况二：它挂在半中间！
				// 让上一个袋子的钩子，越过它，直接勾住它的下一个袋子。
				prev->next = entry->next;
			}
			//顺序不能反
			free(entry->key);
			free(entry);
			return;
		}

		//没找到的话继续往下找
		prev = entry;
		entry = entry->next;
	}
}