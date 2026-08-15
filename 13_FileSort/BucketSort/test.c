#include <stdio.h>

// 找最大值的函数(找出最大值，决定建几层楼)
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

// 桶排序（利用数字的“大小范围”来进行排序）
// 设定一个分桶规则：“按十位数分桶”
void BucketSort(int *a, int n)
{
    // 找到最大值，决定桶的数量
    int max = getMax(a, n);
    int bucketNum = max / 10 + 1; // 比如最大是45，45/10+1=5，建5个桶(0到4)

    // 准备 bucketNum 个水桶，假设每个桶最多装 n 个数字
    int buckets[bucketNum][n];
    int counts[bucketNum]; // 记录每个桶现在有多少个数字
    for (int i = 0; i < bucketNum; ++i)
    {
        counts[i] = 0;
    }

    // 按分数段对号入座
    for (int i = 0; i < n; ++i)
    {
        int index = a[i] / 10; // 算出该进几号桶（几十就进几号桶）
        buckets[index][counts[index]] = a[i];
        counts[index]++;
    }

    // 在每个桶内部，把数字排好序（这里用简单的冒泡排序）
    for (int i = 0; i < bucketNum; ++i)
    {
        int numInThisBucket = counts[i]; // 记住当前桶里面有多少个数字

        for (int j = 0; j < numInThisBucket - 1; ++j)
        {
            for (int k = 0; k < numInThisBucket - 1 - j; ++k)
            {
                if (buckets[i][k] > buckets[i][k + 1])
                {
                    int tmp = buckets[i][k];
                    buckets[i][k] = buckets[i][k + 1];
                    buckets[i][k + 1] = tmp;
                }
            }
        }
    }

    // 按 0号到最高号桶的顺序，依次把人叫出来
    int index = 0;
    for (int i = 0; i < bucketNum; ++i)
    {
        for (int j = 0; j < counts[i]; ++j)
        {
            a[index++] = buckets[i][j];
        }
    }
}

int main()
{
    int arr[10] = {10, 5, 9, 6, 1, 2, 3, 7, 8, 4};
    BucketSort(arr, 10);
    for (int i = 0; i < 10; ++i)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}