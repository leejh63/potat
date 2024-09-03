#include <stdio.h>

int main()
{
    int num1 = 0;
    int size;
    size = sizeof(num1);
    printf("char=%d\nint=%d\nfloat=%d",
            sizeof(char),
            sizeof(int),
            sizeof(float));
    return 0;
}