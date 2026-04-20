#define _CRT_SECURE_NO_WARNINGS 1

//#include "bfs.h"
//
//int dx[4] = { -1, 1, 0, 0 };
//int dy[4] = { 0, 0, -1, 1 };
//
//void bfs(int start_x, int start_y, int target_x, int target_y)
//{
//	int vis[100][100] = { 0 };
//	Queue q;
//	initQueue(&q);
//
//	Point start = { 0, start_x, start_y };
//	pushQueue(&q, start);
//	vis[start_x][start_y] = 1;
//
//	while (!isEmpty(&q))
//	{
//		Point curr = popQueue(&q);
//
//		if (curr.x == target_x && curr.y == target_y)
//		{
//			printf("visited %d, %d at step %d\n", curr.x, curr.y, curr.step);
//          freeQueue(&q);
//          return;
//		}
//
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = curr.x + dx[i];
//			int ny = curr.y + dy[i];
//
//			if (nx < 100 && nx >= 0 && ny < 100 && ny >= 0 && vis[nx][ny] == 0)
//			{
//				vis[nx][ny] = 1;
//				Point next = { curr.step + 1, nx, ny };
//				pushQueue(&q, next);
//			}
//		}
//	}
//
//	freeQueue(&q);
//}
//
//int main()
//{
//	bfs(0, 0, 4, 4);
//	return  0;
//}


//数组模拟实现

#include <stdio.h>

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

typedef struct Point
{
	int x;
	int y;
	int step;
}Point;

Point q[100000];
int head = 0, tail = 0;

void bfs(int start_x, int start_y, int target_x, int target_y)
{
	int vis[100][100] = { 0 };
	head = 0, tail = 0;
	Point start = { start_x, start_y, 0 };
	vis[start_x][start_y] = 1;
	q[tail++] = start;

	while (head < tail)
	{
		Point curr = q[head++];

		if (curr.x == target_x && curr.y == target_y)
		{
			printf("Visited %d, %d at step %d\n", curr.x, curr.y, curr.step);
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = curr.x + dx[i];
			int ny = curr.y + dy[i];

			if (nx >= 0 && nx < 100 && ny >= 0 && ny < 100 && vis[nx][ny] == 0)
			{
				vis[nx][ny] = 1;
				Point next = { nx, ny, curr.step + 1 };
				q[tail++] = next;
			}
		}
	}
}

int main()
{
	bfs(0, 0, 4, 4);
	return 0;
}