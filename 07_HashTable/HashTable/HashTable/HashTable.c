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

void resize(HashTable* ht)
{
	int old_size = ht->size;
	int new_size = old_size * 2;

	//打造一排全新的抽屉
	Node** new_entries = (Node**)malloc(sizeof(Node*) * new_size);
	for (int i = 0; i < new_size; i++)
	{
		new_entries[i] = NULL;//先对每个新抽屉置空
	}

	Node** old_entries = ht->entries;//拿到旧抽屉

	//搬家：挨个翻旧抽屉
	for (int i = 0; i < old_size; i++)
	{
		Node* entry = old_entries[i];//抓住旧抽屉上的袋子

		while (entry)
		{
			// 极其致命的拆迁铁律又来了：拔下来之前，先看下一个袋子是谁！
			Node* next_entry = entry->next;

			// 重新算号 (Rehash)：
			// 以前是除以 10 取余数，现在是除以 20 取余数。
			// 比如算出来原本是 23，以前在 3 号抽屉，现在应该去 3 号抽屉；
			// 如果原本是 33，以前在 3 号抽屉，现在就要去 13 号抽屉了！
			unsigned int new_slot = hash(entry->key, new_size);

			//头插法插入
			entry->next = new_entries[new_slot];
			new_entries[new_slot] = entry;

			entry = entry->next;
		}
	}

	//销毁旧抽屉
	free(old_entries);

	// 更新系统：让大柜子换上新的核心
	ht->entries = new_entries;
	ht->size = new_size;
	// ht->count 不变！因为袋子的总数还是那么多，只是住得更宽敞了。
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

	//当前还没挂入袋子
	ht->count = 0;

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
	// 警报器：如果袋子数量达到了抽屉数量的 75%
	// 比如 10 个抽屉挂了 7 个以上的袋子，说明快挤爆了！
	if (ht->count >= ht->size * 0.75) {
		// 瞬间触发大搬家！在后台偷偷扩容成 20 个抽屉
		resize(ht);
	}

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

	//袋子数量+1
	ht->count++;
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

void free_table(HashTable* ht)
{
	//挨个拉开所有抽屉
	for (int i = 0; i < ht->size; i++)
	{
		Node* entry = ht->entries[i];//抓住当前抽屉上的第一个袋子

		while (entry)
		{
			//先记录entry的下一个袋子，防止找不到了
			Node* next_entry = entry->next;

			free(entry->key);
			free(entry);

			entry = next_entry;
		}
	}

	//所有的袋子和名字都被清空了再来清空抽屉
	free(ht->entries);
	//清空柜子,最后要在函数里面自己手动置空，写ht = NULL;
	free(ht);
}