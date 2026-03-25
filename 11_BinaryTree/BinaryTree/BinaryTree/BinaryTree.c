#define _CRT_SECURE_NO_WARNINGS 1

#include "BinaryTree.h"

TreeNode* createNode(int value)
{
	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));

	//检查是否malloc成功
	if (newNode == NULL)
	{
		perror("malloc failed");
		exit(1);//退出程序
	}

	//正式初始化节点
	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}