// word_size.c
#include <stdio.h>

int main()
{
    void *ptr;
    printf("指针大小 (字节): %lu\n", sizeof(ptr));
    printf("机器字长 (Bits): %lu\n", sizeof(ptr) * 8);
    return 0;
}