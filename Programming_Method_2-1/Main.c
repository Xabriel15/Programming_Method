#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    printf("Integer ranges:\n");

    printf("signed char:   %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char: 0 to %u\n", (unsigned int)UCHAR_MAX);

    printf("signed short:  %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short: 0 to %u\n", (unsigned int)USHRT_MAX);

    printf("signed int:    %d to %d\n", INT_MIN, INT_MAX);
    printf("unsigned int:  0 to %u\n", UINT_MAX);

    printf("signed long:   %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long: 0 to %lu\n", ULONG_MAX);

    printf("signed long long: %lld to %lld\n",
        LLONG_MIN, LLONG_MAX);
    printf("unsigned long long: 0 to %llu\n", ULLONG_MAX);

    printf("\nFloating-point ranges:\n");

    printf("float:       %e to %e\n", -FLT_MAX, FLT_MAX);
    printf("double:      %e to %e\n", -DBL_MAX, DBL_MAX);
    printf("long double: %Le to %Le\n", -LDBL_MAX, LDBL_MAX);

    printf("\nSmallest positive normalized values:\n");
    printf("float:       %e\n", FLT_MIN);
    printf("double:      %e\n", DBL_MIN);
    printf("long double: %Le\n", LDBL_MIN);

    return 0;
}
