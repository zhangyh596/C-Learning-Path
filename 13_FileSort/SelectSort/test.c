#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

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

int main()
{
    int arr[10] = {10, 5, 9, 6, 1, 2, 3, 7, 8, 4};
    SelectSort(arr, 10);
    for (int i = 0; i < 10; ++i)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}