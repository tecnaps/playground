#include <stdio.h>

#define IN  1
#define OUT 0

/*prints one word per line*/

int main(){

int c, state;
state = OUT;

while((c = getchar())!=EOF){

    if (state == IN && c != ' ' && c != '\t' && c!= '\n')
        putchar(c);

    if (state == OUT && c != ' ' && c != '\t' && c != '\n'){
        state = IN;
        putchar(c);
        }

    if (state == IN && (c == ' ' || c == '\t' || c == '\n')){
        state = OUT;
        putchar('\n');
        }
    }
}