#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

struct Node
{
	int x, y;
};

int dx[8] = { 2,1,-1,-2,-2,-1,1,2 };
int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	//定义一个队列存放所有点的信息
	struct Node que[160005];
	//用head标记准备处理的位置，tail标记新位置
	int head = 0, tail = 0;
	int ans[405][405];
	int sx, sy;
	scanf("%d %d", &sx, &sy);
	//将数组全初始化为-1
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			ans[i][j] = -1;
		}
	}
	ans[sx][sy] = 0;//初始位置为0
	que[tail].x = sx, que[tail].y = sy;
	tail++;
	while (head < tail)
	{
		struct Node now = que[head];
		head++;
		for (int i = 0; i < 8; i++)
		{
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && ans[nx][ny] == -1)
			{
				ans[nx][ny] = ans[now.x][now.y] + 1;
				que[tail].x = nx;
				que[tail].y = ny;
				tail++;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}