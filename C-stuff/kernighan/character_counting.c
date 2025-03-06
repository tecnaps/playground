#include <stdio.h>

/*counts characters put in until EOF*/

/*1st version: while

int main()
{
  long nc;
  nc = 0;
  while (getchar() != EOF)
    ++nc;
  printf("\n# of characters put in: %ld\n", nc);
  return 0;
}
*/

/*2nd version: for*/

int main()
{
  double nc;
  for(nc = 0; getchar()!= EOF; ++nc)
    ; // body is necessary in for loops 
  printf("\n# of characters put in: %3.0f", nc);
  return 0;
}
