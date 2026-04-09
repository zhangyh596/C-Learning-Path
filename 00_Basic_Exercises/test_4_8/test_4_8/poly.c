#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include "poly.h"

Polynomial createNode(double coef, int expn)
{
	Polynomial newnode = (Polynomial)malloc(sizeof(PolyNode));
	newnode->coef = coef;
	newnode->expn = expn;
	newnode->next = NULL;

	return newnode;
}

Polynomial subtractPoly(Polynomial A, Polynomial B)
{
	Polynomial dummy = (Polynomial)malloc(sizeof(PolyNode));
	dummy->next = NULL;
	Polynomial tail = dummy;

	while (A != NULL && B != NULL)
	{
		if (A->expn > B->expn)
		{
			Polynomial newnode = createNode(A->coef, A->expn);
			tail->next = newnode;
			tail = tail->next;
			A = A->next;
		}
		else if (A->expn < B->expn)
		{
			Polynomial newnode = createNode(-B->coef, B->expn);
			tail->next = newnode;
			tail = tail->next;
			B = B->next;
		}
		else
		{
			double diff = A->coef - B->coef;
			if (diff != 0)
			{
				Polynomial newnode = createNode(diff, A->expn);
				tail->next = newnode;
				tail = newnode;
			}

			A = A->next;
			B = B->next;
		}
	}

	while (A != NULL)
	{
		Polynomial newnode = createNode(A->coef, A->expn);
		tail->next = newnode;
		tail = tail->next;
		A = A->next;
	}
	while (B != NULL)
	{
		Polynomial newnode = createNode(-B->coef, B->expn);
		tail->next = newnode;
		tail = tail->next;
		B = B->next;
	}

	Polynomial ret = dummy->next;
	free(dummy);
	return ret;
}

void freePoly(Polynomial p)
{
	Polynomial pcur = p;
	while (pcur != NULL)
	{
		Polynomial next = pcur->next;
		free(pcur);
		pcur = next;
	}
}