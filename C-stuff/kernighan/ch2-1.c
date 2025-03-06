#include <limits.h>
#include <float.h>
#include <stdio.h>

int main(){
    printf("\nINTEGER LIMITS\n\n");
    printf("char bit limit: %d\n", CHAR_BIT);
    printf("char min: %d\n", CHAR_MIN);
    printf("char max: %d\n", CHAR_MAX);
    printf("signed char min: %d\n", SCHAR_MIN);
    printf("signed char max: %d\n", SCHAR_MAX);
    printf("unsigned char max: %d\n", UCHAR_MAX);
    printf("multibyte char max: %d\n", MB_LEN_MAX);
    printf("short int min: %d\n", SHRT_MIN);
    printf("short int max: %d\n", SHRT_MAX);
    printf("unsigned short int max: %d\n", USHRT_MAX);
    printf("int min: %d\n", INT_MIN);
    printf("int max: %d\n", INT_MAX);
    printf("unsigned int max: %d\n", UINT_MAX);
    printf("long int min: %li\n", LONG_MIN);
    printf("long int max: %li\n", LONG_MAX);
    printf("unsigned long int max: %lu\n", ULONG_MAX);

    printf("\nFLOATING POINT LIMITS\n\n");
    printf("\nFLT_RADIX defines the base: 2, 10, 16\n\n");
    printf("number of digits in the mantissa (number) of a float: %d\n", FLT_MANT_DIG);
    printf("number of digits in the mantissa (number) of a double: %d\n", DBL_MANT_DIG);
    printf("number of digits in the mantissa (number) of a long double: %d\n", LDBL_MANT_DIG);

    printf("number of decimal digits (base 10) of a float: %d\n", FLT_DIG);
    printf("number of decimal digits (base 10) of a double: %d\n", DBL_DIG);
    printf("number of decimal digits (base 10) of a long double: %d\n", LDBL_DIG);

    printf("minimum negative integer value of the exponent of a float: %d\n", FLT_MIN_EXP);
    printf("minimum negative integer value of the exponent of a double: %d\n", DBL_MIN_EXP);
    printf("minimum negative integer value of the exponent of a long double: %d\n", LDBL_MIN_EXP);

    printf("maximum integer value of the exponent of a float: %d\n", FLT_MAX_EXP);
    printf("maximum integer value of the exponent of a double: %d\n", DBL_MAX_EXP);
    printf("maximum integer value of the exponent of a long double: %d\n", LDBL_MAX_EXP);

    printf("minimum finite floating-point value of a float: %e\n", FLT_MIN);
    printf("minimum finite floating-point value of a double: %e\n", DBL_MIN);
    printf("minimum finite floating-point value of a long double: %le\n", LDBL_MIN);

    printf("maximum finite floating-point value of a float: %e\n", FLT_MAX);
    printf("maximum finite floating-point value of a double: %e\n", DBL_MAX);
    printf("maximum finite floating-point value of a long double: %le\n", LDBL_MAX);

    printf("least significant digit representable of a float: %e\n", FLT_EPSILON);
    printf("least significant digit representable of a double: %e\n", DBL_EPSILON);
    printf("least significant digit representable of a long double: %le\n", LDBL_EPSILON);

    printf("minimum negative integer value of the exponent base 10 of a float: %d\n", FLT_MIN_10_EXP);
    printf("minimum negative integer value of the exponent base 10 of a double: %d\n", DBL_MIN_10_EXP);
    printf("minimum negative integer value of the exponent base 10 of a long double: %d\n", LDBL_MIN_10_EXP);

    printf("maximum integer value of the exponent base 10 of a float: %d\n", FLT_MAX_10_EXP);
    printf("maximum integer value of the exponent base 10 of a double: %d\n", DBL_MAX_10_EXP);
    printf("maximum integer value of the exponent base 10 of a long double: %d\n", LDBL_MAX_10_EXP);

}