#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
	int data;//数据域：用来存东西
	struct TreeNode* left;//指针域：指向左边子节点的指针
	struct TreeNOde* right;//指针域：指向右边子节点的指针
}TreeNode;