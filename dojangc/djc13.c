#include <stdio.h>

int main()
{
    char char1;
    char1 = 'a';
    printf("%c 아스키 %d\n", char1, char1);
    printf("%c 아스키 %d\n", char1+1, char1+1);
    
    char char2;
    char2 = 97;
    printf("%c 아스키 %d", char2, char2);
    return 0;
}