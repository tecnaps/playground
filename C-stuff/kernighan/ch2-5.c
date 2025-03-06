// see strpbrk in string.h, returns pointer

#include <string.h>
#include <stdio.h>

void any(char s1[], char s2[]);

int main(){
    char s1[] = "Hello";
    char s2[] = "world";
    any(s1, s2);
}

void any(char s1[], char s2[]){

    /* prints the first occurence of a letter from s2 in s1 
       or -1 if not present */

    int  i, j, skip;
    skip = 0;

    for (i = 0; i < strlen(s2); ++i){
        for(j = 0; j < strlen(s1); ++j){
            if(s1[j] == s2[i]){                 // checks if a letter is found in s1
                printf("%c : %d\n", s2[i], j);
                skip = 1;
                break;
            }
        }
        if (skip == 1){                         // skip if a letter was found in s1
            skip = 0;
            continue;
        } else
            printf("%c : -1\n", s2[i]);
    }
}
