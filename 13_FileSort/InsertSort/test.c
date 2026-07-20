#include <stdio.h>

void InsertSort(int *a, int n)
{
    // [0, end]有序，end + 1 位置插入[0, end]使[0, end + 1]有序
    for (int i = 0; i < n - 1; ++i)
    {
        int end = i;
        int tmp = a[end + 1];
        while (end >= 0)
        {
            if (a[end] > tmp)
            {
                a[end + 1] = a[end];
                --end;
            }
            else
            {
                break;
            }
        }
        // 因为end可能会走到-1
        a[end + 1] = tmp;
    }
}

int main()
{
    int arr[10] = {10, 5, 9, 6, 1, 2, 3, 7, 8, 4};
    InsertSort(arr, 10);
    for (int i = 0; i < 10; ++i)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}