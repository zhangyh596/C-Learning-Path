//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <limits.h>
//#include <stdlib.h>
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//
//	int layers = (n + 1) / 2;
//
//	int* sums = (int*)calloc(layers, sizeof(int));
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			int val;
//			scanf("%d", &val);
//
//			int up = i;//到矩阵上边界的距离
//			int down = n - 1 - i;//到矩阵下边界的距离
//			int left = j;//到矩阵左边界的距离
//			int right = n - 1 - j;//到矩阵右边界的距离
//
//			int min_ud = up < down ? up : down;
//			int min_lr = left < right ? left : right;
//			int layer_index = min_ud < min_lr ? min_ud : min_lr;
//
//			sums[layer_index] += val;
//		}
//	}
//
//	int max = INT_MIN;
//	int min = INT_MAX;
//	for (int i = 0; i < layers; i++)
//	{
//		if (sums[i] > max)
//		{
//			max = sums[i];
//		}
//		if (sums[i] < min)
//		{
//			min = sums[i];
//		}
//	}
//
//	printf("Max: %d, Min: %d\n", max, min);
//	printf("Diff: %d\n", max - min);
//	return 0;
//}