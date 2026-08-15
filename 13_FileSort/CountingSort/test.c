#include <stdio.h>

// 找最大值的函数（为了决定计数数组的长度）
int getMax(int *a, int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

// 计数排序
void CountingSort(int *a, int n)
{
    // 找到最大值，决定计数数组的大小
    int max = getMax(a, n);

    // 准备计数数组大小（比如最大值是 9，我们需要 0~9 号，共 10 个位置）
    int count[max + 1];
    for (int i = 0; i <= max; ++i)
    {
        count[i] = 0;
    }

    // 遍历原数组，数字是多少，对应位置的数量就 +1
    for (int i = 0; i < n; ++i)
    {
        int candidate = a[i];
        count[candidate]++;
    }

    // 按顺序输出结果，抄回原数组
    int index = 0;
    for (int i = 0; i <= max; ++i)
    {
        while (count[i] > 0)
        {
            a[index++] = i;
            count[i]--;
        }
    }
}

int main()
{
    int arr[10] = {10, 5, 9, 6, 1, 2, 3, 7, 8, 4};
    CountingSort(arr, 10);
    for (int i = 0; i < 10; ++i)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}