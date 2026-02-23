#define _CRT_SECURE_NO_WARNINGS 1

#include "snake.h"

static void SetPos(short x, short y)
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
	SetPos(42, 20);
	system("pause");
	system("cls");
	SetPos(25, 14);
	wprintf(L"用↑、↓、←、→来控制蛇的移动，按F3加速，F4减速\n");
	SetPos(25, 15);
	wprintf(L"加速能够得到更高的分数\n");
	SetPos(42, 20);
	system("pause");
	system("cls");
}

void CreateMap()
{
	//上
	for (int i = 0; i < 29; i++)
	{
		wprintf(L"%lc", WALL);
	}
	//下
	SetPos(0, 26);
	for (int i = 0; i < 29; i++)
	{
		wprintf(L"%lc", WALL);
	}
	//左
	for (int i = 1; i <= 25; i++)
	{
		SetPos(0, i);
		wprintf(L"%lc", WALL);
	}
	//右
	for (int i = 1; i <= 25; i++)
	{
		SetPos(56, i);
		wprintf(L"%lc", WALL);
	}
}

void InitSnake(pSnake ps)
{
	pSnakeNode cur = NULL;
	for (int i = 0; i < 5; i++)
	{
		cur = (pSnakeNode)malloc(sizeof(SnakeNode));
		if (cur == NULL)
		{
			perror("malloc failed");
			return;
		}
		cur->next = NULL;
		cur->x = POS_X + 2 * i;
		cur->y = POS_Y;

		//头插法插入链表
		cur->next = ps->_pSnake;
		ps->_pSnake = cur;
	}

	cur = ps->_pSnake;
	while (cur)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}

	//设置贪吃蛇的属性
	ps->_dir = RIGHT;//默认向右
	ps->_score = 0;
	ps->_food_weight = 10;
	ps->_sleep_time = 200;//单位是毫秒
	ps->_status = OK;
}

void GameStart(pSnake ps)
{
	//0.先设置窗口的大小名字，再光标隐藏
	system("mode con cols=100 lines=30");
	system("title 贪吃蛇");
	//隐藏光标操作
	// 拿到控制台的“遥控器” (获取句柄)
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	// 找一张纸，准备记录光标当前的“设置信息”
	CONSOLE_CURSOR_INFO CursorInfo;
	// 按下遥控器，把当前的光标设置读取出来，写到纸上
	GetConsoleCursorInfo(houtput, &CursorInfo);
	// 在纸上把“是否可见 (bVisible)”这一项划掉，改成 false（不可见）
	CursorInfo.bVisible = false;
	// 按下遥控器的“保存”键，把修改后的设置重新应用给控制台
	SetConsoleCursorInfo(houtput, &CursorInfo);

	//1.打印环境界面 2.功能介绍
	WelcomeToGame();
	//3.绘制地图
	CreateMap();
	//4.创建蛇
	InitSnake(ps);
	//5.创建食物
	//6.设置游戏的相关信息
}