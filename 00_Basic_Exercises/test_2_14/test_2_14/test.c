#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int v;
	struct Node* next;
};

struct Node* heads[100005];

void add(int u, int v)
{
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->v = v;
	newnode->next = heads[u];
	heads[u] = newnode;
}

int n, m;
int count;
int vis[100005];

void dfs(int u)
{
	vis[u] = 1;
	struct Node* pcur = heads[u];
	while (pcur != NULL)
	{
		if (vis[pcur->v] == 0)
		{
			vis[pcur->v] = 1;
			dfs(pcur->v);
		}
		pcur = pcur->next;
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int p = 0, q = 0;
		scanf("%d %d", &p, &q);
		add(p, q);
		add(q, p);
	}
	for (int i = 1; i <= n; i++)
	{
		if (vis[i] == 0)
		{
			count++;
			dfs(i);
		}
	}
	printf("%d", count);
	return 0;
}