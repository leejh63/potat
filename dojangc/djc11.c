#include <stdio.h>
// long double 제외시킴
int main()
{
    float num1 = 0.0f;
    double num2 = 0.0;
    printf("float = %d\ndouble = %d", sizeof(num1), sizeof(num2));
    return 0;
}