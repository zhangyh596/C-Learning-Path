#include <stdio.h>
#include <stdbool.h>

#define ROW 4
#define COL 4

// 0 代表通路，1 代表障碍
int map[ROW][COL] = {
    {0, 0, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 0},
    {1, 1, 0, 0},
};

// 标记走过的地点
int visited[ROW][COL] = {0};

// 设定方向：下右上左
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

typedef struct Point
{
    int x, y;
} Point;

Point path[ROW * COL];
int path_len = 0;

bool dfs(int x, int y, int target_x, int target_y)
{
    // 碰到边界或障碍直接返回
    if (x < 0 || x >= ROW || y < 0 || y >= COL)
        return false;
    if (map[x][y] == 1 || visited[x][y] == 1)
        return false;

    // 先标记当前节点并记录路径数组
    // 用数组模拟栈
    visited[x][y] = 1;
    path[path_len].x = x;
    path[path_len].y = y;
    path_len++;

    // 走到终点返回true
    if (x == target_x && y == target_y)
        return true;

    // 四个方向均尝试走
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (dfs(nx, ny, target_x, target_y))
        {
            return true;
        }
    }

    // 回溯，四周不通，撤销当前路径标记
    path_len--;
    return false;
}

int main()
{
    dfs(0, 0, 3, 3);
    for (int i = 0; i < path_len; i++)
    {
        printf("(%d, %d)\n", path[i].x, path[i].y);
    }
    return 0;
}