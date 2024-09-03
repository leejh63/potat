#include <stdio.h>

#include <stdint.h>

int main()
{   // 부호존재
    int8_t int1 = -128;
    int16_t int2 = 32767;
    int32_t int3 = 2147483647;
    int64_t int4 = 9223372036854775807;
    printf("%d %d %d %lld\n", int1, int2, int3, int4);
    // 부호 없음
    uint8_t uint1 = 255;
    uint16_t uint2 = 65535;
    uint32_t uint3 = 4294967295;
    uint64_t uint4 = 18446744073709551615ull; // << ull 붙여줘야한다.
    printf("%u %u %u %llu\n", uint1, uint2, uint3, uint4);
    return 0;
}