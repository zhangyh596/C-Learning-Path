#define _CRT_SECURE_NO_WARNINGS 1

#include "Point.h"

int main()
{
	Vector my_vec;

	printf("--- 系统启动：初始化 Vector ---\n");
	init_vec(&my_vec);
	printf("初始状态: size = %d, capacity = %d\n\n", my_vec.size, my_vec.capacity);

	// 制造测试数据，专门考验你的三重排序逻辑
	// A: 距离 7 (x=3, y=4)
	// B: 距离 7 (x=-3, y=4) -> 距离同A，但 x < A.x
	// C: 距离 2 (x=1, y=1)
	// D: 距离 2 (x=-1, y=1) -> 距离同C，但 x < C.x
	// E: 距离 2 (x=-1, y=-1) -> 距离同D，x 同D，但 y < D.y
	Point points[] = {
		{3, 4}, {-3, 4}, {1, 1}, {-1, 1}, {-1, -1}
	};

	printf("--- 开始连续插入数据，测试扩容机制 ---\n");
	for (int i = 0; i < 5; i++)
	{
		push_vec(&my_vec, points[i]);
		printf("插入点 (%2d, %2d) | 当前 size = %d, capacity = %d\n",
			points[i].x, points[i].y, my_vec.size, my_vec.capacity);
	}

	printf("\n--- 开始 qsort 排序 ---\n");
	// 调用 C 标准库的快排
	qsort(my_vec.data, my_vec.size, sizeof(Point), compare_point);

	printf("排序结果：\n");
	for (int i = 0; i < my_vec.size; i++)
	{
		int dist = abs(my_vec.data[i].x) + abs(my_vec.data[i].y);
		printf("[%d] 点(%2d, %2d) -> 曼哈顿距离: %d\n",
			i, my_vec.data[i].x, my_vec.data[i].y, dist);
	}

	printf("\n--- 清理内存 ---\n");
	destroy_vec(&my_vec);
	// 测试是否真的清空了
	if (my_vec.data == NULL && my_vec.size == 0)
	{
		printf("内存释放彻底，Vector 销毁成功！\n");
	}
	else
	{
		printf("警告：内存未正确清理！\n");
	}

	return 0;
}