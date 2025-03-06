#include <stdio.h>

#define BUF 62

int main() {

    int c, i, words[BUF];

    for (i = 0; i< BUF; ++i)
        words[i] = 0;

    c = 0;

    while ((c=getchar()) != EOF){

        if (c >=48 && c <= 57)
            ++words[c-48];
        else if (c >= 65 &&  c <= 90)
            ++words[c-29];              //sort uppercase after lowercase letters
        else if (c >= 97 && c <= 122)
            ++words[c-87];
    }

for (i = 0; i < BUF; ++i)
    if (i < 10)
        printf("%c: %d\n", i+48, words[i]);
    else if (i > 9 && i < 36)
        printf("%c: %d\n", i+87, words[i]);
    else
        printf("%c: %d\n", i+29, words[i]);
}