#include <stdio.h>

// https://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format
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

int setbits(int x, int p, int n, int y);


int main(){

    int x = setbits(2312314, 7, 5, 7);
    printf("\n x:" BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(2312314));
    printf("\n y:" BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(7));
    printf("\n new x:" BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(x));
}

int setbits(int x, int p, int n, int y){

    //index starts at 1 not 0 (use p+1 for 0)
    /*  RHS of |

        ~0                              inverts 0 to 1s 
                                        (11111111)
        ~0 << n                         shifts the 1s n positions to the left adding 0s 
                                        (n=5: 11100000)
        ~(~0 << n)                      inverts all the bits 
                                        (n=5: 00011111)
        y & ~(~0 << n)                  gets the n  last bits of y
                                        (n=5: 000yyyyy)
        (y & ~(~0 << n)) << (p+1-n)     shifts n last bits of y to the pth 
                                        position adding 0s
                                        (n=5: 0yyyyy00 for p = 7)
        LHS of |

        ~(~0 << n )                     inverts all bits
                                        (n=5: 00011111)                                
        ~(~0 << n ) << (p+1-n)          shifts the 1s to the pth position to the 
                                        left adding 0s 
                                        (n=5: 01111100 for p=7)                               
        ~(~(~0 << n ) << (p+1-n))       inverts all bits
                                        (n=5: 10000011 for p=7)
        x & ~(~(~0 << n ) << (p+1-n))   clears n bits form the pth position of x
                                        (n=5: x00000xx for p=7)

        LHS      | RHS                                
        x00000xx | 0yyyyy00 = xyyyyyxx */

    return x & ~(~(~0 << n ) << (p-n)) | (y & ~(~0 << n)) << (p-n);
}