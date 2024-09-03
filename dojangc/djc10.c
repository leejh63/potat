#include <stdio.h>
// long double 의 경우 잘안나옴 컴파일러 차이인걸로 예상
// 대부분의 시스템에서는 double을 잘 지원하며, 정밀도도 충분하다고 함.
int main()
{
    float num1 = 0.1f;
    double num2 = 3867.215820;
    double num3 = 9.327512;
    printf("%f %f %Lf\n", num1, num2, num3);

    float num11 = 3.e5f; // 300000
    double num22 = -1.2345e-2; //-0.012345
    double num33 = 5.21e+9; //5210000000
    printf("%e %e %Le\n", num11, num22, num33);
    return 0;
}