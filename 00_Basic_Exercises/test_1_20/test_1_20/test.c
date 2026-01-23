#define _CRT_SECURE_NO_WARNINGS 1


//
//int allocate_matrix(int*** ptr_matrix, int rows, int cols)
//{
//	*ptr_matrix = (int**)malloc(rows * sizeof(int*));
//	for (int i = 0; i < rows; i++)
//	{
//		*(*ptr_matrix + i) = (int*)malloc(cols * sizeof(int));
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int rows, cols;
//	scanf("%d %d", &rows, &cols);
//	int** p = (int**)malloc(rows * sizeof(int*));
//	for (int i = 0; i < rows; i++)
//	{
//		p[i] = (int*)malloc(cols * sizeof(int));
//	}
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			p[i][j] = 5 * i + j;
//		}
//	}
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			printf("%2d ", p[i][j]);
//		}
//		printf("\n");
//	}
//	for (int i = 0; i < 3; i++)
//	{
//		free(p[i]);
//		p[i] = NULL;
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

#include <stdio.h>
#include <string.h>

int main()
{
	char s1[100], s2[100];
	scanf("%s %s", s1, s2);
	int len1 = strlen(s1), len2 = strlen(s2);
	int a[100] = { 0 }, b[100] = { 0 }, c[100] = { 0 };
	for (int i = 0; i < len1; i++)
	{
		a[i] = s1[len1 - 1 - i] - '0';
	}
	for (int i = 0; i < len2; i++)
	{
		b[i] = s2[len2 - 1 - i] - '0';
	}
	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			c[i + j] += a[i] * b[i];
			c[i + j + 1] += c[i + j] / 10;
			c[i + j] = c[i + j] % 10;
		}
	}
	return 0;
}