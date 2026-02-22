#define _CRT_SECURE_NO_WARNINGS 1

#include "snake.h"

void SetPos(short x, short y)
{
	//获取标准输出设备的句柄
	HANDLE houtput = NULL;
	houtput = GetStdHandle(STD_OUTPUT_HANDLE);

	//定位光标的位置
	COORD pos = { x, y };
	SetConsoleCursorPosition(houtput, pos);
}
void WelcomeToGame()
{
	SetPos(40, 14);
	wprintf(L"欢迎来到贪吃蛇小游戏\n");
}
void GameStart(pSnake ps)
{
	//0.先设置窗口的大小名字，再光标隐藏
	system("mode con cols=100 lines=30");
	system("title 贪吃蛇");
	//隐藏光标操作
	// 1. 拿到控制台的“遥控器” (获取句柄)
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	// 2. 找一张纸，准备记录光标当前的“设置信息”
	CONSOLE_CURSOR_INFO CursorInfo;
	// 3. 按下遥控器，把当前的光标设置读取出来，写到纸上
	GetConsoleCursorInfo(houtput, &CursorInfo);
	// 4. 在纸上把“是否可见 (bVisible)”这一项划掉，改成 false（不可见）
	CursorInfo.bVisible = false;
	// 5. 按下遥控器的“保存”键，把修改后的设置重新应用给控制台
	SetConsoleCursorInfo(houtput, &CursorInfo);

	//1.打印环境界面
	WelcomeToGame();
	//2.功能介绍
	//3.绘制地图
	//4.创建蛇
	//5.创建食物
	//6.设置游戏的相关信息
}