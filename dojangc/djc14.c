#include <stdio.h>

int main()
{   // const 는 변수 선언시 초기화 진행 필요
    const int num1 = 10;
    printf("안녕 %d\n", num1);

    float flo1;
    double dou1;
    // 입출력 형식 주의 할것 더블의 경우 scanf는 %lf 이다.
    scanf("%f %lf", &flo1, &dou1);
    printf("%f %f\n", flo1, dou1);

    return 0;
}