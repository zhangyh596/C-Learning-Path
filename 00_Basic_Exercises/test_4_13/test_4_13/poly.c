#define _CRT_SECURE_NO_WARNINGS 1

#include "poly.h"

PolyNode* createNode(int coef, int exp)
{
	PolyNode* newnode = (PolyNode*)malloc(sizeof(PolyNode));
	if (newnode == NULL)
	{
		return NULL;
	}

	newnode->coef = coef;
	newnode->exp = exp;
	newnode->next = NULL;

	return newnode;
}

void appendNode(PolyNode** head, int coef, int exp)
{
	if (head == NULL || coef == 0)
	{
		return;
	}

	PolyNode* prev = NULL;
	PolyNode* pcur = *head;
	while (pcur != NULL)
	{
		if (pcur->exp == exp)
		{
			pcur->coef += coef;
			if (pcur->coef == 0)
			{
				if (prev == NULL)
				{
					*head = pcur->next;
				}
				else
				{
					prev->next = pcur->next;
				}
				free(pcur);
			}
			return;
		}

		else if (pcur->exp < exp)
		{
			PolyNode* newnode = createNode(coef, exp);
			newnode->next = pcur;
			if (prev == NULL)
			{
				*head = newnode;
			}
			else
			{
				prev->next = newnode;
			}
			return;
		}
		prev = pcur;
		pcur = pcur->next;
	}

	//如果遍历完没有找到位置，说明指数最小，插到最末尾
	PolyNode* newnode = createNode(coef, exp);
	if (prev == NULL)
	{
		*head = newnode;
	}
	else
	{
		prev->next = newnode;
	}
}

void printPoly(PolyNode* head)
{
	if (head == NULL)
	{
		printf("0\n");
		return;
	}

	PolyNode* pcur = head;
	while (pcur != NULL)
	{
		if (pcur->coef > 0)
		{
			if (pcur != head)
			{
				printf("+");
			}
		}
		else
		{
			printf("-");
		}

		int abs_coef = abs(pcur->coef);
		if (abs_coef != 1 || (abs_coef == 1 && pcur->exp == 0))
		{
			printf("%d", abs_coef);
		}

		if (pcur->exp > 1)
		{
			printf("x^%d", pcur->exp);
		}
		else if (pcur->exp == 1)
		{
			printf("x");
		}
		else if (pcur->exp == 0)
		{

		}
		pcur = pcur->next;
	}
	printf("\n");
}

void freePoly(PolyNode** head)
{
	if (head == NULL || *head == NULL)
	{
		return;
	}

	PolyNode* pcur = *head;
	while (pcur != NULL)
	{
		PolyNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*head = NULL;
}