#include <stdio.h>

/*converts celsius to fahrenheit: range 0 - 300, step 5*/

int main()
{
  float celsius, fahr;
  float upper, lower, step;
  upper = 300;
  lower = 0;
  step = 5;
  celsius = lower;

  while (celsius <= upper)
    {
      if (celsius == 0)
	printf("\nCelsius | Fahrenheit");
      fahr = celsius * 9 * 0.2 + 32;
      printf("\n%6.1f  |   %5.1f", celsius, fahr);
      celsius = celsius + step;
    }
  return 0;
}


/*from Kernighan:
  
  %d    prints decimal integer
  %6d   prints decimal integer, at least 6 characters wide
  %f    prints float
  %6f   prints float, at least 6 characters wide
  %.2f  prints fkloat, 2 characters after decimal point
  %6.2f prints float, at least 6 characters wide and 2 after decimal point
*/
