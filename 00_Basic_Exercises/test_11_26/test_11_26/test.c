#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//
//char* my_strncpy(char* dest, const char* src,size_t n)
//{
//	char* ret = dest;
//	assert(dest && src);
//	while (n > 0 && *src != '\0')
//	{
//		*dest++ = *src++;
//		n--;
//	}
//	while (n > 0)
//	{
//		*dest++ = '\0';
//		n--;
//	}
//	return ret;
//
//
//}
//int main()
//{
//	char dest[20] = "hello";
//	char src[] = "world";
//	printf("%s", my_strncpy(dest, src, 5));
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//char* my_strncat(char* dest, const char* src, size_t n)
//{
//	char* ret = dest;
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	while (n > 0 && *src != '\0')
//	{
//		*dest = *src;
//		dest++;
//		src++;
//		n--;
//	}
//	*dest = '\0';
//	return ret;
//}
//int main()
//{
//	char dest[20] = "hello,";
//	char src[] = "world";
//	printf("%s", my_strncat(dest, src, 5));
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//
//int my_strncmp(const char* str1, const char* str2, size_t n)
//{
//	if (n == 0)
//		return 0;
//	while (n > 0&&str1 != '\0' && str2 != '\0' && (*str1 == *str2))
//	{
//		str1++;
//		str2++;
//		n--;
//	}
//	return *str1 - *str2;
//}
//int main()
//{
//	char str1[] = "apple";
//	char str2[] = "banana";
//	printf("%d", my_strncmp(str1, str2, 5));
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//char* my_strstr(const char* str1, const char* str2)
//{
//	char* cp = (char*)str1;//需要强制类型转换，遍历str1的字符
//	char* s1;//当前str1的匹配指针
//	char* s2;//当前str2的匹配指针
//	if (*str2 == '\0')
//		return ((char*)str1);
//	while (*cp != '\0')//*cp为真表示str1还未走到末尾
//	{
//		s1 = cp;//不匹配s1返回到cp的位置
//		s2 = (char*)str2;
//		while (*s1 && *s2 && (*s1 == *s2))//对s1和s2匹配
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 = '\0')
//			return cp;
//		cp++;
//	}
//	return (NULL);
//}
//int main()
//{
//	char str1[] = "abcdeabcd";
//	char str2[] = "bcd";
//	printf("%s", my_strstr(str1, str2));
//	return 0;
//}

#include <stdio.h>
#include <string.h>

int main()
{
	char arr[] = "111.222.333.444";
	char* sep = '.';
	char* str = NULL;
	for (str = strtok(arr, sep); str != NULL; str = strtok(NULL, sep))
	{
		printf("%s\n", str);
	}
	return 0;
}