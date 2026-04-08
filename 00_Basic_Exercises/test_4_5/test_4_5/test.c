#define _CRT_SECURE_NO_WARNINGS 1

#include "queue.h"

//P1443马的遍历

int ans[405][405];
int dx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };

void bfs(int n, int m, int sx, int sy)
{
	NodeQueue* q = queue_create(160005);

	Node start;
	start.x = sx, start.y = sy;
	queue_push(q, start);
	ans[sx][sy] = 0;

	Node curr;
	while (queue_pop(q, &curr))
	{
		for (int i = 0; i < 8; i++)
		{
			int nx = curr.x + dx[i];
			int ny = curr.y + dy[i];

			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && ans[nx][ny] == -1)
			{
				Node newnode;
				newnode.x = nx, newnode.y = ny;
				queue_push(q, newnode);
				ans[nx][ny] = ans[curr.x][curr.y] + 1;
			}
		}
	}
	queueDestroy(q);
}

int main()
{
	int n, m, sx, sy;
	scanf("%d %d %d %d", &n, &m, &sx, &sy);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			ans[i][j] = -1;
		}
	}

	bfs(n, m, sx, sy);

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