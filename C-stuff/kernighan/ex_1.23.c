#include <stdio.h>

/* basic program to fold lines
   
   TODO:
   -read in words (check)
   -check delimiters: \t, ' ', \n ; . (check except for \t)
   -get word length (check)
   -check length against line length (check)
   
   ********

   -put word onto different line if word length > line length
    and word is longer than current line
   -what to do with long lines? -> group similar letters
 */

#define MAXLEN 1000
#define n 10

int copy (char word[], char out[], int length,  int position);

int main (){
  int i, c, line, len;
  char word[n];
  char output[MAXLEN];

  i = line = 0;
  
  while ((c=getchar())!=EOF){
    output[i]= c;
    ++line;
    ++i;
    if(line == n) {      
      output[i]='\n';
      line = 0;
      ++i;
    }
  }
  output[i]='\0';
  printf("%s", output);

  int credits = n;
  int wordlength = 0;
  int outputpos = 0;
  int wordpos=0;
  
  char word[n];
  
  while ((c=getchar())!=EOF){

    /*scans word*/
    
    if (credits > 0 || c != '\n'){
      word[wordpos] = c;
      ++wordpos;
      ++wordlength;
      --credits;
      
      /*checks if the last character read is a delimiter*/

      if (c == ' '){
	i = copy(word, output, wordlength, i);
	output[i] = ' ';
	++i;
	--credits;
	wordpos = 0;
	wordlength = 0;
      }
      else if (c == '\t') {
	/*pass*/
      }
      else if (c == ',') {
	i = copy(word, output, wordlength, i);
	output[i] = ' ';
	++i;
	--credits;
	wordpos = 0;
	wordlength = 0;
      }
      else if (c == ';') {
	i = copy(word, output, wordlength, i);
	output[i] = ' ';
	++i;
	--credits;
	wordpos = 0;
	wordlength = 0;
      }
      else if (c == '.') {
	i = copy(word, output, wordlength, i);
	output[i] ' ';
	++i;
	--credits;
	wordpos = 0;
	wordlength = 0;
      }
    }

    /*check for wordlength is superfluous if c == '\n'*/
    
    else if (c == '\n') {
      i = copy(word, output, wordlength, i);
      output[i] = '\n';
      ++i;
      if (wordpos != 0){
	wordpos = 0;
	wordlength = 0;
	credits = n;
      }
      else
	credits = n;
    }
    
    /*to be continued
      TODO:
      if credits = 0
      case 1: wordlength < n (instert '\n' and print on next line)
      case 2: wordlength > n (print on current line and insert '\n')
     */

    else if (credits == 0) {
      /*pass*/
      if (wordlength < n && wordlength != 0)
	{}
      else if (wordlength == n)
	{}
      else {
	//	output[i] = '\n';
	//	++i;
	//	word[wordpos] = c;
	// Problem: if c is a delimiter (check)
      }
    }
  }
  output[i] = '\0';
}

int copy(char word[], char output[], int len, int i){
  int j = 0;

  while (j < len) {
    output[i] = word[j];
    ++i;
    ++j;
  }
  return i;
}
