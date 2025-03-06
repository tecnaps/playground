/*

Variables:      basic data objects
Constants:      basic data objects
Declarations:   list variables, data types, initial values
Operators:      specify operations on variables and constants
Expressions:    combines variables and constants to new values     

ANSI changes:   signed and unsigned for ALL integer types
                notations for:  unsigned constants
                                unsigned hex character constants
                float operations may be done in single precisionon
                long double for extended precision
                String constants mayh be concatenated at compile time
                Enumerations part of the language
                objects may be declared const
                rules for automatic coercions of types augmented
*/

////////////////////////////////////////////////////////////////////////////////

/* Variable names

variable names should be related to the purpose of the variable

Variables:  1st character lowercase letter ('_' counts as letter)
            bad practice: using '_' as 1st character

constants:  all uppercase letters

internal name:  first 31 characters of a name are significant

external variables & function names:    
                maybe less than 31 characters are significant (b/c of specific 
                assemblers / loaders)

external variables: uniqueness for first 6 characters and single case guaranteed

keywords:   reserved words (e.g. if, else, return), must be lower case
*/

////////////////////////////////////////////////////////////////////////////////

/*Data types and sizes

basic data types

char        single byte, character in local character set
int         natural size of int on host machine
float       single precision 
double      double precision

qualifiers: (based on natural size of int, double, float on host machine)

short       int(at least 16bit)
long        int(at least 32bit), double (extended precision)
signed      char (-128-127), int
unsigned    char, int 


unsigned numbers are always positive
printable characters are always positive

<limits.h>, <float.h> contain symbolic constants for all above mentioned sizes
*/

////////////////////////////////////////////////////////////////////////////////

/*constants

evaluated during compilation

long contants are marked with the suffix 'L' or 'l'
unsigned constants are marked with the suffix 'U' or 'u' e.g. 'ul' or 'UL'
floating point constants (double) contain   a decimal point
                                            en exponent e.g. 1e-2
                                            suffix 'l' or 'L' for long double

octal integers are prefixed with '0', e.g. 31 is 037 in octal
hexadecimal integers are prefixed with '0x', e.g. 31 is 0x1f or 0x1F in hex
note: octal and hexadecimals may be followed by 'l' or 'L' for long
                                                'u' or 'U' for unsigned

character constants are integers written as character, e.g. 'x' 

note:   value of a character constant is the value of the character in the host 
        machines character set, e.g. ASCII)

bit patters:

'\ooo' is 1 to 3 octal digits 0...7
note:   777 is 9 bits and the compiler might complain if char is to small

'\xhh' and hh is 1 or more hexadeciumal digits 0...9 a...f

e.g.    #define VTAB '\013' or #define VTAB '\xb'
        #define BELL '\007' or #define BELL '\x7'


escape sequences:

\a      alert character (bell)
\b      backspace
\f      formfeed
\n      newline
\r      carriage return
\t      horizontal tab
\v      vertical tab
\\      backslash
\?      question mark
\'      single quote
\"      double quote
\ooo    ocatal number
\xhh    hexadecimal number


string constants:

string constants can be concatenated at compile time:

    e.g. "hello, ", "world" is evaluated at compile time to "hello world"

note:   'x' and "x" are different constants:
            'x' is a character constant, i.e. an integer
            "x" is a string constant, i.e. an array of characters

*/

#include <string.h>

int strlen(char s[]) {

    /*returns the length of a string s*/

    int i;
    while(s[i] != '\0')
        ++i;
    return i;
}

/*
enumeration constant:   enumeration is a list of constant integer values

enum boolean { NO, YES};

note:   first name has value 0, second name has value 1, etc.
        alternatively, values can be assigned explicitly, e.g.

enum escapes {  BELL = '\a', BACKSPACE = '\b', TAB = '\t', 
                NEWLINE = '\n', VTAB = '\v', RETURN = '\r'};

enum months {   JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

note:   names in different enumerations must be distinct

note:   enums are an alternative to #define 
        advantage:  enums need not be checked by a compiler, but offer the  
                    possibility to check the value 
*/

////////////////////////////////////////////////////////////////////////////////

/*Declarations

in general: variables must be declared
note:   certain declarations can be made implicity by content

initialization: static variables initialized once 
                external / static variables are initialized to zero by default
                automatic variables initialized each time a function is called
                automatic variables without explicit initializer have 
                        undefined values

initializer:    for static variables must be a constant expression
                for automatic variables can be any expression
                
const:  can be used with variables or arrays
        e.g. const char[] = "hello world";
*/

////////////////////////////////////////////////////////////////////////////////

