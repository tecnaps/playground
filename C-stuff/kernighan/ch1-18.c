#include <stdio.h>

#define MAXLINE 1000

/*remove trailing blanks and tabs and delete blank lines*/

int get_line(char line[], int maxline);
void trim(char line[], int len);


int main(){

    int len;
    char line[MAXLINE], trimmed[MAXLINE];

    while ((len = get_line(line, MAXLINE)) >0){
        trim(line, len);
        printf("%s", line);
    }
    return 0;

}

int get_line(char line[], int lim){

    int c, i;

    for(i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c='\n'){
        line[i] = c;
        ++i;
    }
    line[i]='\0';
    return i;
}

void trim(char line[], int len) {

    int i;

    for (i = len-1; 0 < i; --i)
        if (line[i] != ' ' && line[i] != '\t'){
            line[i+1] = '\0';
            return;
        }
    if (i == 0)
        line[i] ='\0';
}