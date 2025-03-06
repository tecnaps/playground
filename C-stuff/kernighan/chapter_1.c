/* hello world

stdio.h header for standard input/output

text formatting:    \n newline
                    \t tab
                    \b backspace
                    \" escape double quote
                    \\ backslash
*/

#include <stdio.h>

main(){

    printf("hello, world\n");
}

//#############################################################################


/* Variables and Arithmetic Expressions

int and float depend on the machine (16 or 8 bit) 
int ranges from -32768 to 32767
integer division truncates
printf:     %d  substituted for integer
            %f  substituted for float
            %o  substituted for octal
            %x  substituted for hexadecimal
            %c  substituted for character
            %s  substituted for string
            %%  substituted for %


note:   there is no input / output defined in C itself
        thats why printf is part of stdio.h (standard library for input/output)

padding:    printf("%3d %6d\n", fahr, celsius);

            integer fields: %3d     3 at least characters wide
                            %6d     6 at least characters wide

            float fields:   %3,0f   at least 3 characters wide, no fraction digits 
                            %6.1f   at least 6 characters wide, 1 fraction digit
                            %.2f    at least 0 characters wide, 2 fraction digits

data types:     char    single byte
                short   short int
                long    long int
                double  double-precision float


float: a decimal point in a constant indicates float

note: if an arithmetic operation contains an integer an integer operation is performed



*/

#include <stdio.h>  //integer

/*prints a Fahrenheit-Celsius table using integer*/

main() {

    int fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while(fahr <= upper) {
        celsius = 5 * (fahr-32) / 9;
        printf("%3d\t %6d\n", fahr, celsius);
        fahr = fahr + step;
    }
}

#include <stdio.h> //float

/*prints a Fahrenheit-Celsius table using float*/

