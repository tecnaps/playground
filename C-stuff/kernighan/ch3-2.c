#include <stdio.h>

#define MAXLENGTH 100

void escape(char s[], char t[]);
void apprehend(char s[], char t[]);

int main(){

    char s[] = "hello\t\n\tworld";
    char t[MAXLENGTH];
    escape(s, t);
    printf("%s\n", t);
    apprehend(s,t);
    printf("%s\n", s);
}

void escape(char s[], char t[]){

    /*copies strings and converts \n and \t into visible escape sequences*/
    int i, j;
    i = j = 0;

    while (s[i] != '\0'){
        switch (s[i]){
            case '\n':
                t[j] = '\\';
                j++;
                t[j] = 'n';
                i++;
                j++;
                break;
            case '\t':
                t[j] = '\\';
                j++;
                t[j] = 't';
                i++;
                j++;
                break;
            default:
                t[j] = s[i];
                i++;
                j++;
                break;
        }
    }
    t[j] = '\0';
}

void apprehend(char s[], char t[]){

    /*converts escape sequences into real characters*/
    
    int i, j;
    i=j=0;
    while (s[i] != '\0'){
        switch(s[i]){
            case '\\':
                switch(s[i+1]){
                    case 'n':
                        t[j] = '\n';
                        i+=2;
                        j++;
                        break;
                    case 't':
                        t[j] = '\t';
                        i+=2;
                        j++;
                        break;
                    default:
                        t[j] = s[i];
                        i++;
                        j++;
                        break;
                }
            default:
                t[j] = s[i];
                i++;
                j++;
                break;
        }
    }
    t[j] = '\0';
}