/*Arithmetic operators

'%' cannot be used with float or double
overflow:       action is machine dependent
underflow:      action is machine dependent
direction of truncaton for '/' is machine dependent
sign of the result for '%' is machine dependent

precedence:      unary: +, -    >>      *, /, %         >>       binary: +, -
*/

////////////////////////////////////////////////////////////////////////////////

/*relational and logical operators

precedence:     arith. operators   >>       >, >=, <, <=        >>      ++, !=

logical operators:      relat.    >>      !       >>      &&      >>       || 

note:   != has higher precendence than = (assignment)

unary negation !:       converts non-zero operand to 0
                        converts zero operand to 1

*/

////////////////////////////////////////////////////////////////////////////////

/*type conversions

when operators have operands of different types, they are converted to a common
        type

automatic conversion:   only conversions that convert a narrower type to a wider

                        bool to char
                        char to short
                        short to int
                        int to unsigned int
                        unsigned int to long
                        long to unsigned
                        unsigned to long long
                        long long to float (round-off errors)
                        float to double
                        double to long double

note:   expressions that don't make sense (float as subscript) are not allowed
note:   expressions that might lose information (assigning longer integer to 
        shorter integer) are allowed, but draw a warning
*/

int atoi(char s[]){

        /*converts a string s of numbers to an integer*/

        int i, n;
        n=0;
        for(i=0; s[i]>='0' && s[i]<='9'; ++i)
                n=10*n+(s[i]-'0');
        return n;
} 

int lower(int c){

        /*converts char c to lower case*/

        if(c>= 'A' && c <='Z')
                return c + 'a' - 'A';
        else
                return c;

}

/*
lower works for ASCII but not necessarily for all character sets
<ctype.h> defines functions providing tests and conversions independent of a 
        specific character set e.g. tolower

note: c>='0' && c<='9' can be replaced by isdigit(c) from <ctype.c>

note:   C does not specify whether char is signed or unsigned, hence the 
        conversion of a char to an int can result in a negative integer 
        
        This depends on the architecture of the host machine, i.e. 
        1) a char with leftmost bit 1 is converted to a negative integer
        2) a char is promoted to an int by adding 0s to the left int

        protability:    specify signed or unsigned if non-character data is 
                        stored in char
*/

assignment(char c, char d){

d = c >= '0' && c <= '9'; //assigns 1 if c is a digit and 0 otherwise

}

/*
note:   float is not automatically converted to double in ANSI C
        float is used to save   storage in large arrays
                                save time in double precision calculations
note:   functions in <math.h> use double precision

note:   conversion rules are more complicated when signed / unsigned operands 
        are used
        problem: comparisons between signed and unsigned values are 
                 machine-dependent (b/c sizes of int types), 
        
        e.g. int 16 bits and long 32 bits: 
                
                -1L < 1U        b/c 1U is promoted to signed long
                -1L > 1UL       b/c -1L promoted to unsigned long

note: assignments:      RHS is converted to LHS type

conversion of char to int either by sign extension or zero extension
longer integers are converted to shorter integers / chars by dropping high order bits

*/

conversion(int i, char c){

i = c;
c = i;
}

/*
value of c remains unchanged (even if sign extensioln is used)
note:   if the order is reversed, information might be lost
*/

conversion(float x, int i){

x=i;    //conversion from int to float
i=x;    //conversion from float to int: loses fractional part
}


conversion(double y, float x){

x = y; // conversion from double to float         
}
/*
note:   whether conversion from double to float leads to round-off or truncation
        is implementatioln dependent

note:   arguments of a function call are expressions, hence type conversion also 
        take place in function calls

        without function prototype:     char and short are converted to int
                                        float is converted to double

note:   explicit type conversions can be forced by 'cast'
        (type) expression, e.g. (int) 3.24

example: sqrt() from <math.h> expects a double argument to work:

        int n = 4;
        sqrt((double) n)

precedence:     cast hast the same precedcence as unary operators

note: declaration of a function prototype causes automatic coercion of arguments

        double sqrt(double);
        root = sqrt(2);         //conversion of 2 to double 2.0
*/

unsigned long int next =1;
int rand(void){

        /*return pseudo-random integer*/
        next = next * 1103515245 + 12345;
        return (unsigned int) (next/65536) % 32768;
}

void srand(unsigned int seed){

        /*set seed for rand()*/
        next = seed;
}

////////////////////////////////////////////////////////////////////////////////

/*Increment / decrement operators

prefix:         increments n before the value is used
postfix:        increments n after the value is used
*/

increment(int x, int n){

        x = n++;        // x is n
        x = ++n;        // x is n+1
}

/*
note:   increment / decrement operators cannot be used with expressions
        e.g. (i+j)++ is illegal
*/


