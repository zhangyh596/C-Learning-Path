#define _CRT_SECURE_NO_WARNINGS 1

//一
//#include <stdio.h>
//
//int main()
//{
//	int a, b, c;
//	scanf("%d %d %d", &a, &b, &c);
//
//	printf("%d %d %d\n", c, a, b);
//	return 0;
//}




//二
//#include <stdio.h>
//
//int arr[1005];
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	int sum = arr[0];
//	int max = arr[0];
//	for (int i = 1; i < n; i++)
//	{
//		sum += arr[i];
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//
//	printf("%d %d\n", sum, max);
//	return 0;
//}




//三
//#include <stdio.h>
//
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	if (a <= 0 || b <= 0)
//	{
//		printf("invalid\n");
//		return 0;
//	}
//	while (a > 0)
//	{
//		int tmp = a;
//		a = b % a;
//		b = tmp;
//	}
//	printf("%d\n", b);
//	return 0;
//}



//四
//#include <stdio.h>
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n - 1 - i; j++)
//		{
//			printf(" ");
//		}
//
//		for (int k = 0; k < 2 * i + 1; k++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}




//五
//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	char s[1005];
//	fgets(s, sizeof(s), stdin);
//
//	char ss[1000][1000];
//	int count = 0;// 统计单词数
//	int len = 0;// 该单词的长度
//	for (int i = 0; s[i] != '\0'; i++)
//	{
//		if (s[i] == ' ' || s[i] == '\n')
//		{
//			ss[count][len] = '\0';
//
//			count++;
//			len = 0;
//		}
//		else
//		{
//			ss[count][len++] = s[i];
//		}
//	}
//
//	for (int i = count - 1; i >= 0; i--)
//	{
//		printf("%s ", ss[i]);
//	}
//	return 0;
//}


//#include <stdio.h>
//
//int main() {
//    char ss[1000][1005];
//    int count = 0;
//
//    // scanf("%s") 每次刚好读取一个不含空格的单词
//    // 当它成功读取时，返回 1；当读到文件末尾（或终端输入结束）时，返回 EOF
//    while (scanf("%s", ss[count]) != EOF) {
//        count++;
//    }
//
//    // 倒序打印
//    for (int i = count - 1; i >= 0; i--) {
//        printf("%s", ss[i]);
//        if (i > 0) {
//            printf(" ");
//        }
//    }
//    printf("\n");
//
//    return 0;
//}


//六
//#include <stdio.h>
//
//int main()
//{
//	int num = 0;
//	while (1)
//	{
//		scanf("%d", &num);
//		if (num == -1)
//		{
//			return 0;
//		}
//
//		int sum = 0;
//		int tmp = num;
//		while (tmp > 0)
//		{
//			sum = sum * 10 + tmp % 10;
//			tmp = tmp / 10;
//		}
//
//		if (sum == num)
//		{
//			printf("Yes\n");
//		}
//		else
//		{
//			printf("No\n");
//		}
//	}
//	return 0;
//}




//七
//#include <stdio.h>
//#include <stdlib.h>
//
//struct ListNode
//{
//	int val;
//	struct ListNode* next;
//};
//
//int main()
//{
//	struct ListNode* head = NULL;
//	struct ListNode* tail = NULL;
//
//	int num = 0;
//	while (1)
//	{
//		scanf("%d", &num);
//		if (num == -1)
//		{
//			break;
//		}
//		
//		struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
//		if (newnode == NULL)
//		{
//			return 1;
//		}
//		newnode->val = num;
//		newnode->next = NULL;
//
//		if (head == NULL)
//		{
//			head = tail = newnode;
//		}
//		else
//		{
//			tail->next = newnode;
//			tail = newnode;
//		}
//	}
//
//	struct ListNode* prev = NULL;
//	struct ListNode* pcur = head;
//	while (pcur)
//	{
//		struct ListNode* next = pcur->next;
//		pcur->next = prev;
//		prev = pcur;
//		pcur = next;
//	}
//
//	while (prev)
//	{
//		printf("%d ", prev->val);
//		prev = prev->next;
//	}
//	return 0;
//}





