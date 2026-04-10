// ==================== main.c ====================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "miner.h"

int R, C;
int total_gold = 0;

int main()
{
	// 假设地图最大 100x100
	char map[100][100];
	char commands[1005];

	scanf("%d %d", &R, &C);

	for (int i = 0; i < R; i++) {
		scanf("%s", map[i]);
	}

	scanf("%s", commands);

	int start_r = 0, start_c = 0;

	process_commands(map, start_r, start_c, commands);

	printf("收集到的金矿数量: %d\n", total_gold);
	printf("最终地图状态:\n");
	for (int i = 0; i < R; i++)
	{
		printf("%s\n", map[i]);
	}

	return 0;
}