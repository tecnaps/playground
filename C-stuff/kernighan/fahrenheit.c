#include <stdio.h>

/*converts fahrenheit to celsius, step 5, range 0 - 300*/

int main()
{
  int fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 5;

  fahr = lower;
  while (fahr <= upper)
    {
      celsius = 5 * (fahr - 32) / 9;
      if (fahr == 0)
	printf("\nFahrenheit | Celsius\n");
      printf("  %5d    |   %3d\n",  fahr, celsius);
      fahr = fahr + step;
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
