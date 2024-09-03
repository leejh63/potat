#include <stdio.h> // 표준 입출력 헤더
#include <stdlib.h>

// 기본 실행영역
int main(void){
    int test1;
    int *scoreP;
    const int test2 = 100;
    printf("hello\n");
    scanf("%d", &test1);
    printf("%d\n", test1);
    printf("%d\n", test2);
    // test2 = 3; 에러가 난다.
    printf("%d", test2);
    return 0;
}

// 변수 선언
// 자료형 변수명 = 값;
// 정수int %d,
// 실수float %f < .2f < 소수점 둘째자리까지 표현해라
// 더블double %f // longdouble이란것도 있으며 Lf 로 표현
// const 자료형 으로 사용 상수는 값 변경 불가.
// 문자 char 변수명 = "값" // 한글자 혹은 문자열
// scanf의 경우 문자열을 받을때는 변수명의 값 지정필요, char a[256]; 이런식으로 지정해야한다 