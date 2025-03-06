#include <stdio.h>

#define MAXLINE 100

int main(){

    int i, lim;
    char c;
    char s[MAXLINE];


    lim = 100;
    i = 0;
    while((c=getchar())!= EOF){
        if (i < lim-1)
            if (c!='\n')
                s[i] = c;
        else
            break;
        ++i;
    }
    s[i] = '\0';

    printf("%s\n", s);
}