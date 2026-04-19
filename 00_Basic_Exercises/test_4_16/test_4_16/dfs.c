#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

int map[5][5];
int vis[5][5];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int path_count = 0;

void dfs(int x, int y, int target_x, int target_y, int rows, int cols)
{
	if (map[x][y] == 1 || map[target_x][target_y] == 1)
	{
		return;
	}

	if (x == target_x && y == target_y)
	{
		path_count++;
		return;
	}

	vis[x][y] = 1;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && map[nx][ny] != 1 && vis[nx][ny] == 0)
		{
			dfs(nx, ny, target_x, target_y, rows, cols);
		}
	}

	vis[x][y] = 0;
}

int main()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	memset(vis, 0, sizeof(vis));
	vis[0][0] = 1;

	dfs(0, 0, 4, 4, 5, 5);

	printf("%d", path_count);

	return 0;
}