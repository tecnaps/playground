#include <string.h>
#include <ctype.h>
#include <stdio.h>

#define MAXLEN 8

int htoi (char s[]); 

int main(){
    htoi("0x1fee4a");
}

int htoi(char s[]){

    int i, n;
    i = n = 0;

    if (s[1] == 'x' || s[1] == 'X')
        i = 2;

    while (i < strlen(s)){
        if (s[i] >= '0' && s[i]<='9')
            n = 16*n+(s[i]-'0');
        else if (s[i]>='a' && s[i]<='f')
            n = 16*n+(s[i]-'a'+10);
        else if (s[i]>='A' && s[i]<='F')
            n = 16*n+(s[i]-'A'+10);
        else{
            printf("invalid input\n");
            return -1; 
        }
        ++i;
    }
    return n;
}