#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void* b)
{
	const char* str1 = (const char*)a;
	const char* str2 = (const char*)b;

	return strcmp(str1, str2);
}

int main()
{
	/*char word[100][100];
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", word[i]);
	}

	qsort(word, n, sizeof(word[0]), cmp);

	for (int i = 0; i < n; i++)
	{
		printf("%s ", word[i]);
	}*/

	char line[] = "12345,99,100000";
	char word[100][100];
	int count = 0;

	char* token = strtok(line, ",");
	while (token != NULL)
	{
		strcpy(word[count], token);
		count++;
		token = strtok(NULL, ",");
	}

	for (int i = 0; i < count; i++)
	{
		printf("%s ", word[i]);
	}
	return 0;
}