#include <stdio.h>

/*fahrenheit - celsius conversion with for-loop
  from 300 - 0 degree with step: 5 in reverse order*/

int main ()
{
  float fahr, celsius;
  float upper, lower, step;
  upper = 300.0;
  lower = 0.0;
  step = 5.0;

  fahr = upper;
  
  for(int i  = 300; i > 0; i=i-5) //note: i = i-5
    {
      celsius = 5*(fahr - 32 / 9);
      printf("\n%4.1f | %4.1f", fahr, celsius);
      fahr = fahr - step;
    }

  /*for loop is apropriate if initialization and increment
    are single steps and logically related*/
}
