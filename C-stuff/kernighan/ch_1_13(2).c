#include <stdio.h>

/*variant of the longest line program with external variables*/

#define MAXLINE 1000

//external variables

int max;
char line[MAXLINE];
char longest[MAXLINE];
/*
  line, max and longest are external variables so there is no need
  to pass them to cgetline() and copy() as arguments
  instead void is passed as argument
*/
int cgetline(void);
void copy(void);

int main(){
  int len;

  /*max and longest were already defined at the beginning of
    this src file. At this point they are only made know to
    main by declaration*/

  //extern int max;
  //extern char longest[];

  max=0;

  while((len = cgetline())>0)
    if (len>max) {
      max=len;
      copy();
    }
  if(max > 0)
    printf("%s", longest);
  return 0;
}

int cgetline(void){
  int c, i;
  //extern char line[];

  for(i=0; i < MAXLINE - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
    line[i]=c;
  if(c=='\n'){
    line[i]=c;
    ++i;
  }
  line[i]='\0';
  return i;
}

void copy(void){
  int i;
  //extern char line[], longest[];

  i=0;
  while((longest[i]=line[i])!='\0')
    ++i;
}
