#include <stdio.h>
#include <stdlib.h>

int main()
{
    char* num;
    num = (char*)malloc(sizeof(char) * 4) ;
    *num = 'a';
    *(num + 1) = 'b';
    *(num + 2) = 'c';
    *(num + 3) = 'd';
    printf("num addr = %p 1, %c 2, %c 3, %c 4, %c",num, num[0], num[1], num[2], num[3]);
    free(num);
    return 0;
}