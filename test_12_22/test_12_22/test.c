#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int main()
//{
//	char s[] = "zhangsan 20 90.5";
//	char name[20];
//	int age;
//	float score;
//	int ret = sscanf(s, "%s %d %f", name, &age, &score);
//	printf("成功读取变量个数：%d\n", ret);
//	printf("name=%s age=%d score=%.1f", name, age, score);
//	return 0;
//}
//
//#include <stdio.h>
//
//int main()
//{
//	char buf[100];
//	int id = 1001;
//	float price = 29.9;
//	char name[] = "book";
//	int len = sprintf(buf, "商品：%s,编号：%d,价格：%.1f", name, id, price);
//	printf("成功写入字符数%d\n", len);
//	printf("拼接结果：%s", buf);
//	return 0;
//}


#include <stdio.h>

int main()
{
	FILE* pf = fopen("test.txt", "r");
	if (NULL == pf)
	{
		perror("fopen failed");
	}
	char buf[100];
	while (fgets(buf, sizeof(buf), pf) != NULL)
	{
		printf("%s", buf);
	}
	if (feof(pf))
	{
		printf("\n已到达文件末尾\n");
	}
	else if (ferror(pf))
	{
		printf("\0发生文件读写错误\n");
	}
	fclose(pf);
	pf = NULL;
	return 0;
}
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen failed");
//	}
//	char buf[100];
//	while (fgets(buf, sizeof(buf), pf) != NULL)
//	{
//		printf("%s", buf);
//	}
//	if (feof(pf))
//	{
//		printf("\n已读取到文件末尾\n");
//	}
//	else
//	{
//		printf("\n读取过程中发生错误\n");
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
////
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("fopen failed");
//	}
//	char buf[100];
//	fgets(buf, sizeof(buf), pf);
//	printf("第一次读取%s\n", buf);
//
//	rewind(pf);
//	fgets(buf, sizeof(buf), pf);
//	printf("第二次读取%s", buf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//int main()
//{
//	int n;
//	FILE* pFile;
//	char buffer[27];
//
//	pFile = fopen("myfile.txt", "w+");
//	for (n = 'A'; n <= 'Z'; n++)
//		fputc(n, pFile);
//	rewind(pFile);
//
//	fread(buffer, 1, 26, pFile);
//	fclose(pFile);
//
//	buffer[26] = '\0';
//	printf(buffer);
//	return 0;
//}


//int main()
//{
//	FILE* pf = fopen("test.txt", "rb");
//	if (NULL == pf)
//	{
//		perror("fopen failed");
//	}
//	fseek(pf, 0, SEEK_END);
//	long size = ftell(pf);
//	printf("文件大小：%ld字节\n", size);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	FILE* pFile;
//	pFile = fopen("example.txt", "wb");
//	fputs("This is an apple.", pFile);
//	fseek(pFile, 9, SEEK_SET);
//	fputs(" sam", pFile);
//	fclose(pFile);
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (NULL == pf)
//	{
//		perror("fopen failed");
//	}
//	fseek(pf, 5, SEEK_SET);
//	int ch = fgetc(pf);
//	if (ch == EOF)
//	{
//		printf("读取失败或已到文件末尾\n");
//	}
//	else
//	{
//		printf("读取的字符：%c\n", ch);
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}