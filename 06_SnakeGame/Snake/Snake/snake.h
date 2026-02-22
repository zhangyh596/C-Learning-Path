#pragma once

#include <windows.h>
#include <stdbool.h>
#include <stdlib.h>

//类型的声明

//蛇的方向
enum DIRECTION
{
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};

//蛇的状态
//正常，撞墙，撞到自己，正常退出
enum GAME_STATUS
{
	OK,
	KILL_BY_WALL,
	KILL_BY_SELF,
	END_NORMAL
};

//蛇身的节点类型
typedef struct SnakeNode
{
	//坐标
	int x;
	int y;
	//指向下一个节点的指针
	struct SnakeNode* next;
}SnakeNode;
typedef SnakeNode* pSnakeNode;

//贪吃蛇
typedef struct Snake
{
	pSnakeNode _pSnake;//指向蛇头的指针
	pSnakeNode _pfood;//指向食物节点的指针
	enum DIRECTION _dir;//蛇的方向
	enum GAME_STATUS _status;//游戏的状态
	int _food_weight;//一个食物的分数
	int _score;//总成绩
	int _sleep_time;//休息时间，时间越短速度越快，时间越长速度越慢
}Snake;
typedef Snake* pSnake;

//函数的声明

//游戏的初始化
void GameStart(pSnake);