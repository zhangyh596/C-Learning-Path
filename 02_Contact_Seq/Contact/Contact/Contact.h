#pragma once

#define NAME_MAX 20
#define GENDER_MAX 10
#define TEL_MAX 20
#define ADDR_MAX 100

//定义联系人数据结构
typedef struct personInfo
{
	char name[NAME_MAX];//名字
	char gender[GENDER_MAX];//性别
	int age;//年龄
	char tel[TEL_MAX];//电话号码
	char addr[ADDR_MAX];//住址
}peoInfo;

typedef struct Seqlist Contact;//前置声明

//通讯录的初始化
void ContactInit(Contact* con);
//通讯录的销毁
void ContactDestroy(Contact* con);
//通讯录添加数据
void ContactAdd(Contact* con);
//通讯录删除数据
void ContactDel(Contact* con);
//通讯录数据修改
void ContactModify(Contact* con);
//通讯录查找
void ContactFind(Contact* con);
//通讯录数据展示
void ContactShow(Contact* con);
