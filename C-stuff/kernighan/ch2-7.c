#include <stdio.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  ((byte) & 0x80 ? '1' : '0'), \
  ((byte) & 0x40 ? '1' : '0'), \
  ((byte) & 0x20 ? '1' : '0'), \
  ((byte) & 0x10 ? '1' : '0'), \
  ((byte) & 0x08 ? '1' : '0'), \
  ((byte) & 0x04 ? '1' : '0'), \
  ((byte) & 0x02 ? '1' : '0'), \
  ((byte) & 0x01 ? '1' : '0') 

int invert(int x, int p, int n);


int main(){

int x = invert(2312314, 7, 5);
    printf("\n x:" BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(2312314));
    printf("\n y:" BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(7));
    printf("\n new x:" BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(x));

}

int invert(int x, int p, int n){

    /*  LHS
        ~0                              inverts all 0s to 1s
                                        (11111111)
        ~0 << n                         shifts the rightmost bit n positions left
                                        (n=5: 11100000)
        ~(~0 << n)                      inverts all bits
                                        (n=5: 00011111)
        ~(~0 << n)<< (p-n)              shifts the rightmost bit p-n positons left
                                        (n=5, p=7: 01111100)
        ~(~(~0 << n)<< (p-n))           inverts all bits
                                        (n=5, p=7: 10000011)
        x & ~(~(~0 << n)<< (p-n))       clears n bits from the pth position of x
                                        (n=5, p=7: x00000xx)
        RHS
        (~0 << n)                       shifts the rightmost bit n positions left
                                        (n=5: 11100000)
        ~(~0 << n)                      inverts all bits
                                        (n=5: 00011111)
        ~(~0 << n) << (p-n)             shifts the rightmost bit p-n positions left
                                        (n=5, p=7: 01111100)
        ~x & ~(~0 << n) << (p-n)        clears all bits except n bits from the 
                                        pth position of the inverted x
                                        (n=5, p=7: 0zzzzz00)

        LHS      | RHS
        x00000xx | 0zzzzz00 = xzzzzzxx
    */  

    return  x & ~(~(~0 << n)<< (p-n)) | ~x & ~(~0 << n) << (p-n);
}