#include <stdio.h>
#include <float.h>

int main()
{
    float fmin = FLT_MIN;
    float fmax = FLT_MAX;
    double dmin = DBL_MIN;
    double dmax = DBL_MAX;
    printf("float = %.3f ~ %e\ndouble = %.3f ~ %e\n", fmin, fmax, dmin, dmax);

    float fminunder = fmin/10000000;
    float fmaxover = fmax*1000;
    double dminunder = dmin/1000000;
    double dmaxover = dmax*1000;
    printf("float = %.3f ~ %f\ndouble = %.3f ~ %f", fminunder, fmaxover, dminunder, dmaxover);
    return 0;
}
// 정수와 실수의 오버, 언더 플로우 의 차이점 존재한다.