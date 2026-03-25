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

	int target1 = 100;
	TreeNode* result1 = searchNode(root, target1);
	if (result1 != NULL)
	{
		printf("找到了数字%d\n", result1->data);
	}
	else
	{
		printf("没有找到%d这个数字\n", target1);
	}

	freeTree(root);
	printf("二叉树成功被释放\n");

	return 0;
}