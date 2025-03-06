#include <stdio.h>

/*copy inpurt to output replace backspace   by \b
                                tab         by \t
                                backslash   by \\*/

int main() {

    int c;

    while ((c = getchar()) != EOF) {

        if (c == '\b'){
            putchar('\\');
            putchar('b');
        }
        else if (c == '\t'){
            putchar('\\');
            putchar('t');
        }
        else if (c == '\\'){
            putchar('\\');
            putchar('\\');
        }
        else
            putchar(c);
    }
}
