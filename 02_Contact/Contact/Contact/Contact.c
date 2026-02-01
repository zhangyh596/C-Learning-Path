#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"
#include "Seqlist.h"

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