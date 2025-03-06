#include <stdio.h>

int main(){


// chinesischer Restsatz

    int a, mod, result, rest = 0;
    a = 306;
    mod = 19;
    rest = 5; 
    for(int x=1; ; x++){
        if ((a*x+rest) % mod == 0)
        {
            printf("%d", x);
            return 0;
        }
    }
return 0;
}