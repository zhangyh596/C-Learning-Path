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
			perror("InitSnake failed");
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

void CreateFood(pSnake ps)
{
	int x = 0, y = 0;

	//生成x是2的倍数
again:
	do
	{
		x = rand() % 53 + 2;//x:2~54
		y = rand() % 25 + 1;//y:1~25
	} while (x % 2 != 0);

	//x和y的坐标不能和蛇身坐标冲突
	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{
		if (x == cur->x && y == cur->y)
		{
			goto again;
		}
		cur = cur->next;
	}

	//创建食物的节点
	pSnakeNode pFood = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pFood == NULL)
	{
		perror("CreateFood failed");
		return;
	}
	pFood->x = x;
	pFood->y = y;
	pFood->next = NULL;

	SetPos(x, y);
	wprintf(L"%lc", FOOD);
	ps->_pFood = pFood;
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

	//1.打印环境界面和功能介绍
	WelcomeToGame();
	//2.绘制地图
	CreateMap();
	//3.创建蛇
	InitSnake(ps);
	//4.创建食物
	CreateFood(ps);
}

static void PrintHelpInfo()
{
	SetPos(64, 14);
	wprintf(L"%ls", L"不能穿墙，不能咬到自己");
	SetPos(64, 15);
	wprintf(L"%ls", L"用↑、↓、←、→来控制蛇的移动\n");
	SetPos(64, 16);
	wprintf(L"%ls", L"按F3加速，F4减速\n");
	SetPos(64, 17);
	wprintf(L"%ls", L"按esc退出游戏，按空格键暂停游戏\n");
}

#define KEY_PRESS(vk) ((GetAsyncKeyState(vk)&1)?1:0)

static void Pause()
{
	while (1)
	{
		Sleep(200);
		if (KEY_PRESS(VK_SPACE))
		{
			break;
		}
	}
}

int NextIsFood(pSnakeNode pn, pSnake ps)
{
	return (ps->_pFood->x == pn->x && ps->_pFood->y == pn->y);
}

void EatFood(pSnakeNode pn, pSnake ps)
{
	//头插法
	ps->_pFood->next = ps->_pSnake;
	ps->_pSnake = ps->_pFood;

	//释放下一个位置的节点
	free(pn);
	pn = NULL;

	//打印蛇
	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}
	ps->_score += ps->_food_weight;

	//重新创建食物
	CreateFood(ps);
}

void NoFood(pSnakeNode pn, pSnake ps)
{
	//头插法
	pn->next = ps->_pSnake;
	ps->_pSnake = pn;

	//打印新蛇头
	SetPos(pn->x, pn->y);
	wprintf(L"%lc", BODY);

	//找尾节点的前一个节点
	pSnakeNode cur = ps->_pSnake;
	while (cur->next->next != NULL)
	{
		cur = cur->next;
	}

	//把最后一个节点打印成空格
	SetPos(cur->next->x, cur->next->y);
	printf("  ");

	//释放掉尾节点
	free(cur->next);
	cur->next = NULL;
}

void KillByWall(pSnake ps)
{
	if (ps->_pSnake->x == 0 || ps->_pSnake->x == 56 ||
		ps->_pSnake->y == 0 || ps->_pSnake->y == 26)
	{
		ps->_status = KILL_BY_WALL;
	}
}

void KillBySelf(pSnake ps)
{
	pSnakeNode cur = ps->_pSnake->next;
	while (cur)
	{
		if (cur->x == ps->_pSnake->x && cur->y == ps->_pSnake->y)
		{
			ps->_status = KILL_BY_SELF;
			break;
		}
		cur = cur->next;
	}
}

void SnakeMove(pSnake ps)
{
	//创建一个节点，表示蛇即将到达的下一个节点
	pSnakeNode pNextNode = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pNextNode == NULL)
	{
		perror("SnkaeMove failed");
		return;
	}

	switch (ps->_dir)
	{
	case UP:
		pNextNode->x = ps->_pSnake->x;
		pNextNode->y = ps->_pSnake->y - 1;
		break;
	case DOWN:
		pNextNode->x = ps->_pSnake->x;
		pNextNode->y = ps->_pSnake->y + 1;
		break;
	case LEFT:
		pNextNode->x = ps->_pSnake->x - 2;
		pNextNode->y = ps->_pSnake->y;
		break;
	case RIGHT:
		pNextNode->x = ps->_pSnake->x + 2;
		pNextNode->y = ps->_pSnake->y;
		break;
	}

	if (NextIsFood(pNextNode, ps))
	{
		EatFood(pNextNode, ps);
	}
	else
	{
		NoFood(pNextNode, ps);
	}

	//检测蛇是否撞墙
	KillByWall(ps);
	//检测蛇是否撞到自己
	KillBySelf(ps);
}

void GameRun(pSnake ps)
{
	//打印帮助信息
	PrintHelpInfo();
	do
	{
		//打印总分数和食物的分值
		SetPos(64, 10);
		printf("总分数：%d\n", ps->_score);
		SetPos(64, 11);
		printf("当前食物的分数：%d\n", ps->_food_weight);

		if (KEY_PRESS(VK_UP) && ps->_dir != DOWN)
		{
			ps->_dir = UP;
		}
		else if (KEY_PRESS(VK_DOWN) && ps->_dir != UP)
		{
			ps->_dir = DOWN;
		}
		else if (KEY_PRESS(VK_LEFT) && ps->_dir != RIGHT)
		{
			ps->_dir = LEFT;
		}
		else if (KEY_PRESS(VK_RIGHT) && ps->_dir != LEFT)
		{
			ps->_dir = RIGHT;
		}
		else if (KEY_PRESS(VK_SPACE))
		{
			Pause();
		}
		else if (KEY_PRESS(VK_ESCAPE))
		{
			//正常退出
			ps->_status = END_NORMAL;
		}
		else if (KEY_PRESS(VK_F3))
		{
			//加速
			if (ps->_sleep_time > 80)
			{
				ps->_sleep_time -= 30;
				ps->_food_weight += 2;
			}
		}
		else if (KEY_PRESS(VK_F4))
		{
			//减速
			if (ps->_food_weight > 2)
			{
				ps->_sleep_time += 30;
				ps->_food_weight -= 2;
			}
		}

		SnakeMove(ps);//蛇走一步的过程
		Sleep(ps->_sleep_time);

	} while (ps->_status == OK);
}