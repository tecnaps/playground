#include <stdio.h>

/*counts words, lines and and characters*/

#define IN 1 /* inside a word*/
#define OUT 0 /*outside a word*/

int main()
{
  int c, nl, nw, nc, state;
  /* c = current read character
     nl = newline
     nc = caracter count
     nw = word count
   */
  state = OUT;
  nl = nw =nc = 0;
  while((c = getchar()) != EOF)
    {
      ++nc;
      if (c == '\n')
	      ++nl;
      if (c==' '|| c=='\n'||c=='\t')
	      state=OUT;
      else if(state==OUT)
	      {
	        state=IN;
	        ++nw;
	      }
    }
  printf("%d %d %d\n", nl, nw, nc);
  return 0;
}
