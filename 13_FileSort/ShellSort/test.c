#include <stdio.h>

void ShellSort(int *a, int n)
{
    // 每次让步长折半。或者 gap = gap / 3 + 1
    int gap = n;

    // 最外层循环：控制步长不断缩小，直到 gap = 1
    while (gap > 1)
    {
        gap /= 2;
        // 和InsertSort基本相似
        for (int i = 0; i < n - gap; ++i)
        {
            int end = i;
            int tmp = a[end + gap]; // 抓取相隔 gap 的新牌

            while (end >= 0)
            {
                if (a[end] > tmp)
                {
                    a[end + gap] = a[end]; // 跨大步往后挪
                    end -= gap;            // 指针往前跳 gap 格
                }
                else
                {
                    break;
                }
            }
            a[end + gap] = tmp;
        }
    }
}

int main()
{
    int arr[10] = {10, 5, 9, 6, 1, 2, 3, 7, 8, 4};
    ShellSort(arr, 10);
    for (int i = 0; i < 10; ++i)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}