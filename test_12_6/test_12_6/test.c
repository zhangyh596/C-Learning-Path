#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main()
//{
//    char arr[4];
//    scanf("%s", arr);
//    if (arr[0] == '<' && arr[1] == '<' && arr[2] == '<')
//    {
//        printf("abc");
//    }
//    else if (arr[0] == '<' && arr[1] == '<' && arr[2] == '>')
//    {
//        printf("acb");
//    }
//    else if (arr[0] == '<' && arr[1] == '>' && arr[2] == '>')
//    {
//        printf("cab");
//    }
//    else if (arr[0] == '>' && arr[1] == '<' && arr[2] == '<')
//    {
//        printf("bac");
//    }
//    else if (arr[0] == '>' && arr[1] == '>' && arr[2] == '>')
//    {
//        printf("cba");
//    }
//    else if (arr[0] == '>' && arr[1] == '>' && arr[2] == '<')
//    {
//        printf("bca");
//    }
//    return 0;
//}


#include <stdio.h>

int main()
{
	int arr[200001] = { 0 };
	int n = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		arr[i] = i;
	}
	int m = 0;
	scanf("%d", &m);
	for (int j = 0; j < m; j++)
	{
		int op = 0;
		switch (op)
		case 1:
	}

	return 0;
}