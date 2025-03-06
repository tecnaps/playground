#include <stdio.h>

/*simple program to read and write single characters
 EOF is a constant defined in stdio.h*/

/* first version

int main()
{

  int c; // char is to small to hold EOF 
  c = getchar();
  while(c!= EOF)
    {
      putchar(c);
      c=getchar();
    }
  return 0;
  }*/

/*second version*/

int main()
{

  int c;
  while((c=getchar())!= EOF)
      putchar(c);

  return 0;

}
