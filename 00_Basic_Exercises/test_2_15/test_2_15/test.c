#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int int_max(int x, int y)
//{
//	return x > y ? x : y;
//}
//
//float float_max(float x, float y)
//{
//	return x > y ? x : y;
//}
//
#define GENERIC_MAX(type) \
type type##_max(type x, type y) \
{                               \
      return (x>y?x:y);         \
}

GENERIC_MAX(int)
GENERIC_MAX(float)

int main()
{
	int a = int_max(2, 3);
	printf("%d", a);
	return 0;
}