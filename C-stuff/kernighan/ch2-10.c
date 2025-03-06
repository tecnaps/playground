#include <stdio.h>

int lower (int c){

    /*converts upper case letters to lower case*/

    return (c>= 'A' && c <='Z') ? c + 'a'-'A' : c;

}