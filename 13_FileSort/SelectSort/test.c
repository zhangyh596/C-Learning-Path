#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// 直接选择排序
void SelectSort(int *a, int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int minIndex = i;

        // 寻找 [i, n-1] 区间内的最小值
        for (int j = i + 1; j < n; ++j)
        {
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }

        // 将找到的最小值放到当前轮次的开头 (i 的位置)
        if (minIndex != i)
        {
            swap(&a[i], &a[minIndex]);
        }
    }
}

// 二元选择排序（双向选择排序）
void DualSelectSort(int *a, int n)
{
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        int minIndex = left;
        int maxIndex = left;

        // 在 [left, right] 区间内同时寻找最大值和最小值的下标
        for (int i = left + 1; i <= right; ++i)
        {
            if (a[i] < a[minIndex])
            {
                minIndex = i;
            }
            if (a[i] > a[maxIndex])
            {
                maxIndex = i;
            }
        }
        // 优化：如果找了一圈发现最大值和最小值是一样的，
        // 说明剩下的数字全长一个样，直接提前收工！
        if (a[minIndex] == a[maxIndex])
        {
            break;
        }

        // 将最小值交换到最左端 (left)
        if (minIndex != left)
        {
            swap(&a[left], &a[minIndex]);
        }

        // 核心大坑修正：如果最大值原本就在 left 的位置
        // 经过上面的交换，最大值已经被换到了 minIndex 的位置！
        if (maxIndex == left)
        {
            maxIndex = minIndex;
        }

        if (maxIndex != right)
        {
            swap(&a[right], &a[maxIndex]);
        }

        left++;
        right--;
    }
}

int main()
{
    int arr1[10] = {10, 5, 9, 6, 1, 2, 3, 7, 8, 4};
    SelectSort(arr1, 10);
    for (int i = 0; i < 10; ++i)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    int arr2[10] = {10, 5, 9, 6, 1, 2, 3, 7, 8, 4};
    DualSelectSort(arr2, 10);
    for (int i = 0; i < 10; ++i)
    {
        printf("%d ", arr2[i]);
    }
    return 0;
}