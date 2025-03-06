#include <stdio.h>

#define MAXLINE 1000

/*prints lines with 80 characters or more*/

int get_line(char line[], int maxline);
int main(){

    int len;
    char line[MAXLINE];

    while((len = get_line(line, MAXLINE)) > 0)
        if(len >= 80)
            printf("%s", line);
    return 0;

}

int get_line(char line[], int lim){

    int c, i;

    for (i=0; i< lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if(c == '\n'){
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}