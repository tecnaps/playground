#include <stdio.h>

#define MAXLINE 1000

void reverse_line(char line[], char reverse[], int len);
int get_line(char line[], int maxline);

int main() {

    int c, len;
    char line[MAXLINE], reverse[MAXLINE];

    while((len = get_line(line, MAXLINE)) > 0){
        reverse_line(line, reverse, len);
        printf("%s", reverse);
    }
    return 0;
}

int get_line(char line[], int lim){
    int c, i;

    for (i=0; i< lim-1 && (c=getchar())!= EOF && c != '\n'; ++i)
        line[i] = c;
    if(c == '\n'){
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void reverse_line(char line[], char reverse[], int lim){
    int i;

    for (i = 0; i<lim-1; ++i)
        reverse[i] = line[lim-(i+2)];
    reverse[i] = '\0';      //note: i is incremented before the loop ends
}
