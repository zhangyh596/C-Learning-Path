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

TreeNode* insertNode(TreeNode* root, int value)
{
	if (root == NULL)
	{
		return createNode(value);
	}

	// 如果新来的值比当前节点的数据小，说明它该去左边
	if (value < root->data)
	{
		// 让当前节点的左指针，接住从左子树传回来的结果
		root->left = insertNode(root->left, value);
	}
	// 如果新来的值比当前节点的数据大，说明它该去右边
	else if (value > root->data)
	{
		// 让当前节点的右指针，接住从右子树传回来的结果
		root->right = insertNode(root->right, value);
	}
	// 如果新值等于当前节点的值，我们一般什么都不做，因为二叉搜索树通常不存重复数据
	return root;
}