#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"
#include "SList.h"
#include <string.h>

//辅助函数（通过名字寻找节点）
static Contact* FindByName(Contact* pc, char* name)
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