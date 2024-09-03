#include <stdio.h>  // 표준입출력 std in out
// 함수 선언은 무조건 위에서 해야함
int var1(void)
{
    int x;  // 4정수형 int 변수선언%% 이스케이프 문자
    float y; // 4실수형 float 변수 선언
    double z; // 8실수형 double 선언 < float의 바이트한계로 표현못하는 경우사용
    x = 5;
    y = 12345678910.123456f;
    z = 12345678910.123456;  // 1 이 아니라 L이다
    printf("int-4바이트\n");
    printf("x = %d y = %.2f, z = %lf\n" , x, y, z);
    printf("메모리 크기 sizeof() x = %d, y = %d, z = %zu\n", sizeof(x), sizeof(y), sizeof(z));
}

int formun(void)
{
    int k;
    // 세미콜론 두개는 반드시 써워야 하며 안에 값은 굳이 안써도된다.
    for (k=1;k <= 5; k++ ) // (초기값; 조건; 증감) 증감시 k++, k=k+1, ++k, k += 1 뭐든 상관 없음
    {// 조건 만족시 내부 코드 실행
        printf("sss%d\n", k);
    }
}

int dobformun(void)
{
    int k, dob;
    // 세미콜론 두개는 반드시 써워야 하며 안에 값은 굳이 안써도된다.
    for (k=1;k <= 5; k++ ) // (초기값; 조건; 증감) 증감시 k++, k=k+1, ++k, k += 1 뭐든 상관 없음
    {// 조건 만족시 내부 코드 실행
        for (dob = 1; dob <= 3; dob++ )
            {
                printf("*");
            }
        printf("ddd%d\n", k);
    }
}

int trifor(void)
{
    int one, two, thr;
    for (one = 1; one <= 5; one++)
    {
        for (thr = 0; thr <(5 - one); thr++ )
        {
            printf("#");
        }

        for (two = 1; two < one; two++)
        {
            printf("*");
        }

        printf("O\n");
    }
}


int whilemun(void)
{
    int i;
    i = 1;
    while (i <= 10)
    {
        printf("%d\n", i);
        i++;
    }
}

int dowhilemun(void)
{
    int i;
    i = 1;
    do
    {
        printf("%d\n", i);
        i++;

    } while (i <= 10);
}
// 파이썬이랑 컨티뉴, 브레이크는 비슷함
int breakwhile(void)
{        
    int i;
    i = 10;
    
    while(1) //do
    {
        printf("%d\n", i);
        // i--;
        if(i < 0)
        {
            break;
        }
        i--;
    } // while(i<0);
}

int contiwhile(void)
{        
    int i;
    i = 10;
    
    while(i > 0) //do
    {
        printf("%d\n", i);

        i--;

        if((i % 2) == 1)
        {
            printf("hole");
            continue;
        }
        // i--;
    } // while(i<0);
}
//  버퍼는 임시 기억장소라고 생각하면 된다. 
// 데이터를 하나하나 입출력하는것이 아닌 한번에 다받아서 보내거나 출력한다.
int iobuffer(void)
{
    // char c; // char은 1바이트만 가능 따라서 이 코드로는 abc를 입력받아도 a만 출력된다.
    // scanf("%c", &c);
    // printf("%c", &c);
    
    // 입력받을떄 a치고 엔터를 치게되면 버퍼에 엔터값이 들어간다
    // getchar 함수 << 그냥 문자만 받아올 수 있음 
    // char c1, c2, c3;
    // scanf("%c%c%c", &c1, &c2, &c3);
    // printf("%c %c %c", c1, c2, c3);
    
    char d;
    d = getchar();
    while (getchar() != '\n'); //버퍼를 지우는 코드 굳이? 라는생각이 들긴함
    printf("%c", d);
}
// 반환값이 없다면 void 사용
void bae10(void)
{
    int n = 5;
    int i, max;
    // 배열값을 없이 생성시 0이 아닌 의미없는 값이 들어간다.
    // 배열 길이를 비워놓으면 자동으로 설정됨
    // n의 변수를 넣기 위해선 c가 아닌 c99를 이용해야한다.
    int a[] = {1, 5, 3, 6, 3}; //1차원 
    // a[][] 2차원이며 일반적으로 이중for문과 같이사용된다.

    max = a[0];

    for (i = 0; i < 5; i++)
    {
        printf("%d\n", a[i]);

        if (max <= a[i])
        {
            max = a[i];
        }
        printf("max = %d\n", max);
    }
}



