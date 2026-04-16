#define _CRT_SECURE_NO_WARNINGS 1

#include "poly.h"

int main()
{
	PolyNode* node1 = createNode(4, 3);
	node1->next = NULL;
	appendNode(&node1, 2, 1);
	printPoly(node1);
	freePoly(&node1);

	PolyNode* node2 = createNode(-3, 3);
	node2->next = NULL;
	appendNode(&node2, 3, 3);
	appendNode(&node2, 2, 2);
	printPoly(node2);
	freePoly(&node2);
	return 0;
}