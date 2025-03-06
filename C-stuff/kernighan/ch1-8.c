#include <stdio.h>

/*count blanks, tabs and newlines*/


int main (){

    int c, tabs, blanks, newlines;

    c = 0;
    tabs = 0;
    blanks = 0;
    newlines = 0;

    while ((c=getchar()) != EOF){

        if (c == '\t')
            ++tabs;
        else if (c == ' ')
            ++ blanks;
        else if (c == '\n')
            ++newlines;
    }
    printf("\nTabs: %d\nBlanks: %d\nNewlines: %d\n", tabs, blanks, newlines);
}