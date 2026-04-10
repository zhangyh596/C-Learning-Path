#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MyString.h"

void Init(MyString* s, int cap)
{
	s->str = (char*)malloc(cap * sizeof(char));
	s->str[0] = '\0';
	s->len = 0;
	s->cap = cap;
}

void append(MyString* s, const char* tail)
{
	int len_tail = 0;
	const char* p_tail = tail;
	while (*p_tail != '\0')
	{
		len_tail++;
		p_tail++;
	}

	int new_len = s->len + len_tail;
	if (new_len >= s->cap)
	{
		int new_cap = new_len + 1;
		char* tmp = (char*)realloc(s->str, new_cap * sizeof(char));
		if (tmp == NULL)
		{
			printf("realloc fail");
			return;
		}
		s->str = tmp;
		s->cap = new_cap;
	}

	char* p = s->str;// 让p走到s->str的末尾
	while (*p != '\0')
	{
		p++;
	}

	p_tail = tail;
	while (*p_tail != '\0')
	{
		*p = *p_tail;
		p++;
		p_tail++;
	}

	*p = '\0';
	s->len = new_len;
}

void Destroy(MyString* s)
{
	if (s->str != NULL)
	{
		free(s->str);
		s->str = NULL;
		s->len = 0;
		s->cap = 0;
	}
}
