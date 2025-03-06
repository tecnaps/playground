#include <stdio.h>
#include <string.h>
#include <limits.h>

/*e.g.  8 Bit :          -128 = 1000 0000 
        2s complement of -128 = 0111 1111 add 1 = 1000 0000 = -128 (overflow condition)
        there is no representation of +128 in 2s complement, hence the behaviour 
        is undefined*/

#define MAXLENGTH 100

void itoa(int n, char s[]);
void reverse(char s[]);

int main(){

    char s1[MAXLENGTH];
    itoa(INT_MIN, s1);
    printf("%s, %d\n", s1, INT_MAX);
}

void itoa(int n, char s[]){

    int i, sign, overflow;
    overflow = 0;

    if ((sign = n) < 0)
        if (sign  == INT_MIN){          // if n is the most negative number 
                                        // overflow is set and n set to INT_MAX
            n = INT_MAX;
            overflow = 1;
        }
        else    
            n = -n;

    i = 0;
    do{
        s[i++] = n % 10 + '0';
        if (i == 1 && overflow == 1){   // test if overflow is set
            overflow = 0;
            s[i-1]++;
        }
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]){

    int c, i, j;
    for (i=0, j=strlen(s)-1; i < j; i++, j--){
        c = s[i];
        s[i]=s[j];
        s[j]=c;
    }
}