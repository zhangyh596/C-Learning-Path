#define _CRT_SECURE_NO_WARNINGS 1

#include "dfs.h"

int main()
{
	int rows = 4;
	int cols = 5;

	// 用一维数组来模拟二维数组
	int* grid = (int*)malloc(sizeof(int) * rows * cols);
	int* visited = (int*)calloc(rows * cols, sizeof(int));

	if (grid == NULL || visited == NULL)
	{
		return 1;
	}

	// 我们手动捏一张 4x5 的地图，肉眼看看应该有 2 个岛屿
	int test_map[20] =
	{
		1, 1, 0, 0, 0,  // 岛屿 A (左上)
		1, 1, 0, 0, 1,  // 岛屿 B (右上，单格)
		0, 0, 0, 1, 1,  // 岛屿 C (右下，两格)
		0, 0, 0, 0, 0
	};

	// 把测试数据拷贝到我们动态申请的堆内存 grid 中
	for (int i = 0; i < 20; i++)
	{
		grid[i] = test_map[i];
	}

	int count = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int index = i * cols + j;
			if (grid[index] == 1 && visited[index] == 0)
			{
				count++;
				dfs(i, j, rows, cols, grid, visited);
			}
		}
	}

	printf("找到了%d座岛屿\n", count);

	free(grid);
	grid = NULL;
	free(visited);
	visited = NULL;
	return 0;
}