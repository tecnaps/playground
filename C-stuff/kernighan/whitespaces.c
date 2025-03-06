#include <stdio.h>

/*simple program to count blanks, tabs and newlines*/

int main(){
  int c, space, tab, newline;
  space = 0;
  tab = 0;
  newline = 0;
  while ((c=getchar())!= EOF){
    if (c == ' ')
      ++space;
    if (c == '\t')
      ++tab;
    if (c == '\n')
      ++newline;
  }
  printf("\nspace: $%d\ntabs: %d\nnewline: %d\n", space, tab, newline);
  return 0;
}
