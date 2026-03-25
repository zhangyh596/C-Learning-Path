#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
	int data;//数据域：用来存东西
	struct TreeNode* left;//指针域：指向左边子节点的指针
	struct TreeNOde* right;//指针域：指向右边子节点的指针
}TreeNode;

//创建新节点
TreeNode* createNode(int value);
//插入节点
TreeNode* insertNode(TreeNode* root, int value);
//中序遍历打印函数
void inorderTraversal(TreeNode* root);
//查找指定的数字
TreeNode* searchNode(TreeNode* root, int target);
//销毁二叉树
void freeTree(TreeNode* root);