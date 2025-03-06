#include <string.h>
#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main(){
    char s1[] = "hello";
    char s2[] = "world";
    squeeze(s1, s2);
    printf("%s\n", s1);
}

void squeeze(char s1[], char s2[]){

    /*deletes all characters in in s1 that matches any character in s2*/

    int i, j, k, skip;

    i = k = skip = 0;
    while(i < strlen(s1)){
        for (j=0; j < strlen(s2); ++j)
            if (s1[i] == s2[j]){        // if character is present
                skip=1;
                break;
            }
        if (skip == 0){                 // if character is not present
            s1[k++] = s1[i];     
        }
        skip = 0;
        i++;
    }
    s1[k] = '\0';
}