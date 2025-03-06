#include <stdio.h>

#define TAB 8
#define MAXLINE 80

void flush(char line[], int lim);
int trim(char line[], int start, int end);

int main (){

    int c, cnt, blank, blankPos, i, j;
    char line[MAXLINE];

    cnt = blank = blankPos = j = 0;

    while ((c=getchar()) != EOF){

        if (c != '\t' && c != '\n') {                   //no tabstop no newline
            if (c == ' '){                              //character is blank
                line[cnt] = c;
                blank = 1;
                blankPos = cnt;
                ++cnt;
            } else{                                     //character is no blank
                line[cnt] = c;
                ++cnt;
            }
        }
        else if (c == '\n'){                            //newline read
            flush(line, cnt);
            blank = 0;
            blankPos = 0;
            cnt = 0;
        }
        else if (c == '\t'){                            //tabstop read
            if (cnt % TAB == 0){
                if (cnt + TAB >= MAXLINE){              //flush
                    flush(line, cnt);
                    putchar('\n');
                    blank =0;
                    blankPos = 0;
                    cnt = 0;
                } else {                                //entab
                    for (i=0; i < TAB; ++i)
                        line[cnt++] = ' ';
                    blank = 1;
                    blankPos = cnt;
                }
            } else{
                if (cnt +(TAB-(cnt % TAB)) >= MAXLINE){ //flush
                    flush(line, cnt);
                    putchar('\n');
                    blank =0;
                    blankPos = 0;
                    cnt = 0;
                } else {                                //entab
                    for (i=0; i < TAB; ++i)
                        line[cnt++] = ' ';
                    blank = 1;
                    blankPos = cnt;
                }
            }
        }
        if (cnt > MAXLINE){                             //MAXLINE reached
            if (blank == 1){                            //blank in line
                flush(line, blankPos);
                putchar('\n');

                j = trim(line, blankPos, cnt);          //trims trailing blanks
                for (i=j;i < cnt; ++i)
                    line[(i-j)] = line[i];

                blank=0;
                blankPos=0;
                cnt=i-j;
            } else {                                    //no blank in line
                flush(line, cnt);
                putchar('-');
                putchar('\n');
                cnt = 0;
            }
        } 

    }


}

void flush(char line[], int lime){

    /*prints contents of line and trims leading blanks*/

    int i, j;

    i = j = 0;
    if (line[0]== ' ')                                  //check for leading blanks
        j = trim(line, 0, lime);

    for (i = j; i< lime; i++)
        putchar(line[i]);
}

int trim(char line[], int start, int end){

    /*trims blanks by skipping over them in line*/

    int i = start;
    while (line[i] == ' ' && i < end)
        ++i;

    return i;
}