//八
//#include <stdio.h>
//
//int dx[4] = { 0, 1, 0, -1 };
//int dy[4] = { 1, 0, -1, 0 };
//
//int arr[100][100];
//int vis[100][100];
//
//int main()
//{
//	int m, n;
//	scanf("%d %d", &m, &n);
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//
//	int dir = 0;
//	int x = 0, y = 0;
//	for (int i = 0; i < m * n; i++)
//	{
//		vis[x][y] = 1;
//		printf("%d ", arr[x][y]);
//
//		int nx = x + dx[dir];
//		int ny = y + dy[dir];
//
//		if (nx >= m || nx < 0 || ny >= n || ny < 0 || vis[nx][ny] == 1)
//		{
//			dir = (dir + 1) % 4;
//			nx = x + dx[dir];
//			ny = y + dy[dir];
//		}
//		x = nx;
//		y = ny;
//	}
//	return 0;
//}


//九
//#include <stdio.h>
//
//void f(int n, char a, char b, char c)
//{
//	if (n == 1)
//	{
//		printf("%c -> %c\n", a, c);
//		return;
//	}
//
//	f(n - 1, a, c, b);
//	printf("%c -> %c\n", a, c);
//	f(n - 1, b, a, c);
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	f(n, 'A', 'B', 'C');
//	return 0;
//}


//十
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool isLeapYear(int year)
{
	if (year % 400 == 0 || (year % 100 != 0) && (year % 4 == 0))
	{
		return true;
	}
	return false;
}

int main()
{
	int year1, month1, day1;
	int year2, month2, day2;
	scanf("%d-%d-%d", &year1, &month1, &day1);
	scanf("%d-%d-%d", &year2, &month2, &day2);

	int sum = 0;
	if (year1 > year2)
	{
		for (int i = year2; i <= year1; i++)
		{
			if (isLeapYear(i))
			{
				days[2]++;
			}

			if (i == year1)
			{
				for (int j = 0; j < month1; j++)
				{
					sum += days[j];
				}
				sum += day1;
			}
			else if (i == year2)
			{
				sum += days[month2] - day2;
				for (int j = month2 + 1; j <= 12; j++)
				{
					sum += days[j];
				}
			}
			else
			{
				sum += 365 + days[2] - 28;
			}
			if (isLeapYear(i))
			{
				days[2]--;
			}
		}
	}
	else if (year1 < year2)
	{
		for (int i = year1; i <= year2; i++)
		{
			if (isLeapYear(i))
			{
				days[2]++;
			}

			if (i == year2)
			{
				for (int j = 0; j < month2; j++)
				{
					sum += days[j];
				}
				sum += day2;
			}
			else if (i == year1)
			{
				sum += days[month1] - day1;
				for (int j = month1 + 1; j <= 12; j++)
				{
					sum += days[j];
				}
			}
			else
			{
				sum += 365 + days[2] - 28;
			}
			if (isLeapYear(i))
			{
				days[2]--;
			}
		}
	}
	else
	{
		if (isLeapYear(year1))
		{
			days[2]++;
		}

		if (month1 > month2)
		{
			sum += days[month2] - day2;
			for (int i = month2 + 1; i < month1; i++)
			{
				sum += days[i];
			}
			sum += day1;
		}
		else if (month1 < month2)
		{
			sum += days[month1] - day1;
			for (int i = month1 + 1; i < month2; i++)
			{
				sum += days[i];
			}
			sum += day2;
		}
		else
		{
			sum += abs(day1 - day2);
		}

		if (isLeapYear)
		{
			days[2]--;
		}
	}

	printf("%d", sum);

	return 0;
}





//十一
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct Student
//{
//	int id;
//	char name[20];
//	int score1;
//	int score2;
//	int total;
//}Student;
//
//Student students[100000];
//
//int cmp(const void* p1, const void* p2)
//{
//	Student* student1 = (Student*)p1;
//	Student* student2 = (Student*)p2;
//
//	if (student1->total > student2->total)
//	{
//		return -1;
//	}
//	else if (student1->total == student2->total)
//	{
//		if (student1->id > student2->id)
//		{
//			return 1;
//		}
//		else if(student1->id < student2->id)
//		{
//			return -1;
//		}
//		else
//		{
//			return 0;
//		}
//	}
//	else
//	{
//		return 1;
//	}
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d %s %d %d", &students[i].id, students[i].name, &students[i].score1, &students[i].score2);
//		students[i].total = students[i].score1 + students[i].score2;
//	}
//
//	qsort(students, n, sizeof(Student), cmp);
//
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d %s %d\n", students[i].id, students[i].name, students[i].total);
//	}
//	return 0;
//}





//十二
//#include <stdio.h>
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//
//	int sum = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (i % 3 == 0 || i % 7 == 0)
//		{
//			sum += i;
//		}
//	}
//
//	printf("%d", sum);
//	return 0;
//}