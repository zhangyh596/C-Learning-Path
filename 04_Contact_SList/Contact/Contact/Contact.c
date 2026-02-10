#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"
#include "SList.h"
#include <string.h>

//辅助函数（通过名字寻找节点）
static Contact* FindByName(Contact* pcon, char* name)
{
	Contact* pcur = pcon;
	while (pcur)
	{
		if (strcmp(pcur->data.name, name) == 0)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}

//通讯录初始化
void ContactInit(Contact** ppcon)
{
	*ppcon = NULL;
}

//添加联系人
void ContactAdd(Contact** ppcon)
{
	PeoInfo info;
	printf("请输入姓名：");
	scanf("%s", info.name);
	printf("请输入性别：");
	scanf("%s", info.gender);
	printf("请输入年龄：");
	scanf("%d", &info.age);
	printf("请输入电话：");
	scanf("%s", info.tel);
	printf("请输入地址：");
	scanf("%s", info.addr);

	SLTPushBack(ppcon, info);
	printf("添加成功！\n");
}