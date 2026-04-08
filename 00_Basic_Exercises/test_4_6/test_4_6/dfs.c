#define _CRT_SECURE_NO_WARNINGS 1

#include "dfs.h"

void dfs(int x, int y, int rows, int cols, int* grid, int* visited)
{
	if (x >= rows || x < 0 || y >= cols || y < 0)
	{
		return;
	}

	int index = x * cols + y;// 关键找下标


	if (visited[index] == 1 || grid[index] == 0)
	{
		return;
	}

	visited[index] = 1;

	dfs(x - 1, y, rows, cols, grid, visited);
	dfs(x + 1, y, rows, cols, grid, visited);
	dfs(x, y - 1, rows, cols, grid, visited);
	dfs(x, y + 1, rows, cols, grid, visited);
}

