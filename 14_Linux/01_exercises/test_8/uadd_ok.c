#include <stdio.h>

int uadd_ok(unsigned x, unsigned y)
{
	unsigned sum = x + y;
	return sum >= x;
}

int main()
{
	int flag = uadd_ok(1, 2);
	printf("%d", flag);
	return 0;
}