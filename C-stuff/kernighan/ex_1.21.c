#include <stdio.h>

/*detab: replaces tabstops with blanks for a fixed set of tab stops
  \t is 4 characters wide
 */

#define MAXLINE 1000
#define n 8

int detab(char output[], int pos, int delta);

int main(){

  int c, i, delta, line;
  i = 0;
  delta = line = 0;
  
  char output[MAXLINE];
  while((c=getchar())!= EOF && i < MAXLINE - 1){
    if(c=='\t') {
      delta = n - (line % n);
      while (delta>0){
	output[i]=' ';
	++i;
	++line;
	--delta;
      }
    }
    else if (c != '\n'){
      output[i]=c;
      ++i;
      ++line;
    }
    else {
      output[i]='\n';
      line=0;
      ++i;
    }
  }
  output[i]='\0';
  printf("%s", output);
  return 0;
}

