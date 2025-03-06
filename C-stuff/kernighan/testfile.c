/*this is a file to run sample code from the book*/

#include <stdio.h>

#define MAXLINE 1000

int getlin(char line[], int maxline);
void copy(char to[], char from[]);

int main(){

    /*print longest line from input*/

    int len, max;
    char line[MAXLINE], longest[MAXLINE];

    max=0;
    while((len = getlin(line, MAXLINE)) > 0)
        if (len > max){
            max = len;
            copy(longest, line);
        }
    
    if (max > 0)
        printf("%s", longest);
    return 0;
}

int getlin(char s[], int lim){

    /*reads line into s and returns its length*/

    int c,i;

    for (i=0; i < lim-1 && (c=getchar())!= EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]){

    /*copy 'from' into 'to', assumption: 'to' is big enough to hold 'from'*/

    int i;

    i=0;
    while((to[i] = from[i]) != '\0')
        ++i;
}