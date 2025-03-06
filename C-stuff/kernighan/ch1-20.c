#include <stdio.h>

#define TAB 8

/*  convert Tabstops into blanks    
    note: distance varies */

int main(){

    int c, i, cnt;
    cnt = 0;

    while ((c=getchar())!= EOF){

        if (c =='\n'){
            putchar(c);
            cnt = 0;
        }
        else if (c == '\t')
            for (i = 0; i <= cnt % TAB; ++i ){
                putchar(' ');
                ++cnt;
            }
        else{
            putchar(c);
            ++cnt;

        }
    }
}
