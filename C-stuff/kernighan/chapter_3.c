/*
Control Flow

3.1 Staments and Blocks

expression: x = 0, i++, printf(...)
statement:  x=0; i++; printf(...);
note:   staments become expressions when ; is added

stamement terminator:   ;

note:   {} are used to group declarations and staments into block / compound statements
        variables can be declared inside any blocks

note:   no ; after the closing } of a block

3.2 if-else

coding shortcus:    since if tests the numeric value of an expression
                    if (x) exquivalent to if(x!=0)


3.3 else if                  
*/

int binsearch (int x, int v[], int n){

    /*find x in v[0] <= v[1] <= ... <= v[n-1]*/

    int low, high, mid;
    low =0;
    high = n-1;
    while (low <=high){
        mid = (low+high)/2;
        if (x < v[mid])         // value of x lower than mid
            high = mid - 1;
        else if (x > v[mid])    // value of x greater than mid
            low = mid+1;
        else                    // found match om v
            return mid;
    }
    return -1;                  // no match in v
}


/*
3.4 Switch

tests whether an expresseion matches one of a number of constant integer values

        switch(expression){
            case const-expr1: statements
            case const-expr2: staements
            default: statements
        }

note:   all case expressions must be different
        default is optional, only executed if no case matches
*/

#include <stdio.h>
main(){

    int c, i, nwhite, nother, ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i<10; ++i)
        ndigit[i] = 0;
    while ((c=getchar()) != EOF){
        switch(c){

            // 0-9 are all digits: falling through
            case '0': case '1': case '2': case '3': case '4':   
            case '5': case '6': case '7': case '8': case '9':
                ndigit[c-'0']++;
                break;
            // ' ', '\n' and '\t' are all whitespaces: falling thorugh
            case ' ':               
            case '\n':
            case '\t':
                nwhite++;
                break;
        default:
            nother++;
            break;          // unncessary, but good form (defensive programming)
        }
    }
    printf("digits =");
    for (i = 0; i<10; ++i)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n", nwhite, nother);
    return 0;
}

/*
note:   cases serve merely as labels, so code falls through after a case until 
        break / return is reached

note:   falling through cases is not robust and should be used sparingly

3.5 Loops - while and for

for loop:   for(expr1; expr2; expr3)

            grammatically components are expressions, usually 

                expr1 assignments / function calls 
                expr2 relational expression
                expr3 assignments / function calls

note: any expression 1-3 can be omitted, but the ';' must remain
        if expr1 and expr3 are omitted they are dropped
        if expr2 is omitted it is assumed to be true
*/

void example(){

        for(;;){
            // infinite loop broken by break / return
        }
}

/* 
note:   for-loop preferrable for simple initialization and increment
        loop variable retains value after termination of the loop
        
bad style:  putting unrelated computations in the intialization / increment of a 
            for loop 
*/

#include <ctype.h>

int atoi(char s[]){

    /* convert s to integer*/

    int i, n, sign;
    for (i=0; isspace(s[i]); i++)       // skip white spaces
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')     // skip sign
        i++;
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n +(s[i] - '0');
    return sign * n;
}

/*
standard library:   strtol converts strings to long integers
*/

void shellsort(int v[], int n){

    /*sort v[0]...v[n-1] in increasing order*/

    int gap, i, j, temp;

    for (gap = n/2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j=i-gap; j>=0 && v[j] > v[j+gap]; j-=gap){
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
}

/*
outermost loop: controls gap between compared elements (halfed each iteratioln)
middel loop:    steps along the elements
innermost loop: compares each pair of elements separated by gap (elements out of 
                order are reversed)

note: when gap is reduced to 1, the algorithm is a simple exchange sort

comma operator: most often in for statements,
                expressions are evaluated left to right
                type and value of the result is the type and value of the 
                right operand
*/

#include <string.h>

void reverse(char s[]){

    /*reverses a string in place*/

    int c,i,j;

    for (i=0, j=strlen(s)-1; i < j; i++, j--){
        c=s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/*
note:   commas between function arguments, variables in declarations etc are not
        comma operators

note:   comma operators used sparingly for strongly related constructs e.g. when 
        a multistep computation must be a single expression 
*/

void example(char s[]){

    int i, j, c;
    for (i=0, j = strlen(s)-1; i<j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}

/*
Do while

advantage:   body is executed at least once
*/

void itoa(int n, char s[]){

    /*convert n to characters in s*/

    int i, sign;

    if ((sign = n) < 0)                 // record sign
        n = -n;                         // reverse sign for negative n
        i=0;
        do{                             // generate digits in reverse order
            s[i++] = n % 10 + '0';      // get next digit
        } while ((n /= 10) > 0);        // delete digit
        if (sign < 0)
            s[i++] = '-';
        s[i] = '\0';
        reverse(s);
}

/*
note: do while is necessary since at least one digit must be installed in s
*/