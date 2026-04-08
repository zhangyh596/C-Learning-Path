//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	unsigned long long* arr = (unsigned long long*)malloc(sizeof(unsigned long long) * (n + 1));
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%llu", &arr[i]);
//	}
//
//	int T = 0;;
//	scanf("%d", &T);
//	for (int i = 0; i < T; i++)
//	{
//		int p = 0;
//		scanf("%d", &p);
//
//		if (p == 1)
//		{
//			arr[p] = arr[n] * arr[p + 1];
//		}
//		else if (p == n)
//		{
//			arr[p] = arr[p - 1] * arr[1];
//		}
//		else
//		{
//			arr[p] = arr[p - 1] * arr[p + 1];
//		}
//	}
//
//	for (int i = 1; i <= n; i++)
//	{
//		printf("%llu", arr[i]);
//		if (i < n)
//		{
//			printf(" ");
//		}
//	}
//	printf("\n");
//
//	free(arr);
//	arr = NULL;
//	return 0;
//}