#define _CRT_SECURE_NO_WARNINGS 1


//#include <stdio.h>
//
//int main()
//{
//	FILE* pr = fopen("data.txt", "r");
//	if (NULL == pr)
//	{
//		perror("文件打开失败：");
//		return 1;
//	}
//	FILE* pw = fopen("data_copy.txt", "w");
//	if (NULL == pw)
//	{
//		perror("文件打开失败：");
//		return 1;
//	}
//	int ch;
//	while ((ch = fgetc(pr)) != EOF)
//	{
//		fputc(ch, pw);
//	}
//	fclose(pr);
//	pr = NULL;
//	fclose(pw);
//	pw = NULL;
//	return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("text.txt", "wb");
//	fwrite(&a, 4, 1, pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	FILE* pf = fopen("data.txt", "w");
//	if (NULL == pf)
//	{
//		perror("fopen failed");//打印错误原因
//	}
//	//后续操作...
//	fclose(pf);
//	pf = NULL;//避免野指针
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen failed");
//	}
//	int ch;//用int类型接收而非char
//	while ((ch = fgetc(pf)) != EOF)
//	{
//		putchar(ch);//输出读取到的字符
//	}
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	if (NULL == pf)
//	{
//		perror("fopen failed");
//	}
//	//写入字符
//	fputc('h', pf);
//	fputc('e', pf);
//	fputc('l', pf);
//	fputc('l', pf);
//	fputc('o', pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (NULL == pf)
//	{
//		perror("fopen failed");
//	}
//	char buf[1024];
//	while (fgets(buf, sizeof(buf), pf) != NULL)
//	{
//		printf("%s", buf);
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	if (NULL == pf)
//	{
//		perror("fopen failed");
//	}
//	const char* str1 = "hello";
//	const char* str2 = "world";
//	fputs(str1, pf);
//	fputs("\n", pf);
//	fputs(str2, pf);
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	//data.txt的内容是10 3.14 hello
//	FILE* pf = fopen("data.txt", "r");
//	if (NULL == pf)
//	{
//		perror("fopen failed");
//	}
//	int a;
//	float b;
//	char c[20];
//	int count = fscanf(pf, "%d %f %s", &a, &b, c);
//	printf("读取到的个数：%d\n", count);
//	printf("a=%d,b=%.2f,c=%s", a, b, c);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	FILE* pf = fopen("data.txt", "w");
//	if (NULL == pf)
//	{
//		perror("fopen failed");
//	}
//	int id = 1001;
//	char name[] = "zhangsan";
//	float score = 90.5;
//	fprintf(pf, "%d %s %.1f", id, name, score);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//
#include <stdio.h>

int main()
{
	FILE* pf = fopen("data.bin", "rb");
	if (NULL == pf)
	{
		perror("fopen failed");
	}
	int arr[5];
	size_t count = fread(arr, sizeof(int), 5, pf);
	printf("读取到的个数：%zd\n", count);
	for (int i = 0; i < count; i++)
	{
		printf("%d ", arr[i]);
	}
	fclose(pf);
	pf = NULL;
	return 0;
}

//#include <stdio.h>
//
//int main()
//{
//	FILE* pf = fopen("data.bin", "wb");
//	if (NULL == pf)
//	{
//		perror("fopen failed");
//	}
//	int arr[5] = { 1,2,3,4,5 };
//	size_t count = fwrite(&arr, sizeof(int), 5, pf);
//	if (count == 5)
//	{
//		printf("数据写入成功 \n");
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

