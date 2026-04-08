//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <limits.h>
//
//int main()
//{
//	char s[1005];
//	scanf("%s", s);
//
//	long long res = 0;
//
//	for (int i = 0; s[i] != '\0'; i++)
//	{
//		if (s[i] >= '0' && s[i] <= '9')
//		{
//			int digit = s[i] - '0';
//			res = res * 10 + digit;
//
//			if (res > INT_MAX)
//			{
//				printf("OVERFLOW\n");
//				return 0;
//			}
//		}
//	}
//	printf("%lld\n", res);
//	return 0;
//}