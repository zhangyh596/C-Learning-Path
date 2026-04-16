#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode
{
	int coef;// 系数
	int exp;// 指数
	struct PolyNode* next;
}PolyNode;

PolyNode* createNode(int coef, int exp);
void appendNode(PolyNode** head, int coef, int exp);
void printPoly(PolyNode* head);
void freePoly(PolyNode** head);