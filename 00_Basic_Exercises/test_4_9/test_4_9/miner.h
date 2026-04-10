#pragma once

extern int total_gold;
extern int R, C;

// 注意二维数组传参的退化机制，第一维可以省略，第二维必须明确（100）
void process_commands(char map[][100], int start_r, int start_c, const char* commands);
