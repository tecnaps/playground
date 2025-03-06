#include <stdio.h>

/*simple program to trim blanks*/

int main() {
  int c, lastchar;
  while((c=getchar())!= EOF){
    if (lastchar == ' ' && c == ' ')
      continue;
    else
      {
	printf("%c", lastchar);
	lastchar = c;
      }
  }
  printf("%c\n", lastchar);
  return 0;
}
