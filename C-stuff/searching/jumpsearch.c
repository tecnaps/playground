//! jumnp search algorithm

#include <stdio.h>
#include <math.h>

int min(int a, int b){
    if(a < b)
        return a;
    else
        return b;
}

int jumpsearch (int key, int n, int *ar){

    //! finding optimal block size
    int step = sqrt(n);

    //! locating the segment containing the key
    int prev = 0;
    while (ar[min(step, n)-1] < key){
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;      //! no segment found
    }


    //! doing a linear search in the block
    while (ar[prev] < key) {
        prev++;

        //! checks if end of segment has been reached

        if (prev == min(step, n))
            return -1;      //! key has not been found
    }

    if (ar[prev] == key)
        return prev;        //! key has been found

    return -1;              //! key has not been found
}