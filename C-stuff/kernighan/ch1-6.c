#include <stdio.h>

/*prints the value of getchar()!=EOF and getchar==EOF*/

int main()
{
    int c;
    if ((c = getchar()) != EOF)
        printf("getchar != EOF: %d", (c != EOF));
    else
        printf("getchar == EOF: %d", (c != EOF));
}