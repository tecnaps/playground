#include <stdio.h>
#include <limits.h>

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

int rightrot(int x, int n);
int intBits();

int main(){

    int x = rightrot(1414, 5);
    printf("\n x:" BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(1414));
    printf("\n new x:" BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(1414>>5));

}

int rightrot(int x, int n){

int loss = x & ~(~0 << n);

return (x >> n) | (loss << intBits()-n+1);

}

int intBits(){
    int x = INT_MAX;
    int count = 2;
    
    while (x = x/2) 
        count++;
    
    return count;
}