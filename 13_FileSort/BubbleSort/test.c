#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void BubbleSort(int *a, int n)
{
    // 外层循环控制趟数：n 个元素最多需要跑 n-1 趟
    for (int i = 0; i < n - 1; ++i)
    {
        bool flag = false;

        // 内层循环负责冒泡：每跑完一趟，最后面就会多一个固定好的大元素
        // 所以内层循环只需要走到 n - 1 - i 即可
        for (int j = 0; j < n - 1 - i; ++j)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
                flag = true; // 发生了交换，修改标记
            }
        }

        if (flag == false)
        {
            break;
        }
    }
}

int main()
{
    int arr[10] = {10, 5, 9, 6, 1, 2, 3, 7, 8, 4};
    BubbleSort(arr, 10);
    for (int i = 0; i < 10; ++i)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}