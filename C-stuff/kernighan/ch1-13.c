#include <stdio.h>

#define IN  1
#define OUT 0
#define BUF 30

/*prints a histogram of wordlengths*/

int main(){

int c, cnt, i, max, state, words[BUF];

for(i = 0; i < BUF; ++i)
    words[i] = 0;

state = OUT;
cnt = max = 0;

while ((c=getchar()) != EOF){

    if (state == IN && c != ' ' && c != '\n' && c != '\t')
        ++cnt;
    else if (state == OUT && c != ' ' && c != '\n' && c != '\t'){
        state = IN;
        ++cnt;
    }
    else if (state == IN && (c == ' ' || c == '\n' || c == '\t')){

        state = OUT;
        if (cnt< BUF)
            ++words[cnt];
        cnt = 0;
    }
}

for (i = 0; i < BUF; ++i)
    if(max < words[i])
        max = words[i];

while (0 < max){
    for (i = 0; i < BUF; ++i)
        if (words[i]==max){
            printf(" + ");
            --words[i];
        }
        else
            printf("   ");
    printf("\n");
    --max;
    }
    
for (i=0; i< BUF; ++i)
    if (i < 10)
        printf(" %d ", i);
    else
        printf(" %d", i);

}