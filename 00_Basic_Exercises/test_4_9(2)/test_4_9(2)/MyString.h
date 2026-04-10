#pragma once

typedef struct {
	char* str;
	int len;
	int cap;
}MyString;

void Init(MyString* s, int cap);
void append(MyString* s, const char* tail);
void Destroy(MyString* s);