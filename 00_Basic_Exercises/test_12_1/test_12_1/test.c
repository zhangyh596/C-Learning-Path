#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//union
//{
//	int i;
//	char c;
//}un;
//int main()
//{
//	int a = 1;
//	char* p = (char*)&a;
//	if (*p == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	un.i = 1;
//	if (un.c == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int a = 0x11223344;
//
//	return 0;
//}


//
//#include <stdio.h>
//
//int main()
//{
//    for (int i = 10000; i <= 99999; i++)
//    {
//        int tmp = i;
//        int sum = 0;
//        for (int j = 10; j <= 10000; j *= 10)
//        {
//            sum += (tmp % j) * (tmp / j);
//        }
//        if (sum == i)
//        {
//            printf("%d ", i);
//        }
//    }
//    return 0;
//}

#include <stdio.h>

int main()
{
	int n = 0;
	scanf("%d", &n);
	int arr[50] = { 0 };
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int ret = 0;
	scanf("%d", &ret);
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] != ret)
		{
			arr[j] = arr[i];
			j++;
		}
	}
	for (int k = 0; k < j; k++)
	{
		printf("%d ", arr[k]);
	}
	return 0;
}