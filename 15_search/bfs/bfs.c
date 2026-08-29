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

int visited[ROW][COL] = {0};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// 队列节点结构体
typedef struct Node
{
    int x, y;
    int pre; // 记录它的“父节点”在队列中的下标，用于倒推路径
} Node;

// 用数组模拟队列
Node queue[ROW * COL];
int head = 0;
int tail = 0;

void print_path(int target_index)
{
    Node path[ROW * COL]; // 用来把倒序的路径正过来
    int len = 0;

    int curr = target_index;

    // 只要当前节点的 pre 不是 -1（起点），就一直往回找
    while (curr != -1)
    {
        path[len++] = queue[curr]; // 把节点存入路径数组
        curr = queue[curr].pre;    // 顺着父节点下标往回跳
    }

    for (int i = len - 1; i >= 0; i--)
    {
        printf("(%d, %d)\n", path[i].x, path[i].y);
    }
}

// 用队列模拟实现
bool bfs(int start_x, int start_y, int target_x, int target_y)
{
    // 起点入队
    queue[tail].x = start_x;
    queue[tail].y = start_y;
    queue[tail].pre = -1; // 起点没有父节点，标记为 -1
    tail++;
    visited[start_x][start_y] = 1;

    // d队列不为空，循环就一直继续
    while (head < tail)
    {
        // 取出队头元素，并把当前队头下标存下来
        int curr_index = head;
        Node curr = queue[head];
        head++;

        if (curr.x == target_x && curr.y == target_y)
        {
            printf("bfs找到最短路径:\n");
            print_path(curr_index); // 把终点在队列里的下标传过去，开始查户口本
            return true;
        }

        // 四个方向都进行探路
        for (int i = 0; i < 4; i++)
        {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            // 检查边界、障碍物、以及是否已经访问过
            if (nx >= 0 && nx < ROW && ny >= 0 && ny < COL && map[nx][ny] == 0 && visited[nx][ny] == 0)
            {
                // 标记当前节点
                visited[nx][ny] = 1;
                queue[tail].x = nx;
                queue[tail].y = ny;
                queue[tail].pre = curr_index;
                tail++;
            }
        }
    }

    // 如果队列全空了还没找到终点，说明死路一条
    return false;
}
int main()
{
    if (!bfs(0, 0, 3, 3))
    {
        printf("起点无法到达终点！\n");
    }
    return 0;
}