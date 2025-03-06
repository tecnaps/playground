#include <stdio.h>

/*simple program to count words*/

int main(){
  
  int c, wc, chksum;
  wc=0;
  chksum = 0;
  while((c=getchar())!=EOF){
    if(c==' ')
      ++wc;
    ++chksum;
  }
  if (chksum!=0)
    ++wc;
  printf("\n number of words: %d\n", wc);
  return 0;
}
