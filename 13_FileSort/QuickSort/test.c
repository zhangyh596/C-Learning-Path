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

// 方法三：左右指针法
// 需要用到前面的swap函数
int partition_hoare(int *a, int low, int high)
{
    int pivot = a[low]; // 选最左边的元素作为基准值
    int left = low;
    int right = high;

    while (left < right)
    {
        // 必须right先走，找比pivot小的数
        // 因为最后交换的时候是把相遇的位置和基准值交换，这个相遇的位置的值必须比pivot小
        // 第一种情况：right 走着走着，主动撞上了停着的 left，下标为left的位置一定比pivot小
        // 第二种情况：left 走着走着，主动撞上了停着的 right，说明此时下标为right的值已经比pivot小了
        // 而如果让left先走，相遇的位置一定是一个比pivot大的数
        // 必须写a[right]>=pivot而不能写a[right]>pivot，否则可能陷入死循环（当下标为left和下标为right都等于pivot）
        while (left < right && a[right] >= pivot)
        {
            right--;
        }

        // left找比pivot大的数
        while (left < right && a[left] <= pivot)
        {
            left++;
        }

        if (left < right)
        {
            swap(&a[left], &a[right]);
        }
    }

    swap(&a[low], &a[left]);

    return left;
}

void QuickSort(int *a, int low, int high)
{
    // 当长度<=1不会进入
    if (low < high)
    {
        int pi = partition_hoare(a, low, high);

        // 递归实现左半边排序和右半边排序
        QuickSort(a, low, pi - 1);
        QuickSort(a, pi + 1, high);
    }
}

// 快速排序非递归版本实现(同时利用前后指针法的函数来实现)
// 定义一个简单的结构体，代表待处理的数组区间 [low, high]
typedef struct
{
    int low;
    int high;
} Range;

void QuickSortIterative(int *a, int low, int high)
{
    if (low >= high)
        return;

    // 手写显式栈，容量最大设为区间元素个数
    int maxCapacity = high - low + 1;
    Range stack[maxCapacity];
    int top = -1;

    // 把初始的大任务 [low, high] 压入栈中
    top++;
    stack[top].low = low;
    stack[top].high = high;

    // 不断弹栈处理，直到没有未完成的子任务
    while (top >= 0)
    {
        // 出栈一个区间任务
        int cur_low = stack[top].low;
        int cur_high = stack[top].high;
        top--;

        // 执行分区，拿到切分点 pi
        int pi = partition_lomuto(a, cur_low, cur_high);

        // 如果左半边元素个数 >= 2，把左区间压栈
        if (pi - 1 > cur_low)
        {
            top++;
            stack[top].low = cur_low;
            stack[top].high = pi - 1;
        }

        // 如果右半边元素个数 >= 2，把右区间压栈
        if (pi + 1 < cur_high)
        {
            top++;
            stack[top].low = pi + 1;
            stack[top].high = cur_high;
        }
    }
}

int main()
{
    int arr[10] = {10, 5, 9, 6, 1, 2, 3, 7, 8, 4};
    QuickSortIterative(arr, 0, 9);
    for (int i = 0; i < 10; ++i)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}