int main(void)
{
    int x, y, z;
    // printf("hello\n");
    // scanf("%d %d %d", &x, &y, &z); // scanf > & 변수앞에 넣는거 잊지말자
    // printf("%d %d %d", x, y, z);
    // var1();
    // formun();
    // dobformun();
    // trifor();
    // whilemun();
    // printf("----------\n");
    // dowhilemun();
    // breakwhile();
    // contiwhile();
    // iobuffer();
    bae10();
    return 0;
}

// 입출력 함수 주의 
//        서식문자 > %d
// scanf("서식문자", &n);   < 반드시 서식문자 쓰고 변수 앞에 & 써야한다.
// 파이썬 에서 input 느낌

// 전치++a; or 후치a++    // a += 1
// 다른 변수와 같이 쓰일때는 주의 해야한다.
// b = ++a  >> 앞에서 부터 진행되기 때문에 a+1 을 해준뒤 b에 저장
// b = a++  >> b에 a를 먼저 넣어준 후 a+1이 진행된다. 
// b = ++a * ++a  << 만약 a가 7일 경우 a+1 한후 다시 a+1 한후 곱해준다 즉 9*9 가 된다.
// 증감연산자는 적당히 써야 좋다 많이 쓰면 효율 떨어진다.

// 비트 연산자의 경우 속도도 빠르고 효율적이다.
// 10진수 이상부터는 10이 1, 0 인지 10인지 구별못하기 때문에 A=11, B=12, C=13,,, 등으로 표현한다.
// 이항연산자, 두개의 항이 필요 
// &는 전부 1이면 1 ,아니면 0 |는 or연산,  ^ xor연산 
// 단항 연산자 ~ not연산자 

// 좌, 우 시프트 <<, >>
// 10 << 1   //10(=00001010)  << 1 //  00010100 == 20을 뜻함 맨앞 숫자는 버려지고 맨뒤는 0이 추가됨
// 시프트 될경우 값의 2배 혹은 2배씩 줄어든다.
// 우 시프트는 좌랑 같은 원리로 진행된다.

//////////////////////변수 접근범위, 생존기간
// 메모리는 data(low address) - heap - stack(high address) 순으로 구성된다.
//           실행~종료까지                   일시적 저장
//
// 함수 밖에서 선언된 변수 > 전역변수
// 함수내에서 static int 변수 > 정적변수
// 정적변수의 경우 선언된 함수 내에서만 사용가능 따라서 모듈화 시키기 좋다.
// 위 두 변수는 프로그램이 종료때까지 지워지지 않는다.
// 함수내 선언된 지역 변수의 경우 일시적으로 사용되는 변수 즉 함수내 블록을 벗어나게되면 사라진다.
// 스택 구조<<<따라서 사라지는 것도 스택구조영향을 받는다.
//
////////// 포인터 개념정리 //////////
// 주소 할당의 경우 1바이트당 한개의 주소를 준다
// 즉, int의 경우 a=5 일경우 a는 4개의 메모리 주소를 할당받는다.
// 변수 선언시 &을 붙여준다 
// int* a = &k;  << k의 주소를 a에 저장 /// k는 a를 참조한다. 라고 표현한다.
//         형식* << 형식형태의 주소 라는 의미이다. int* 정수 형태의 주소값 이라는 의미
// 포인터는 주소를 저장하는 변수라고 생각하면 된다.
// 포인터의 메모리 할당의 경우 32bit > 4byte, 64bit > 8byte
// 변수 형태에 맞게 포인터의 형태도 맞춰줘야한다.
// 포인터는 여러 주소의 값중 가장 위에있는 주소를 참조한다.
// 역참조 // a는 5를 의미 k는 a의 가장 위주소값의미 *k는 a의 값을 의미 << 이게 역참조

// * 뜻 곱하기, 주소를 저장하는 포인터, 역참조

