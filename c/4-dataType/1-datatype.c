#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdint.h>

int main(void) 
{
    printf("|---------------------------|----------------|----------------------|----------------------|\n");
    printf("| %-25s | %-14s | %-20s | %-20s |\n", "Type", "Size (bytes)", "Min", "Max");
    printf("|---------------------------|----------------|----------------------|----------------------|\n");

    printf("| %-25s | %-14zu | %-20d | %-20d |\n", "char", sizeof(char), CHAR_MIN, CHAR_MAX);
    printf("| %-25s | %-14zu | %-20d | %-20d |\n", "signed char", sizeof(signed char), SCHAR_MIN, SCHAR_MAX);
    printf("| %-25s | %-14zu | %-20u | %-20u |\n", "unsigned char", sizeof(unsigned char), 0, UCHAR_MAX);

    printf("| %-25s | %-14zu | %-20d | %-20d |\n", "short", sizeof(short), SHRT_MIN, SHRT_MAX);
    printf("| %-25s | %-14zu | %-20u | %-20u |\n", "unsigned short", sizeof(unsigned short), 0, USHRT_MAX);

    printf("| %-25s | %-14zu | %-20d | %-20d |\n", "int", sizeof(int), INT_MIN, INT_MAX);
    printf("| %-25s | %-14zu | %-20u | %-20u |\n", "unsigned int", sizeof(unsigned int), 0, UINT_MAX);

    printf("| %-25s | %-14zu | %-20ld | %-20ld |\n", "long", sizeof(long), LONG_MIN, LONG_MAX);
    printf("| %-25s | %-14zu | %-20lu | %-20lu |\n", "unsigned long", sizeof(unsigned long), 0UL, ULONG_MAX);

    printf("| %-25s | %-14zu | %-20lld | %-20lld |\n", "long long", sizeof(long long), LLONG_MIN, LLONG_MAX);
    printf("| %-25s | %-14zu | %-20llu | %-20llu |\n", "unsigned long long", sizeof(unsigned long long), 0ULL, ULLONG_MAX);

    printf("| %-25s | %-14zu | %-20e | %-20e |\n", "float", sizeof(float), FLT_MIN, FLT_MAX);
    printf("| %-25s | %-14zu | %-20e | %-20e |\n", "double", sizeof(double), DBL_MIN, DBL_MAX);
    printf("| %-25s | %-14zu | %-20Le | %-20Le |\n", "long double", sizeof(long double), LDBL_MIN, LDBL_MAX);

    printf("|---------------------------|----------------|----------------------|----------------------|\n");

    // tipos fixos de <stdint.h>
    printf("| %-25s | %-14zu | %-20d | %-20d |\n", "int8_t", sizeof(int8_t), INT8_MIN, INT8_MAX);
    printf("| %-25s | %-14zu | %-20u | %-20u |\n", "uint8_t", sizeof(uint8_t), 0, UINT8_MAX);

    printf("| %-25s | %-14zu | %-20d | %-20d |\n", "int16_t", sizeof(int16_t), INT16_MIN, INT16_MAX);
    printf("| %-25s | %-14zu | %-20u | %-20u |\n", "uint16_t", sizeof(uint16_t), 0, UINT16_MAX);

    printf("| %-25s | %-14zu | %-20d | %-20d |\n", "int32_t", sizeof(int32_t), INT32_MIN, INT32_MAX);
    printf("| %-25s | %-14zu | %-20u | %-20u |\n", "uint32_t", sizeof(uint32_t), 0U, UINT32_MAX);

    printf("| %-25s | %-14zu | %-20lld | %-20lld |\n", "int64_t", sizeof(int64_t), INT64_MIN, INT64_MAX);
    printf("| %-25s | %-14zu | %-20llu | %-20llu |\n", "uint64_t", sizeof(uint64_t), 0ULL, UINT64_MAX);

    printf("|---------------------------|----------------|----------------------|----------------------|\n");

    return 0;
}

