/*  rewrite: no need to count all characters only non blanks and blanks within 
    the current range */

#include <stdio.h>

#define TAB 8

/*  entab: converts blanks into tabs
    note: trailing blanks are kept / replaced by tabs */


int main(){

    int c, i, characterCnt, blankCnt;
    
    characterCnt = 0;
    blankCnt = 0;
    while((c=getchar())!=EOF){
        if (c =='\n'){
            if (blankCnt == 0){             //no blanks before newline
                putchar(c);
                characterCnt = 0;
            } else{                         //blanks before newline
                for(i=0; i<blankCnt;++i)
                    putchar(' ');
                putchar(c);
                characterCnt = 0;
                blankCnt = 0;
            }
        } else if (c == ' '){
            ++blankCnt;
            if (characterCnt+blankCnt % TAB == 0){  //tab stop reached
                putchar('\t');
                characterCnt+=blankCnt;
                blankCnt = 0;
            }
        } else if (c != ' ' && blankCnt > 0) {      //1st non-blank character after # of blanks
            if (characterCnt+blankCnt % TAB == 0){  //tab-stop reached
                putchar('\t');
                putchar(c);
                characterCnt += blankCnt;
                blankCnt = 0;
            } else {                                //no tab-stop reached, fill with blanks
                for (i = 0; i<blankCnt; ++i){
                    putchar(' ');
                    ++characterCnt;
                }
                putchar(c);
                blankCnt = 0;
            }

        } else {
            putchar(c);
            ++characterCnt;
        }
    }

}