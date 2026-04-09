#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "poly.h"

void printPoly(Polynomial p)
{
	if (p == NULL)
	{
		printf("0\n");
		return;
	}

	Polynomial pcur = p;
	while (pcur != NULL)
	{
		if (pcur->coef > 0)
		{
			if (pcur != p)
			{
				printf("+");
			}
		}
		else
		{
			printf("-");
		}

		double printCoef = fabs(pcur->coef);
		if (printCoef != 1 || (printCoef == 1 && pcur->expn == 0))
		{
			printf("%g", printCoef);
		}

		if (pcur->expn == 0)
		{

		}
		else if (pcur->expn == 1)
		{
			printf("x");
		}
		else
		{
			printf("x^%d", pcur->expn);
		}
		pcur = pcur->next;
	}
}

int main()
{
	Polynomial node1 = createNode(5, 3);
	Polynomial node2 = createNode(2, 1);
	node1->next = node2;
	Polynomial A = node1;

	Polynomial node3 = createNode(4, 3);
	Polynomial node4 = createNode(1, 2);
	node3->next = node4;
	Polynomial B = node3;

	Polynomial p = subtractPoly(A, B);
	printPoly(p);

	freePoly(A);
	freePoly(B);
	freePoly(p);
	p = NULL;
}