#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <stdlib.h>

//int* getConcatenation(int* nums, int numsSize, int* returnSize)
//{
//	int* ans = (int*)malloc(numsSize * sizeof(int) * 2);
//	for (int i = 0; i < numsSize; i++)
//	{
//		ans[i] = nums[i];
//		ans[i + numsSize] = nums[i];
//	}
//	*returnSize = numsSize * 2;
//	return ans;
//}


#include <stdio.h>
#include <stdlib.h>

int main()
{
	//开辟数组
	int** p = (int**)malloc(3 * sizeof(int*));
	for (int i = 0; i < 3; i++)
	{
		p[i] = (int*)malloc(5 * (sizeof(int)));
	}
	//初始化数组
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			p[i][j] = 5 * i + j;
		}
	}
	//打印数组
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}
	//free开辟的空间
	for (int i = 0; i < 3; i++)
	{
		free(p[i]);
		p[i] = NULL;
	}
	free(p);
	p = NULL;
	return 0;
}