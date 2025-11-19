#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
void swap(int* a, int* b)
{
	if (*a > *b)
	{
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}
}
int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	swap(&a, &b);
	swap(&a, &c);
	swap(&b, &c);
	if (c >= a + b)
		printf("Not triangle\n");
	else
	{
		if (c * c == a * a + b * b)
			printf("Right triangle\n");
		if (c * c < a * a + b * b)
			printf("Acute triangle\n");
		if ((c * c > a * a + b * b) )
			printf("Obtuse triangle\n");
		if (a == b || b == c || a == c)
			printf("Isosceles triangle\n");
		if (a == b && b == c)
			printf("Equilateral triangle\n");
	}

	return 0;
}

//
//void swap(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//#include <stdio.h>
//int main()
//{
//	int a, b, c;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a > b) swap(&a, &b);
//	if (a > c) swap(&a, &c);
//	if (b > c) swap(&b, &c);
//	if (a + b <= c)
//		printf("Not triangle");
//	else
//	{
//		if (c * c == a * a + b * b)
//			printf("Right triangle\n");
//		if (c * c < a * a + b * b)
//			printf("Acute triangle\n");
//		if (c * c > a * a + b * b)
//			printf("Obtuse triangle\n");
//		if (a == b || a == c || b == c)
//			printf("Isosceles triangle\n");
//		if (a == b && a == c)
//			printf("Equilateral triangle\n");
//	}
//	return 0;
//}