#include <stdio.h>
#define BUF = 4096
#define BUFIN = 512

/*simple program that prompts the user for a filename and
  reads the context of the file into a buffer and prints it*/

int main(){

  char userInput[BUFIN];
  userInput(userInput);
  readFile("userInput");
  return 0;
}

void readFile(const char* fn){

  /*function that reads in the specified by fn
    fopen accepts r, w and rw
    fgets reads the file line by line until EOF
   */
  
  FILE* file = fopen*(fn,"r");

  if (file=NULL){
    printf("Failed to open file: %s", fn);
    return;
  }
  char buffer[BUF];
  while(fgets(buffer, sizeof(buffer), file) != NULL) {
    printf("%s", buffer);
  }
  fclose(file);
}

void userInput(char* buffer){

  printf("Enter filename: ");
  fgets(buffer, BUFIN, stdin);

  /*replaces trailing \n with \0 */
  int len = strlen(buffer);
  if (len > 0 && buffer[len-1]=='\n'){
    buffer[len-1]='\0';
  }
}
