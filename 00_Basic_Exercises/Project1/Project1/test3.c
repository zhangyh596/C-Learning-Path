//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//
//////k进制转换成10进制
////int k_to_decimal(const char* str, int k)
////{
////	int res = 0;
////	for (int i = 0; str[i] != '\0'; i++)
////	{
////		int digit = str[i] - '0';
////
////		res = res * k + digit;
////	}
////	return res;
////}
//
//////10进制转换成k进制
////void decimal_to_k(int n, int k)
////{
////	if (n == 0)
////	{
////		printf("0");
////		return;
////	}
////
////	int stack[100];
////	int top = -1;
////
////	while (n > 0)
////	{
////		int remainder = n % k;
////		stack[++top] = remainder;
////
////		n = n / k;
////	}
////
////	for (int i = top; i >= 0; i--)
////	{
////		if (stack[i] >= 10)
////		{
////			printf("%c", stack[i] - 10 + 'A');
////		}
////		else
////		{
////			printf("%d", stack[i]);
////		}
////	}
////	printf("\n");
////}
//
////算10进制转换成k进制的数位之和
//int main()
//{
//	int n, k;
//	scanf("%d %d", &n, &k);
//
//	int sum = 0;
//	while (n > 0)
//	{
//		sum += n % k;
//		n = n / k;
//	}
//	printf("%d\n", sum);
//	return 0;
//}