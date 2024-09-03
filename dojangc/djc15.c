#include <stdio.h>
// 0으로 나누게 될경우 파일이 실행은 되지만 값들이 나오지 않는다 
// 이건 디버깅 진행할경우 예외처리가 뜬다 
// 디버깅은 항시 진행해볼것
int main()
{
    int num1;
    int num2;
    int num3;
    num1 = 3;
    num2 = 0;
    num3 = num1/num2; // 이때 디버깅해보면 오류뜬다.
    printf("%d = %d / %d \n", num3, num1, num2);

    return 0;
}