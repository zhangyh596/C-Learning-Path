#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

struct seqList
{
	int* a;
	int size;
	int capacity;
};

void init(struct seqList* list, int capacity)
{
	list->a = (int*)malloc(sizeof(int) * capacity);
	list->size = 0;
	list->capacity = capacity;
}

void resize(struct seqList* list)
{
	if (list->size == list->capacity)
	{
		int newcapacity = list->capacity == 0 ? 4 : list->capacity * 2;
		int* tmp = (int*)realloc(list->a, sizeof(int) * newcapacity);
		if (tmp == NULL)
		{
			printf("扩容失败\n");
			return;
		}
		list->a = tmp;
		list->capacity = newcapacity;
	}
}

void destroy(struct seqList* list)
{
	free(list->a);
	list->a = NULL;
	list->size = 0;
	list->capacity = 0;
}

void insert(struct seqList* list, int index, int k)
{
	if (index < 0 || index > list->size) return;

	resize(list);

	for (int i = list->size; i > index; i--)
	{
		list->a[i] = list->a[i - 1];
	}

	list->a[index] = k;
	list->size++;
}

void delete(struct seqList* list, int index)
{
	if (index < 0 || index >= list->size) return;
	for (int i = index; i < list->size - 1; i++)
	{
		list->a[i] = list->a[i + 1];
	}
	list->size--;
}

int cmp(const void* p1, const void* p2)
{
	if (*(int*)p1 > *(int*)p2)
	{
		return 1;
	}
	else if (*(int*)p1 == *(int*)p2)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}
void sort(struct seqList* list)
{
	qsort(list->a, list->size, sizeof(int), cmp);
}

struct seqList* merge_unique(struct seqList* list1, struct seqList* list2)
{
	struct seqList* list = (struct seqList*)malloc(sizeof(struct seqList));
	init(list, list1->size + list2->size);

	int size1 = 0, size2 = 0;
	while (size1 < list1->size && size2 < list2->size)
	{
		int candidate;

		if (list1->a[size1] < list2->a[size2])
		{
			candidate = list1->a[size1];
			size1++;
		}
		else if (list1->a[size1] == list2->a[size2])
		{
			candidate = list1->a[size1];
			size1++;
			size2++;
		}
		else
		{
			candidate = list2->a[size2];
			size2++;
		}

		if (list->size == 0)
		{
			list->a[list->size] = candidate;
			list->size++;
			continue;
		}

		if (list->a[list->size - 1] != candidate)
		{
			list->a[list->size] = candidate;
			list->size++;
		}
	}

	if (size1 < list1->size)
	{
		while (size1 < list1->size)
		{
			int candidate = list1->a[size1];
			size1++;

			if (list->size == 0)
			{
				list->a[list->size] = candidate;
				list->size++;
				continue;
			}

			if (list->a[list->size - 1] != candidate)
			{
				list->a[list->size] = candidate;
				list->size++;
			}
		}
	}
	else
	{
		while (size2 < list2->size)
		{
			int candidate = list2->a[size2];
			size2++;

			if (list->size == 0)
			{
				list->a[list->size] = candidate;
				list->size++;
				continue;
			}

			if (list->a[list->size - 1] != candidate)
			{
				list->a[list->size] = candidate;
				list->size++;
			}
		}
	}
	return list;
}

void print_list(const char* name, struct seqList* list)
{
	printf("%s (size:%d, cap:%d): ", name, list->size, list->capacity);
	for (int i = 0; i < list->size; i++) 
	{
		printf("%d ", list->a[i]);
	}
	printf("\n");
}

int main()
{
	// 1. 测试初始化与动态扩容
	struct seqList list1, list2; // 直接在栈上分配结构体，更省事
	init(&list1, 2);
	init(&list2, 2);

	// 2. 插入无序且有重复的数据
	insert(&list1, 0, 5);
	insert(&list1, 1, 1);
	insert(&list1, 2, 3); // 会触发扩容
	insert(&list1, 3, 3);
	insert(&list1, 4, 1);

	insert(&list2, 0, 6);
	insert(&list2, 1, 3);
	insert(&list2, 2, 2);
	insert(&list2, 3, 2);

	printf("--- 排序前 ---\n");
	print_list("List1", &list1);
	print_list("List2", &list2);

	// 3. 测试排序
	sort(&list1);
	sort(&list2);

	printf("\n--- 排序后 ---\n");
	print_list("List1", &list1);
	print_list("List2", &list2);

	// 4. 测试合并去重 (记得先把上面的死循环 Bug 修了！)
	struct seqList* merged_list = merge_unique(&list1, &list2);

	printf("\n--- 合并去重后 ---\n");
	print_list("Merged", merged_list);

	// 5. 测试删除逻辑
	delete(merged_list, 0); // 删掉第一个元素
	printf("\n--- 删除 index 0 后 ---\n");
	print_list("Merged", merged_list);

	// 6. 销毁回收，防止内存泄漏
	destroy(&list1);
	destroy(&list2);
	destroy(merged_list);
	free(merged_list); // 因为 merged_list 是 malloc 出来的结构体，还需要 free 掉结构体本身

	return 0;
}