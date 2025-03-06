#include <stdio.h>

/*kernighans algorithm*/

int bitcount(unsigned x);

int main(){

    printf("%d\n", bitcount(5));

}

int bitcount(unsigned x){

    /*counts the number of bits set to 1*/

    int b = 0;

    while (x != 0){

        x = x &(x-01);
        b++; 
    }

    return b;
}