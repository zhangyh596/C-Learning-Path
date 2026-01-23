#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <string.h>
//
//char* my_strcat(char* dest, const char* src)
//{
//	char* ret = dest;
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	while (*src != '\0')
//	{
//		*dest = *src;
//		dest++;
//		src++;
//	}
//	*dest = '\0';
//	return ret;
//}
//int main()
//{
//	char dest[20] = "hello,";
//	char src[] = "world";
//	printf("%s", my_strcat(dest, src));
//	return 0;
//}


//
//int my_strcmp(const char* str1, const char* str2)
//{
//	while (str1 != '\0'&&str2 != '\0'&&(*str1 == *str2))
//	{
//		str1++;
//		str2++;
//	}
//	return *str1 - *str2;
//}
//int main()
//{
//	char str1[] = "apple";
//	char str2[] = "banana";
//	printf("%d", my_strcmp(str1, str2));
//	return 0;
//}

#include <stdio.h>
#include <string.h>

int main()
{
	char dest[10] = "hello";
	char src[] = "world";
	printf("%s", strncpy(dest, src, 5));
	return 0;
}