#include <stdio.h>

// 方法一：挖坑法
int partition_hole(int *a, int low, int high)
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

    return left; // 返回基准值的最终位置
}

// 方法二：前后指针法
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition_lomuto(int *a, int low, int high)
{
    int pivot = a[high]; // 选最右边的元素作为基准值
    int i = low - 1;     // 慢指针指向比pivot小的最后一位

    // 快指针从low到high-1
    for (int j = low; j < high; ++j)
    {
        if (a[j] <= pivot)
        {
            ++i; // 小数区扩张一格
            swap(&a[i], &a[j]);
        }
    }

    // 全部扫完之后将pivot放到i+1
    swap(&a[i + 1], &a[high]);

    return i + 1; // 返回 Pivot 最终坐完之后的位置下标
}

void QuickSort(int *a, int low, int high)
{
    // 当长度<=1不会进入
    if (low < high)
    {
        int pi = partition_lomuto(a, low, high);

        // 递归实现左半边排序和右半边排序
        QuickSort(a, low, pi - 1);
        QuickSort(a, pi + 1, high);
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