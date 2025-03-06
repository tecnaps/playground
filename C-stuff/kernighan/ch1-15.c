#include <stdio.h>

/*temperature conversion fahrenheit to celsius (using functions)*/

double fahrToCels(int i);

int main(){

    int i, lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    for (i = 0; i <= upper; i+=step)
        printf("%d\t%.2f\n", i, fahrToCels(i));
}

double fahrToCels(int fahr){

    return (5.0 / 9.0) * (fahr-32.0);
}