void squeeze(char s[], int c){

        /*delete all c von s*/

        int i,j;

        for(i=j=0; s[i] != '\0'; i++)
                if(s[i] != c)
                        s[j++] = s[i];
        s[j] = '\0';       
}

void strcat(char s[], char t[]){

        /* concatenate t to the end of s
           assumption: s is big enough */
        int i,j;

        i=j=0;
        while(s[i] !='\0')              // find the end of s
                i++;
        while((s[i++] = t[j++])!='\0')  // copy t
                ;
}

////////////////////////////////////////////////////////////////////////////////

/*Bitwise operators

operators for bit manipulation may only be applied to integral operands, i.e.
        char, short, int, long (signed or unsigned)
        &       bitweise AND
        |       bitwise OR
        ^       bitweise XOR
        <<      left shift
        >>      right shift
        ~       one's complement (unary)

bitmask:        e.g. n = n & 0177 (octal) sets all but the last 7 bits to 0
                e.g. x = x | SET_ON sets the bits to 1 that are 1 in SET_ON
                e.g. y = y ^ SET_ON sets only the bits to 1 where y and SET_ON differ

note: && and  & and || and | are different, e.g. for x = 1 and y = 2
                x & y = 0 but x && y = 1

shift:  x << 2 shifts the value of x by 2 positions left filling with 0s (= x*4) 
        right shift with signed quantities
        x >> 2 shifts the value of x by 2 positions right filling with sign bits (arithmetic shift) 
        right shift with unsigned quantities
        x >> 2 shifts the value of x by 2 positions right filling with 0s (logical shift)

complement:     yields the complement of an integer:
                x = x & ~077 = x & ~0111111 = x & 1000000

note:   x & ~077 is independent of word length
        x & ~0177700 assumes that x is 16 bits longs
*/

unsigned getbits(unsigned x, int p, int n){

        /*get n bits from startposition p
        assumption:     0 at the right end and 
                        n and p are sensible positive numbers
        */

        return (x >> (p+1-n)) & ~(~0 << n);
}

/*
x >> (p+1-n) moves the desired field to the right end of the word
0 << n shifts 0 left n positions filling with 0s
~0 << n complements 0 << n yielding a mask with n 1s in the rightmost bits
*/

////////////////////////////////////////////////////////////////////////////////

/*Assignment operators and expression

Operators with corresponding assignment operators:
        +, -, *, /, %, <<, >>, &, ^, |

expr1 op= expr2 is equivalent expr1 = (exp1) op (expr2), e.g.
        x *= y+1 is equivalent to x = x * (y+1)
*/

int bitcount(unsigned x){

        /*counts the number of bits set to 1 in x*/

        int b;

        for(b=0; x != 0; x >>= 1)
                if(x & 01)
                        b++;
        return b;
}

////////////////////////////////////////////////////////////////////////////////

/*Conditional expressions

ternary operator:       (condition) ? (expr1):(expr2)

note:   (cond)?(expr1):(expr2) is an expression an can be used whenever an 
        expression is allowed
        if expr1 and expr2 are of different types type conversion takes place
        precedence of ?: is low, just above assignment
*/

note(int n, char a[]){

        /*prints n elements of an array a separated by blanks and '\n' after nth element*/

        for (int i = 0; i < n; ++i)
                printf("%6d%c", a[i], (i%10==9 || i==n-1) ? '\n' : ' ');
}


////////////////////////////////////////////////////////////////////////////////

/*precedence and order of evaluation

operators in the same line have the same precendence
operators are listed in decreasing precedence

note:   () refers to function call

                () [] -> .                              left to right
                ! ~ ++ -- + - * (type) sizeof           right to left
                * / %                                   left to right
                + -                                     left to right
                << >>                                   left to right
                < <= > >=                               left to right
                == !=                                   left to right
                &                                       left to right
                ^                                       left to right
                |                                       left to right
                &&                                      left to right
                ||                                      left to right
                ?:                                      left to right
                = += -= *= /+ %= &= ^= != <<= >>=       right to left
                ,                                       left to right

note: unary & + - * have  higher precendence than binary & + - *

note:   c usually does not specify the order in which operands of an operator 
        are evaluated, exception:       && || _: and ,

        example:        x = f() + g()
                        g() may be evaluated before f(), 
                        BEWARE  if f or g alters variables used in g or f respectively
                                (store intermediate values in temporary variables)

        similarily the order in which function arguments are evaluated is not
        specified

        example:        printf("%d %d\n", ++n, power(2,n));
                        produces different results with different compilers 

side effects:   e.g. a[i] = i++; 
                compilers can interprete this statement in different ways
                reason: best order depends on machine architecture
                
note:   c standard only specifies all side effects take effect before a function 
        is callend

note:   code that depends on order of evaluation is bad practice!!!
*/
