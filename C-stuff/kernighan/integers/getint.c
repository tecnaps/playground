#include <ctype.h>
#include <stdio.h>

int getch(void);
int ungetch(int);

//! getint: converts numerical characters into integers

int getint(int *ptrN){
    int c, sign;

    //! trims leading spaces
    while(isspace(c=getch()))
        ;

    //! if the 1st character is not a digit, nor EOF, nor '+' nor '-', i.e. not a valid character for a number 
    if(!isdigit(c) && c !=EOF && c!='+' && c!='-'){
        ungetch(c);         
        return 0;           //! returns 0 b/c input is not a number 
    }

    //! sign is set and if c is either '+' or '-' the next character is read
    sign = (c == '-') ? -1 : 1;
    if(c == '+' || c == '-')
        c = getch();
    
    //! converts all consecutive numerical characters into a number until first non numerical character is read
    for(*ptrN = 0; isdigit(c); c = getch())
        *ptrN = 10* *ptrN + (c - '0');          //! c - '0' removes the offset for numerical characters
    *ptrN *= sign;
    if(c != EOF)
        ungetch(c);
    return c;
}