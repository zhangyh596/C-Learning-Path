#define _CRT_SECURE_NO_WARNINGS 1

#include "HashTable.h"

int main()
{
	//造一个有10个抽屉的柜子
	HashTable* ht = create_table(10);

	//插入内容
	insert(ht, "apple", 100);
	insert(ht, "banana", 200);
	insert(ht, "pear", 300);

	//苹果涨价了
	insert(ht, "apple", 150);

	//查找不同的水果的价钱（检测查找函数）
	int money = 0;
	if (search(ht, "apple", &money))
	{
		printf("找到了，apple的价格是%d\n", money);
	}
	else
	{
		printf("没找到apple\n");
	}

	//删除
	printf("正在删除banana...\n");
	delete_key(ht, "banana");
	if (search(ht, "banana", &money))
	{
		printf("找到了，banana的价格是%d\n", money);
	}
	else
	{
		printf("没找到banana，删除成功\n");
	}

	free_table(ht);
	ht = NULL;
	printf("柜子已释放，无内存泄露\n");
	return 0;
}