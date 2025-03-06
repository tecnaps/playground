#include <stdio.h>

/*converts celsius to fahrenheit*/

int main() {

    float fahr, celsius;
    float upper, lower, step;

    lower = 0;
    upper = 300;
    step= 20;

    celsius = lower;
    printf("\ntemperature conversion table: \n\n");

    while(celsius <= upper){

        fahr = (celsius * 9.0 / 5.0) + 32.0;
        printf("%3.0f \t %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }

}