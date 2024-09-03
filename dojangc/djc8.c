#include <stdio.h>
//정수형 최댓값
#include <limits.h>
// 실수형 최대 최소은 아래 코드 필요
#include <float.h>

int main()
{
    char minnum1 = CHAR_MIN-1;
    int minnum2 = INT_MIN;
    float minnum3 = FLT_MIN;
    char maxnum1 = CHAR_MAX;
    int maxnum2 = INT_MAX;
    float maxnum3 = FLT_MAX;
    printf("char = %d ~ %d\nint = %d ~ %d\nfloat = %f ~ %f", minnum1, maxnum1, minnum2, maxnum2, minnum3, maxnum3);
    return 0;
}