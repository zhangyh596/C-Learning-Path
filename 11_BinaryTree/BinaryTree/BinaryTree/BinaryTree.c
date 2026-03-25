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

void inorderTraversal(TreeNode* root)
{
	if (root != NULL)
	{
		// 先一路向左，去打印比当前节点小的数
		inorderTraversal(root->left);
		// 打印当前节点自己的值
		printf("%d ", root->data);
		// 最后一路向右，去打印比当前节点大的数
		inorderTraversal(root->right);
	}
}

TreeNode* searchNode(TreeNode* root, int target)
{
	if (root == NULL || root->data == target)
	{
		return root;
	}

	// 如果目标比当前节点小，顺藤摸瓜去左边找
	if (target < root->data)
	{
		return searchNode(root->left, target);
	}
	// 如果目标比当前节点大，顺藤摸瓜去右边找
	else
	{
		return searchNode(root->right, target);
	}
}

void freeTree(TreeNode* root)
{
	if (root != NULL)
	{
		freeTree(root->left);
		freeTree(root->right);
		free(root);
	}
}

//辅助函数
TreeNode* findMin(TreeNode* root)
{
	if (root == NULL)
	{
		return NULL;
	}

	while (root->left != NULL)
	{
		root = root->left;
	}
	return root;
}

TreeNode* deleteNode(TreeNode* root, int target)
{
	// 递归终止条件：如果树是空的，或者一直找没找到这个数字
	if (root == NULL)
	{
		return root;
	}

	if (target < root->data)
	{
		// 目标在左边，去左子树里执行删除任务，并重新接好左边的绳子
		root->left = deleteNode(root->left, target);
	}
	else if (target > root->data)
	{
		// 目标在右边，去右子树里执行删除任务，并重新接好右边的绳子
		root->right = deleteNode(root->right, target);
	}
	else
	{
		// 如果没有左孩子（包含了完全没有孩子的情况）
		if (root->left == NULL)
		{
			TreeNode* tmp = root->right;
			free(root);
			return tmp;
		}
		// 如果没有右孩子
		else if (root->right == NULL)
		{
			TreeNode* tmp = root->left;
			free(root);
			return tmp;
		}

		// 走到这里，说明左右孩子都不为空
		// 第一步：去右子树里，找那个最小的“接班人”
		TreeNode* tmp = findMin(root->right);
		// 第二步：把接班人的数据复制到当前节点里
		root->data = tmp->data;
		// 第三步：当前节点的右子树里现在多了一个重复的接班人，去把它删掉
		root->right = deleteNode(root->right, tmp->data);
	}
	return root;
}
