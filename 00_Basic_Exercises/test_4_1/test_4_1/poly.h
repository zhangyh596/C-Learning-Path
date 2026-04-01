#pragma once


#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode
{
	int coef;// 系数
	int exp;// 指数
	struct PolyNode* next;// 指向下一项的指针
}PolyNode;

//创建节点
PolyNode* createNode(int coef, int exp);
//添加多项式
void appendNode(PolyNode** head, int coef, int exp);
//打印多项式
void printPoly(PolyNode* head);
//释放空间
void freePoly(PolyNode** head);
