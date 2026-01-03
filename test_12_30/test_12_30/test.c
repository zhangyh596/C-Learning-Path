#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int vis[1000][1000];

struct Node
{
	int x, y;
	int step;
};

struct Node array[1000001];

int main()
{
	int n = 5, m = 5;
	int head = 0;
	int tail = 0;
	int x = 1, y = 1;
	array[tail].x = x, array[tail].y = y;
	array[tail].step = 0;
	vis[x][y] = 1;
	tail++;
	while (head < tail)
	{
		struct Node now = array[head];
		head++;
		for (int i = 0; i < 4; i++)
		{
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && vis[nx][ny] == 0)
			{
				array[tail].x = nx;
				array[tail].y = ny;
				array[tail].step = now.step + 1;
				if (nx == 3 && ny == 3)
				{
					printf("%d", array[tail].step);
					return 0;
				}
				vis[nx][ny] = 1;
				tail++;
			}
		}
	}
	return 0;
}