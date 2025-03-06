//! sorts lines of text in alphabetic order

//! Data structure: array of pointers. Each line accessed via pointer to 1st character (storred in the array); lines are compared with strcmp()

//! Note: instead of swapping lines only the pointers trade places
//! Note: only a finite number of input lines is accepted

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

//! I/O

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

//! sorting

void qsort(char *lineptr[], int left, int right);
void swap(int *lineptr, int i, int j);

//! driver

main(){
    int nlines;

    if((nlines = readlines(lineptr, MAXLINES)) >= 0){
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

//! readlines> read input lines

#define MAXLEN 1000         //! max length of an input line
int getline(char *, int);
char *alloc(int);

int readlines(char*lineptr[], int maxlines){
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while((len = getline(line, MAXLEN)) > 0)
        if(nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

//! writelines: writes output lines

void writelines(char *lineptr[], int nlines) {
    for(int i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

//! getline: reads a line into an array s, returns its length

int getline(char s[], int lim){

    int c,i;

    //! adds character to s if it is not EOF or newline
    for(i = 0; i < lim-1 && (c=getchar())!= EOF && c!='\n'; ++i)
        s[i] = c;
    if(c == '\n'){
        s[i]= c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

//! qsort: sort v[left]... v[right] in increasing order

void qsort(char *lineptr[], int left, int right){
    int i, last;
    if (left >= right)
        return;
    swap(lineptr, left, (left+right) / 2);
    last = left;
    for (i=left + 1; i <= right; i++)
        if (lineptr[i] < lineptr[left])
            swap(lineptr, ++last, i);
    swap(lineptr, left, last);
    qsort(lineptr, left, last-1);
    qsort(lineptr, last+1, right);
}

//! swap: swaps lineptr[i] for lineptr[j]

void swap(int *lineptr, int i, int j){
    int temp;
    temp = lineptr[i];
    lineptr[i]= lineptr[j];
    lineptr[j] = temp;
}