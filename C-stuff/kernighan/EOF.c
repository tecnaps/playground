#include <stdio.h>

/*programm to  print EOF and check if EOF is put in
 EOF in Windows: ctrl+Z, Linux: ctrl+D */

int main()
{
  int c;
  printf("input is EOF?: \n%d", (c=getchar())!=EOF); // TRUE = 0, FALSE = 1
  printf("\n%d", EOF);
  return 0;
}
