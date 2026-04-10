#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "miner.h"

const int dr[] = { -1, 1, 0, 0 };
const int dc[] = { 0, 0, -1, 1 };

void process_commands(char map[][100], int start_r, int start_c, const char* commands)
{
	int cmd[128];
	cmd['U'] = 0;
	cmd['D'] = 1;
	cmd['L'] = 2;
	cmd['R'] = 3;

	for (int i = 0; commands[i] != '\0'; i++)
	{
		char c = commands[i];

		int nr = start_r + dr[cmd[c]];
		int nc = start_c + dc[cmd[c]];
		if (nr >= 0 && nr < R && nc >= 0 && nc < C && map[nr][nc] != '#')
		{
			if (map[nr][nc] == 'G')
			{
				total_gold += 10;
				map[nr][nc] = '.';

				if (total_gold == 10)
					return;
			}

			start_r = nr;
			start_c = nc;
		}
	}
}