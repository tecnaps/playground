#include <stdio.h>

/*counts lines put in until EOF*/

int main()
{
  int c, nl;
  nl = 0;
  while((c=getchar())!= EOF)
    if (c=='\n')
      ++nl;
  printf("\nnumber of lines put in: %d", nl);
  return 0;
}

/*characters in '' represent a character constant, i.e.
  an integer equal to the numerical value in the
  machine's character set*/
