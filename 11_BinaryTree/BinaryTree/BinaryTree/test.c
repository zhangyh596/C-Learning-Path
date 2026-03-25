#define _CRT_SECURE_NO_WARNINGS 1

#include "BinaryTree.h"

int main()
{
	TreeNode* root = NULL;
	printf("开始向二叉树中插入数字\n");

	root = insertNode(root, 50);
	root = insertNode(root, 30);
	root = insertNode(root, 70);
	root = insertNode(root, 20);
	root = insertNode(root, 40);
	root = insertNode(root, 60);
	root = insertNode(root, 80);

	printf("中序遍历打印的结果是：\n");
	inorderTraversal(root);
	printf("\n");

	return 0;
}