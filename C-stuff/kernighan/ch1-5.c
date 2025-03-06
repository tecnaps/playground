#include <stdio.h>

/*converts fahrenheit to celsius in reverse order*/

int main(){

    float fahr, celsius;
    float upper, lower, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("\nreverse temperature conversion table:\n\n");

    for(fahr=upper; fahr >= lower; fahr = fahr-step){
        printf("%3.0f \t %6.1f\n", fahr, (5.0 / 9.0) * (fahr -32.0));
    }
}