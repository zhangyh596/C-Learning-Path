#pragma once

#define NAME_MAX 100
#define GENDER_MAX 10
#define TEL_MAX 15
#define ADDR_MAX 100

//定义联系人数据结构
typedef struct personoInfo
{
	char name[NAME_MAX];
	char gender[GENDER_MAX];
	int age;
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}PeoInfo;

typedef struct SListNode Contact;//前置声明

//通讯录初始化
void ContactInit(Contact** ppcon);
//添加联系人
void ContactAdd(Contact** ppcon);
//删除联系人
void ContactDel(Contact** ppcon);
//修改联系人
void ContactModify(Contact** ppcon);