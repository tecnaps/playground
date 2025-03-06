//! binsearch: find x in ar[0] <= ar[1] <= ... <= ar[n]

int binsearch( int x, int *ar, int n){
    int low, high, mid;
    low = 0;
    high = n-1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (x < ar[mid])        //! target must be in the lower half
            high = mid +1;
        else if (x > ar[mid])   //! target must be in the higher half
            low = mid + 1;
        else                    //! found match
            return mid;
    } 
    return -1;                  //! found no match

}

int alt_binsearch(int x, int *ar, int n) {

//! binary search with only 1 test inside the loop (ker 3-1)

    int low, high, mid;
    low = 0;
    high = n-1;

    while(low < high) {
        mid = (high + low) / 2;
        if ( x < ar[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    if ( x == ar[low -1])
        return 0;
    else if (x == ar[low])
        return 0;
    else
        return -1;
}