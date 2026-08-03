#include <stdio.h>
#include <stdlib.h>

// 将两个有序子数组合并：[left, mid] 和 [mid+1, right]
void Merge(int *a, int left, int mid, int right, int *tmp)
{
    int i = left;    // 左子数组的起点
    int j = mid + 1; // 右子数组的起点
    int k = left;    // 辅助数组的写入起点

    // 比较左右子数组的元素，将较小的放入 tmp 数组
    while (i <= mid && j <= right)
    {
        if (a[i] <= a[j])
        {
            tmp[k++] = a[i++];
        }
        else
        {
            tmp[k++] = a[j++];
        }
    }

    // 如果左边还剩元素，依次存入 tmp
    while (i <= mid)
    {
        tmp[k++] = a[i++];
    }

    // 如果右边还剩元素，依次存入 tmp
    while (j <= right)
    {
        tmp[k++] = a[j++];
    }

    // 将排序好的 tmp 数组内容拷贝回原数组 arr
    for (i = left; i <= right; ++i)
    {
        a[i] = tmp[i];
    }
}

// 递归分解数组并调用 merge
void MergrSortRecursive(int *a, int left, int right, int *tmp)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2; // 防止溢出

    // 必须分成[left, mid]和[mid + 1, right]，不能是[left, mid - 1]和[mid, right]
    // 只要数组里还有2个或以上的元素，砍一刀之后，左右两半的长度都必须比原长度短
    // 如果砍完之后，某一半的长度居然等于原长度，程序就会原地打转，陷入死循环
    // 发生死循环的“只剩 2 个元素”的情况（比如 left = 0, right = 1）
    // 此时计算出中点：mid = 0 + (1 - 0) / 2 = 0
    // 要是改成 [left, mid-1] 和 [mid, right]，右半区间将陷入死循环
    // 递归分割左半边，并对左半边排序
    MergrSortRecursive(a, left, mid, tmp);
    // 递归分割右半边，并对右半边排序
    MergrSortRecursive(a, mid + 1, right, tmp);

    // 合并左半边和右半边
    Merge(a, left, mid, right, tmp);
}

// 归并排序
void MergeSort(int *a, int n)
{
    // 申请辅助内存
    int *tmp = (int *)malloc(n * sizeof(int));
    if (tmp == NULL)
    {
        printf("内存分配失败\n");
        return;
    }

    MergrSortRecursive(a, 0, n - 1, tmp);

    // 释放辅助内存
    free(tmp);
}

int main()
{
    int arr[10] = {10, 5, 9, 6, 1, 2, 3, 7, 8, 4};
    MergeSort(arr, 10);
    for (int i = 0; i < 10; ++i)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}