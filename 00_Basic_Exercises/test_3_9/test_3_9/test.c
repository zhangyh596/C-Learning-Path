#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int binarySearch(int* nums, int numsSize, int target)
{
	if (nums == NULL || numsSize == 0)
		return -1;

	int left = 0, right = numsSize - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (nums[mid] == target)
		{
			return mid;//找到目标
		}
		else if (nums[mid] < target)
		{
			left = mid + 1;//目标在右侧
		}
		else
		{
			right = mid - 1;//目标在左侧
		}
	}
	return -1;
}

int binarySearchLeft1(int* nums, int numsSize, int target)
{
	int left = 0, right = numsSize - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (nums[mid] >= target)
		{
			right = mid - 1;//注意这一步，待会会解释
		}
		else
		{
			left = mid + 1;
		}
	}

	if (left < numsSize && nums[left] == target)//这一步也很重要，因为数组里面可能根本就没有target
		return left;
	return -1;
}

int binarySearchRight1(int* nums, int numsSize, int target)
{
	int left = 0, right = numsSize - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (nums[mid] <= target)
		{
			left = mid + 1;//关键的一步（和找左端点的思想同理）
		}
		else
		{
			right = mid - 1;
		}
	}

	if (right >= 0 && nums[right] == target)
		return right;
	return -1;
}

int binarySearchLeft2(int* nums, int numsSize, int target)
{
	int left = 0, right = numsSize - 1;
	while (left < right)
	{
		int mid = left + (right - left) / 2;//向下取整
		if (nums[mid] >= target)
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	if (left < numsSize && nums[left] == target)
		return left;
	return -1;
}

int binarySearchRight2(int* nums, int numsSize, int target)
{
	if (nums == NULL || numsSize == 0) return -1; // 边界防御

	int left = 0, right = numsSize - 1;
	while (left < right)
	{
		int mid = left + (right - left + 1) / 2;//向上取整
		if (nums[mid] <= target)
		{
			left = mid;
		}
		else
		{
			right = mid - 1;
		}
	}

	if (left < numsSize && nums[left] == target)
		return left;
	return -1;
}

int binarySearchLeft3(int* nums, int numsSize, int target)
{
	if (nums == NULL || numsSize == 0) return -1; // 边界防御

	int left = 0, right = numsSize - 1;
	//至少有三个元素才循环
	while (left + 1 < right)
	{
		int mid = left + (right - left) / 2;
		if (nums[mid] >= target)
		{
			right = mid;// 目标在左边或者就是 mid，把右边界收缩过来
		}
		else
		{
			left = mid;// nums[mid] < target，目标在右边，把左边界收缩过来
		}
	}
	// 退出循环时，区间必定只剩下 left 和 right 两个相邻的元素
	// 因为找的是【左】端点，所以理所当然优先检查【左】边的 left
	if (nums[left] == target) return left;
	if (nums[right] == target) return right;// 左边不是，兜底查一下右边
	return -1;
}

int binarySearchRight1(int* nums, int numsSize, int target)
{
	int left = 0, right = numsSize - 1;
	//区间至少有三个元素才循环
	while (left + 1 < right)
	{
		int mid = left + (right - left) / 2;
		if (nums[mid] <= target)
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	// 退出循环时，区间必定只剩下 left 和 right 两个相邻的元素
	// 因为找的是【右】端点，所以理所当然优先检查【右】边的 right
	if (nums[right] == target) return right;
	if (nums[left] == target) return left; // 右边不是，兜底查一下左边
	return -1;
}