#include <stdio.h>
#include <string.h>

#define MAXLENGTH 1000

void expand(char s1[], char s2[]);

int main(){

    char s1[] = "-a-g-z1-9 Hello World-";
    char s2[MAXLENGTH];
    expand(s1, s2);
    printf("%s\n", s2);
}

void expand(char s1[], char s2[]){

    /*expands shorthand notations a-z, 0-9 etc*/

    int i, j; 
    i = j = 0;

    while (s1[i]!= '\0'){

        switch(s1[i]){
            case '-':
                if (i>0 && s1[i-1] != ' ' && s1[i-1] != '\t' && 
                    s1[i-1] != '\n' && s1[i-1] != '-')
                    
                    if (i+1 < strlen(s1) && s1[i+1] != ' ' && s1[i+1] != '\t' && 
                        s1[i+1] != '\n' && s1[i+1] != '\0' && s1[i+1] != '-'){
                        
                        for (int k = s1[i-1]+1; k < s1[i+1]; k++){
                            s2[j] = k;
                            j++;
                            }
                        i++;
                        break;
                        }
                        
                s2[j] = s1[i];
                i++;
                j++;
                break;
            default:
                s2[j] = s1[i];
                i++;
                j++;
                break;
        }
    }
    s2[j] = '\0';
}