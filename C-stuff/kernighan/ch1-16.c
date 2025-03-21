#include <stdio.h>

#define MAXLINE 1000

/*print arbitrary long lines and their length*/

int get_line(char line[], int maxline);
void copy(char to[], char from[]);


int main(){
    int len, max;
    char line[MAXLINE], longest[MAXLINE];

    max=0;
    while((len = get_line(line, MAXLINE)) > 0)
        if(len > max){
            max = len;
            printf("%d: %s", len, line);
            copy(longest, line);
        }
    if (max > 0)
        printf("longest line\n%s", longest);
    return 0;

}

int get_line(char s[], int lim){

    int c, i;

    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if(c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]){

    int i;
    
    i=0;
    while((to[i] = from[i]) != '\0')
        ++i;
}