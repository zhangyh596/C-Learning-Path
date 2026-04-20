#define _CRT_SECURE_NO_WARNINGS 1

#include "dfs.h"

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int dfs(int start_x, int start_y, int target_x, int target_y)
{
	int vis[100][100] = { 0 };
	Stack s;
	initStack(&s, 100);

	Point start = { start_x, start_y };
	pushStack(&s, start);
	vis[start_x][start_y] = 1;

	while (!isEmptyStack(&s))
	{
		Point curr = popStack(&s);
		if (curr.x == target_x && curr.y == target_y)
		{
			freeStack(&s);
			return 1;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = curr.x + dx[i];
			int ny = curr.y + dy[i];

			if (nx >= 0 && nx < 100 && ny >= 0 && ny < 100 && vis[nx][ny] == 0)
			{
				vis[nx][ny] = 1;
				Point newPoint = { nx, ny };
				pushStack(&s, newPoint);
			}
		}
	}
	freeStack(&s);
	return 0;
}

int main()
{
	if (dfs(0, 0, 4, 4) == 1)
	{
		printf("有路径\n");
	}
	return 0;
}