#include <stdio.h>

// 方法一：挖坑法
void QuickSort(int *a, int low, int high)
{
    // 当长度<=1不会进入
    if (low < high)
    {
        // 分区挖坑开始
        int pivot = a[low]; // 把左边的数挖走，形成第一个坑
        int left = low;
        int right = high;

        while (left < right)
        {
            // 右指针找小数填入左坑
            while (left < right && a[right] >= pivot)
            {
                right--;
            }
            // 防止是因为left == right而跳出循环的情况
            if (left < right)
            {
                a[left] = a[right];
                left++;
            }

            // 左指针找大数填入右坑
            while (left < right && a[left] <= pivot)
            {
                left++;
            }
            // 防止是因为left == right而跳出循环的情况
            if (left < right)
            {
                a[right] = a[left];
                right--;
            }
        }

        // 此时left == right
        a[left] = pivot;

        // 递归实现左半边排序和右半边排序
        QuickSort(a, low, left - 1);
        QuickSort(a, left + 1, high);
    }
}

int main()
{
    int arr[10] = {10, 5, 9, 6, 1, 2, 3, 7, 8, 4};
    QuickSort(arr, 0, 9);
    for (int i = 0; i < 10; ++i)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}