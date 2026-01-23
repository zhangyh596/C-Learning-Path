#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <ctype.h>
//
//int main()
//{
//	int i = 0;
//	char str[] = "hello,world";
//	while (str[i])
//	{
//		str[i] = toupper(str[i]);//使用转换函数
//		putchar(str[i]);
//		i++;
//	}
//
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//size_t my_strlen(const char* str)
//{
//	int count = 0;
//	while (*str)
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	char str[] = "hello,world";
//	printf("%d", my_strlen(str));
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>

//size_t my_strlen(const char* str)
//{
//	char* p = str;
//	while (*p != '\0')
//		p++;
//	return p - str;
//}
//int main()
//{
//	char str[] = "hello,world";
//	printf("%zu", my_strlen(str));
//	return 0;
//}

#include <stdio.h>
#include <string.h>

char* my_strcpy(char* dest, const char* src)
{
	char* ret = dest;
	while (*dest++ = *src++)
	{

	}
	return ret;
}
int main()
{
	char dest[] = "hello";
	char src[] = "world";
	printf("%s", my_strcpy(dest, src));

	return 0;
}