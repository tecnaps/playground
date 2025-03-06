#include <stdio.h>

/*copy input to output trimming blanks*/

int main(){

    int c, blank;

    blank = 0;
    while((c = getchar()) != EOF)
    {
        if(c != ' '){
            if (blank > 0)      //trims blanks if next character is not a blank
            {
                putchar(' ');
                blank = 0;
            }
            putchar(c);
        }
        else                    //counts # of blanks
            ++blank;
    }
}