#include <stdio.h>

// 排个位、十位、百位……取决于数组里最大的那个数字有几位
int getMax(int *a, int n)
{
    int max = a[0];
    for (int i = 1; i < n; ++i)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}

// 基数排序（利用数字的“位”（个位、十位、百位）来进行排序）
void RadixSort(int *a, int n)
{
    int max = getMax(a, n);

    // 提取某一位数字的方法，我们用一个变量 exp（代表 1, 10, 100...）
    // 看个位：(数字 / 1) % 10
    // 看十位：(数字 / 10) % 10
    // 看百位：(数字 / 100) % 10
    // exp 从 1 开始，每次乘 10。只要 max / exp 大于 0，说明最高位还没处理完
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        // 准备 10 个水桶，假设每个桶最多装 n 个数字
        int buckets[10][n];
        // 记录每个桶放了多少个数字
        int bucket_counts[10] = {0};

        // 遍历数组，将数字放入对应的桶里面
        for (int i = 0; i < n; ++i)
        {
            int digit = (a[i] / exp) % 10; // 取出对应的位
            buckets[digit][bucket_counts[digit]] = a[i];
            bucket_counts[digit]++;
        }

        // 按顺序将桶里面的数字拿出来
        int index = 0;
        for (int i = 0; i < 10; ++i) // 按 0 到 9 号桶顺序
        {
            for (int j = 0; j < bucket_counts[i]; ++j) // 桶里有几个就拿几次（先进先拿）
            {
                a[index++] = buckets[i][j];
            }
        }
    }
}

int main()
{
    int arr[10] = {10, 5, 9, 6, 1, 2, 3, 7, 8, 4};
    RadixSort(arr, 10);
    for (int i = 0; i < 10; ++i)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}