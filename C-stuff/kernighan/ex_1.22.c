#include <stdio.h>

/* "entab" replaces strings of whitespaces with tabstops and blanks*/

#define MAXLEN 1000
#define n 8

int main(){
  int c, delta, i, line;
  char output[MAXLEN];
 
  delta=0;
  i = 0;
  line=0;
  
  while((c=getchar())!=EOF){
    if(c=='\t'){
      delta = n - (line % n);
      while(delta > 0){
	output[i]=' ';
	++i;
	++line;
	--delta;
      }
    }
    else if (c!='\n') {
      output[i]=c;
      ++i;
      ++line;
    }
    else{
      output[i]=c;
      line=0;
      ++i;
    }
  }
  output[i]='\0';
  printf("%s", output);
  return 0;
}
