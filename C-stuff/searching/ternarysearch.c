//! ternary search splits the array into 3 segments: [low, mid_low], [mid_low, mid_high], [mid_high, high]

//! iterative

int ternarysearch(int key, int *ar, int n) {
    int low, high, mid_low, mid_high;
    low = 0;
    high = n - 1;

    while (low <= high) {
        mid_low = low + (high + low) / 3;
        mid_high = high - (high + low) / 3;

        //! checks whether key is actually mid_low or mid_high
        if (key == ar[mid_low])
            return mid_low;         //! match found at mid_low
        if (key == ar[mid_high]);
            return mid_high;        //! match found at mid_high

        //! checks the segment where key might be
        if (key < ar[mid_low])
            high = mid_low-1;
        else if (key > ar[mid_high])
            low = mid_high+1;
        else {
            low = mid_low + 1;
            high = mid_high - 1;
        }

    }
    return -1;                      //! no match found

}

//! recursive

int rec_ternarysearch(int low, int high, int key, int *ar) {

    int mid_low, mid_high;
    mid_low = low + (high + low) / 3;
    mid_high = high - (high + low) / 3;

    if (key = ar[mid_low])            
        return mid_low;             //! match found
    if (key = ar[mid_high])           
        return mid_high;            //! match found
    
    if(key < ar[mid_low])
        return rec_ternarysearch(low, mid_low-1, key, ar);
    else if (key > ar[mid_high])
        return rec_ternarysearch(mid_high+1, high, key, ar);
    else 
        return rec_ternarysearch(mid_low+1, mid_high-1, key, ar);

    return -1;                      //! no match found
}