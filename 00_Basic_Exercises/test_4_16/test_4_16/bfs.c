//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <string.h>
//
//int map[5][5];
//int vis[5][5];
//
//struct Node
//{
//	int x;
//	int y;
//	int step;
//};
//
//struct Node q[100];
//
//int dx[4] = { -1, 1, 0, 0 };
//int dy[4] = { 0, 0, -1, 1 };
//
//int bfs(int start_x, int start_y, int target_x, int target_y, int rows, int cols)
//{
//	if (map[start_x][start_y] == 1 || map[target_x][target_y] == 1)
//	{
//		return -1;
//	}
//
//	int head = 0, tail = 0;
//	
//	memset(vis, 0, sizeof(vis));
//
//	q[tail].x = start_x, q[tail].y = start_y, q[tail].step = 0;
//	tail++;
//	vis[start_x][start_y] = 1;
//
//	while (head < tail)
//	{
//		struct Node curr = q[head++];
//
//		if (curr.x == target_x && curr.y == target_y)
//		{
//			return curr.step;
//		}
//
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = curr.x + dx[i];
//			int ny = curr.y + dy[i];
//
//			if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && vis[nx][ny] == 0 && map[nx][ny] != 1)
//			{
//				q[tail].x = nx;
//				q[tail].y = ny;
//				q[tail].step = curr.step + 1;
//				tail++;
//
//				vis[nx][ny] = 1;
//			}
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	for (int i = 0; i < 5; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			scanf("%d", &map[i][j]);
//		}
//	}
//
//	int ret = bfs(0, 0, 4, 4, 5, 5);
//	printf("%d", ret);
//
//	return 0;
//}