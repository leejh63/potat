#include <stdio.h>

int main()
{
    unsigned char num1;
    char num2;
    num1 = 256; // 최댓값255 > 0 오버플로우 부호존재x
    num2 = 128; // 최댓값127 > -128 오버플로우 부호존재o
    printf("%d %d ", num1, num2);
    return 0;
}