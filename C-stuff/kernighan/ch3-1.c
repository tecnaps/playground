#include <stdio.h>
#include <time.h>

#define LIMIT 100000

int binsearch(int x, int v[], int n);
int binsearch_old(int x, int v[], int n);

int main (){

    int v[LIMIT];

    clock_t tic, toc;
    double elapsed1, elapsed2;

    for (int i = 0; i < LIMIT; ++i)
        v[i] = i;

    tic = clock();

    for (int i = 0; i < 100 ; ++i)
        for (int x = 0; x < LIMIT; ++x)
            binsearch_old(x, v, LIMIT);    

    toc = clock();
    elapsed1 = (double)(toc-tic) / CLOCKS_PER_SEC;

    tic = clock();

    for (int i = 0; i < 100 ; ++i)
        for (int x = 0; x < LIMIT; ++x)
            binsearch(x, v, LIMIT);

    toc = clock();
    elapsed2 = (double)(toc-tic) / CLOCKS_PER_SEC;

    printf("Elapsed: %f seconds\n", elapsed1);
    printf("Elapsed: %f seconds\n", elapsed2);
}

int binsearch(int x, int v[], int n){

    int low, high, mid;

    low = 0;
    high = n-1;

    while (low < high){
        mid = (low + high)/ 2;
        if (x <= v[mid])
            high = mid;
        else
            low = mid + 1;
    }
        return (x == v[low]) ? low: -1;
}

int binsearch_old (int x, int v[], int n){

    /*find x in v[0] <= v[1] <= ... <= v[n-1]*/

    int low, high, mid;
    low = 0;
    high = n-1;
    while (low <= high){
        mid = (low+high)/2;
        if (x < v[mid])         // value of x lower than mid
            high = mid -1;
        else if (x > v[mid])    // value of x greater than mid
            low = mid+1;
        else                    // found match om v
            return mid;
    }
    return -1;                  // no match in v
}