main(){
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while(fahr <= upper){
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f \t %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

//#############################################################################

/* for statement:

for loop statement is a generalization of the while statement

practice:   for is used if intitialization and increment are single statements 
            and logically related

note:   initialization, condition and increment of a for loop can be more 
        complicated expressions

note:   below the 2nd argument of the printf inside the for loop is a 
        calculation

        a value can always be substituted for a more complicated expression of 
        the same type (i.e. calculation)


*/

#include <stdio.h>

main() {

/*temperature conversion with for loop*/

float upper, lower, step;
float fahr, celsius;

lower = 0;
upper = 300;
step = 20;

printf("\ntemperature conversion table:\n\n");

for(fahr = lower; fahr <= upper; fahr = fahr+ step){
    printf("%3.0f \t %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
    }
}

//#############################################################################

/*symbolic constants

bad practice:   using magic numbers

solution:       give magic numbers meaningful names with #define

                #define [name] [replacement]
                every occurence of [name] will be replaced by [replacement]

symbolic constants are  usually all uppercase and
                        do not contain ;
*/

#include <stdio.h>

/*symbolic constants*/
#define LOWER   0
#define UPPER   300
#define STEP    20

int main(){

    float fahr;
    printf("\ntemeprature conversion table:\n\n");

    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP){
        printf("%3.0f \t %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
    }
}

//#############################################################################

/* character input / output

input / output are text streams
text stream:    sequence of characters divided into lines
                each line consists of 0 to n characters
                each line ends with \n

functions for reading / writing characters:

                reading:    getchar()  (reads a single characater)

                            c = getchar;
                
                writing:    putchar()  (writes a single character)

                            putchar(c)

*/

//#############################################################################

/*file copying

characters are stored as bit patterns
types for storing characters:   char (specific type)
                                any integer type (int, long, short)

EOF:    end of file character
        defined in stdio.h (numeric value must not be any character)

note:   the variable to hold the return value of getchar() must be big enough
        to hold EOF and char is not big enough, hence int is used



*/


#include <stdio.h>  //version #1

/*copy input to output*/

int main() {

    int c;

    c = getchar();
    while (c != EOF) {

        putchar(c);
        c = getchar();    
        }

}

#include <stdio.h>  //version #2

main (){

    int c;
    while((c = getchar()) != EOF){  //precedence of != is higher than =
        putchar(c);
    }
}

//#############################################################################

/*character counting

increment:  ++ often more efficient than +1
decrement:  -- analoguous

prefix:     ++nc / --nc
postfix:    nc++ / nc--

output formatting:  %ld     long integer (32 bit)
                    %.0f    suppresses the decimal point and fraction part

null statement:     ; (see below version #2)

boundary case:  for / while always test at least once before running the body
                therefore output is 0 if there is no input
*/

#include <stdio.h>  //version #1

/*count characters in input*/

int main() {

    long nc;

    nc = 0;
    while(getchar() != EOF){
        ++nc;
    }
    printf("%ld\n", nc);
}

#include <stdio.h>  //version #2

/*count characters in input*/

int main(){

    double nc;

    for(nc = 0; getchar() != EOF; ++nc)
        ;                                   //for loop needs a statement (here: ; )
    printf("%.0f\n", nc);
}

//#############################################################################

/*line counting

character constant: character in single quotes 'c' represents the integer equal 
                    to the numerical value of the character in the machine's 
                    character set (applies to escape sequences as well, i.e. \n
                    is a single character; '\n' is a 1 character string constant)



*/

#include <stdio.h>

/*count lines of input*/

int main() {

    int c, nl;

    nl=0;
    while ((c = getchar())!= EOF)
        if (c == '\n')
            ++nl;
    printf("%d\n", nl);
}

//#############################################################################

/* word counting

assignments work from right to left, therefore a = b = c = 0 is legal

*/

#include <stdio.h>

#define IN  1
#define OUT 0

/*count lines, words and characters in input*/

int main() {

    int c, nl, nw, nc, state;

    state = OUT;                                    //state logs if a word is being read
    nl = nw = nc =0;
    while ((c=getchar())!=EOF){

        ++nc;
        if(c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT){
            state = IN;
            ++nw;
        }
    }

    printf("%d \t %d \t %d\n", nl, nw, nc);
}

//#############################################################################

/*Arrays

EOF in windows is ctrl+Z not ctrl+C
subscripts start at 0
note:   numbers might not be consecutive in all character sets 


ASCII table

Dec  Char                           Dec  Char     Dec  Char     Dec  Char
---------                           ---------     ---------     ----------
  0  NUL (null)                      32  SPACE     64  @         96  `
  1  SOH (start of heading)          33  !         65  A         97  a
  2  STX (start of text)             34  "         66  B         98  b
  3  ETX (end of text)               35  #         67  C         99  c
  4  EOT (end of transmission)       36  $         68  D        100  d
  5  ENQ (enquiry)                   37  %         69  E        101  e
  6  ACK (acknowledge)               38  &         70  F        102  f
  7  BEL (bell)                      39  '         71  G        103  g
  8  BS  (backspace)                 40  (         72  H        104  h
  9  TAB (horizontal tab)            41  )         73  I        105  i
 10  LF  (NL line feed, new line)    42  *         74  J        106  j
 11  VT  (vertical tab)              43  +         75  K        107  k
 12  FF  (NP form feed, new page)    44  ,         76  L        108  l
 13  CR  (carriage return)           45  -         77  M        109  m
 14  SO  (shift out)                 46  .         78  N        110  n
 15  SI  (shift in)                  47  /         79  O        111  o
 16  DLE (data link escape)          48  0         80  P        112  p
 17  DC1 (device control 1)          49  1         81  Q        113  q
 18  DC2 (device control 2)          50  2         82  R        114  r
 19  DC3 (device control 3)          51  3         83  S        115  s
 20  DC4 (device control 4)          52  4         84  T        116  t
 21  NAK (negative acknowledge)      53  5         85  U        117  u
 22  SYN (synchronous idle)          54  6         86  V        118  v
 23  ETB (end of trans. block)       55  7         87  W        119  w
 24  CAN (cancel)                    56  8         88  X        120  x
 25  EM  (end of medium)             57  9         89  Y        121  y
 26  SUB (substitute)                58  :         90  Z        122  z
 27  ESC (escape)                    59  ;         91  [        123  {
 28  FS  (file separator)            60  <         92  \        124  |
 29  GS  (group separator)           61  =         93  ]        125  }
 30  RS  (record separator)          62  >         94  ^        126  ~
 31  US  (unit separator)            63  ?         95  _        127  DEL

*/


#include <stdio.h>

/*count digits, white space, others*/

int main() {

    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;
    
    for (i=0; i < 10; i++)
        ndigit[i]=0;
    
    while ((c=getchar())!=EOF){
        if (c>= '0' && c<= '9')
            ++ndigit[c-'0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;
    }

    printf("digits =");
    
    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);
    
    printf(", white space = %d, other = %d\n", nwhite, nother);

}

//#############################################################################

/*Functions

standard library contains function pow(x,y) raising x to power y

parameter / formal argument:    arguments named in the declaration of a function 
actual argument:                argument passed in the function call 

return value:   0           = normal termination
                non-zero    = abnormal termination

prototype:  must agree with the implementation of the function
note:       parameter name are optional in the prototype and need not agree with 
            the implementation. However, types must agree

*/

#include <stdio.h>

int power(int m, int n);        //prototype

/*power function*/

int main(){

    int i;

    for (i = 0; i < 10; ++i)
        printf("%d \t%d\t %d\n", i, power(2,i), power(-3,i));
    return 0;
}

/*power(base,n): raises base to the nth power for n >= 0*/

int power(int base, int n){

    int i, p;

    p = 1;
    for (i=0; i<=n; ++i)
        p = p * base;
    return p;
}

//#############################################################################

/* Call by value

all function arguments in C are PASSED BY VALUE
advantage:  more compact code (reduces need for extraneous variables)

note:   to change variable in calling routine, its adress (i.e. a pointer) must 
        be passed

note:   if the name of an array is passed, actually THE ADRESS OF (i.e. a pointer to) 
        THE FIRST ELEMENT within the array is passed
*/

#include <stdio.h>

/*power(x,y) using vall by value*/

int power (int base, int n){

    int p;

    for (p = 1; n > 0; --n)     // n is used as temporary variable and decremented, 
                                // therefore, there's no need for i
        p = p*base;
    return p;
}

//#############################################################################

/*character arrays

functions communicate by passing / returning arguments

supplying the size of an array in a declaration (not initialization) is to 
    set aside storage

null character: '\0' (value: 0) marks the end of a character string, i.e.
        "hello\n" is stored as  | h | e | l | l | o | \n | \0 |
                                | 0 | 1 | 2 | 3 | 4 |  5 |  6 |
        in an array of size 7

*/

/*programm design:

        while (exists another line)
            if (newline longer longest line)
                save it
                save length
            print longest line

subroutines:

    getline:    return signal if EOF reached and length of line

        note: function can return only 1 value, therefore:
                return 0       if EOF (0 is never a valid line length, '\n' has length 1)
                return length   any other case

    copy:       copy  new line
    main:       main routine

design problems:    1) input is at least as long as MAXLINE

*/

#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char to[], char from[]);

int main(){

    /*print longest line from input*/

    int len, max;
    char line[MAXLINE], longest[MAXLINE];

    max=0;
    while((len = getline(line, MAXLINE)) > 0)
        if (len > max){
            max = len;
            copy(longest, line);
        }
    
    if (max > 0)
        printf("%s", longest);
    return 0;
}

int getline(char s[], int lim){

    /*reads line into s and returns its length*/
    /*note: conflict with getline() in stdio.h*/

    int c,i;

    for (i=0; i < lim-1 && (c=getchar())!= EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]){

    /*copy 'from' into 'to', assumption: 'to' is big enough to hold 'from'*/

    int i;

    i=0;
    while((to[i] = from[i]) != '\0')
        ++i;
}

//#############################################################################

/* External variables and scope

automatic variables:    exist only while a function is executed
                        must be explicitly set upon each entry


external variables: accessible from all functions by name
                    used to communicate data between functions
                    obfuscate data connections 
                    DEFINED once outside any function, but 
                    DECLARED in each function with 'extern'

note:   'extern' can be omitted if the declaration occurs before its use in a function

common practice:    place external variables at the beginning of a source file 
                    and omit 'extern'

note:   external variables defined in different source files than theu are used 
        need 'extern'

note:   c standard takes empty argument list as old-style declaration 
        (no argument list checking), therefore 'void' must be used for an 
        explicitly empty argument list

*/

#include <stdio.h>

#define MAXLINE 1000

int max;
char line[MAXLINE], longest[MAXLINE];

int get_line(void);
void copy(void);

int main(){

    int len;
    extern int max;
    extern char longest[];

    max = 0;
    while ((len = get_line()) >0 )
        if (len > max) {
            max = len;
            copy();                 //conflict with copy() in stdio.h
        }
    if (max > 0)
        printf("%s", longest);
    return 0;
}

int get_line(){

    int c, i;
    extern char line[];

    for(i=0; i < MAXLINE-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n'){
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void copy(){

    int i;
    extern char line[], longst[];
    while ((longest[i]=line[i])!= '\0')
        ++i;
}