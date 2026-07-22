#include <stdio.h>

// 辅助函数，交换两个变量的值
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// 向下调整函数（下沉函数）
// a是目标数组，n是当前堆的大小，i是需要下沉调整的节点
void Heapify(int *a, int n, int i)
{
    int largest = i;       // 默认当前根节点最大
    int left = 2 * i + 1;  // 左子节点索引
    int right = 2 * i + 2; // 右子节点索引

    // 如果左子节点存在，且比当前largest还大
    if (left < n && a[left] > a[largest])
    {
        largest = left;
    }

    // 如果右子节点存在，且比当前largest还大
    if (right < n && a[right] > a[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(&a[i], &a[largest]);

        // largest被调整到下面了，但可能依然会比下面的成员还小
        Heapify(a, n, largest); // 递归下沉
    }
}

void HeapSort(int *a, int n)
{
    // 从最后一个有子节点的根节点（（n-1-1）/2）开始，从下往上
    for (int i = n / 2 - 1; i >= 0; --i)
    {
        Heapify(a, n, i);
    }
    // 执行完这个循环，数组里的最大值绝对在arr[0]

    // 现在的 n 是总人数，我们每次把最大的踢到数组最后面，然后缩小圈子
    for (int i = n - 1; i > 0; --i)
    {
        // 1. arr[0] 是当前最大值，把它和当前堆的最后一个位置 i 交换
        // 这样最大值就永远固定在数组末尾了
        swap(&a[0], &a[i]);

        // 2. 交换后，原来的小喽啰被推到了 0 号
        // 但注意！此时前 i 个元素里，除了 0 号位，其余部分依然保持着堆的完美结构
        // 所以我们只需要对 0 号位这个小喽啰，执行一次下沉
        // 注意这里传入的边界是 i，意味着已经排好序的后面部分不再参与比较
        Heapify(a, i, 0);
    }
}

int main()
{
    int arr[10] = {10, 5, 9, 6, 1, 2, 3, 7, 8, 4};
    HeapSort(arr, 10);
    for (int i = 0; i < 10; ++i)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}