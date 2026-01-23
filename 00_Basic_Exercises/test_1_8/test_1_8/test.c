#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int arr[2000005];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < m; i++)
	{
		int num = 0;
		scanf("%d", &num);
		printf("%d", arr[num]);
		printf("\n");
	}
	return 0;
}