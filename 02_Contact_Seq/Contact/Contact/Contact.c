#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"
#include "Seqlist.h"
#include <string.h>

//通讯录的初始化
void ContactInit(Contact* con)
{
	SLInit(con);//直接调用顺序表
}

//通讯录的销毁
void ContactDestroy(Contact* con)
{
	SLDestroy(con);
}

//通讯录添加数据
void ContactAdd(Contact* con)
{
	peoInfo info;
	printf("请输入要添加的联系人姓名：\n");
	scanf("%s", info.name);
	printf("请输入要添加的联系人性别：\n");
	scanf("%s", info.gender);
	printf("请输入要添加的联系人年龄：\n");
	scanf("%d", &info.age);
	printf("请输入要添加的联系人电话：\n");
	scanf("%s", info.tel);
	printf("请输入要添加的联系人住址：\n");
	scanf("%s", info.addr);
	SLPushBack(con, info);
}

//根据姓名来查找
int FindByName(Contact* con, char name[])
{
	for (int i = 0; i < con->size; i++)
	{
		if (strcmp(con->a[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

//通讯录删除数据
void ContactDel(Contact* con)
{
	char name[NAME_MAX];
	printf("请输入要删除的联系人姓名：\n");
	scanf("%s", name);
	int find = FindByName(con, name);
	if (find < 0)
	{
		printf("要删除的联系人的数据不存在！\n");
		return;
	}
	SLErase(con, find);
	printf("删除成功\n");
}

//通讯录数据展示
void ContactShow(Contact* con)
{
	//表头
	printf("%s %s %s %s %s\n", "姓名", "性别", "年龄", "电话", "地址");
	for (int i = 0; i < con->size; i++)
	{
		printf("%-4s %-4s %-4d %-4s %-4s\n",
			con->a[i].name,
			con->a[i].gender,
			con->a[i].age,
			con->a[i].tel,
			con->a[i].addr
		);
	}
}

//通讯录数据修改
void ContactModify(Contact* con)
{
	char name[NAME_MAX];
	printf("请输入要修改的联系人姓名：\n");
	scanf("%s", name);
	int find = FindByName(con, name);
	if (find < 0)
	{
		printf("要修改的联系人的数据不存在！\n");
		return;
	}
	printf("请输入新的姓名：\n");
	scanf("%s", con->a[find].name);
	printf("请输入新的性别：\n");
	scanf("%s", con->a[find].gender);
	printf("请输入新的年龄：\n");
	scanf("%d", &con->a[find].age);
	printf("请输入新的电话：\n");
	scanf("%s", con->a[find].tel);
	printf("请输入新的住址：\n");
	scanf("%s", con->a[find].addr);
	printf("修改成功\n");
}

//通讯录查找
void ContactFind(Contact* con)
{
	char name[NAME_MAX];
	printf("请输入要查找的联系人姓名：\n");
	scanf("%s", name);
	int find = FindByName(con, name);
	if (find < 0)
	{
		printf("要查找的联系人的数据不存在！\n");
		return;
	}
	printf("%s %s %s %s %s\n", "姓名", "性别", "年龄", "电话", "地址");
	printf("%-4s %-4s %-4d %-4s %-4s\n",
		con->a[find].name,
		con->a[find].gender,
		con->a[find].age,
		con->a[find].tel,
		con->a[find].addr
	);
	printf("查找成功\n");
}