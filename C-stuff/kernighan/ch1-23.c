#include <stdio.h>

int main() {

    /* removes comments from c programs */

    char buffer = 0;
    int c, ignore, multi, single;
    ignore = multi = single = 0;

    while ((c=getchar())!=EOF){

        if (ignore != 1)                                // '/' read, possible comment
            if (c == '/'){
                ignore = 1;
                buffer = '/';
            } else                                      //no comment
                putchar(c);

        else
            if (single == 0 && multi == 0){ 
                if (buffer == '/' && c == '*'){         //multi line comment
                    multi = 1;
                    buffer = 0;
                    continue;
                } else if ( buffer == '/' && c == '/'){ //single line comment
                    single = 1;
                    buffer = 0;
                    continue;
                } else {                                //turns out: no comment
                    putchar(buffer);
                    putchar(c);
                    ignore = 0;
                }

            } else if (single == 1 && c == '\n'){       //single line comment reaches '\n' 
                putchar(c);
                single = 0;
                ignore = 0;
                buffer = 0;
                continue;
            } else if (multi == 1)
                if (c == '*'){                          //'*' read in multi line comment
                    buffer = c;
                    continue;
                } else if (buffer == '*' && c == '/'){  //'/' read after '*' in line comment reaches
                    multi = 0;
                    ignore = 0;
                    buffer = 0;
                } 
    }
}