//! Interpolation search

//! uniform distribution of data

//! complexity:     linear search: O(n)
//!                 jump search: O(sqrt(n))
//!                 binary search: O(log(n))
//!                 interpolation search: improves on binary search

//! difference: interpolation search is not bound to divide the array in the middle depending on the key-element 
//!             interpolation gives the pivot element

//! pivot formula:     pos = low + ((key -ar[low])*(high-low)) / (ar[high]-ar[low])
//!                    different interpolation formula are also possible (see numerics)

//! linear interpolation:

//! pivot formula:      (key - low) / (high-low)

//! constant (K):   K is used to narrow the search space


//! pivot formula:  key, x (index of the key)

//!                 line formula: y = mx + c

//!                 (1) ar[high]= m * high + c
//!                 (2) ar[low]= m * low + c
//!                 (3) x = m * pos + c

//!                 m = (ar[high] - ar[low]) / (high - low)

//!                 (3)-(2) x - ar[low] = m * (pivot - low)
//!                 pivot = low + (x - ar[low]) / m 
//!                 pivot = low + ((x - ar[low]) * (high - low)) / (ar[high] - ar[low])


#include <stdio.h>

int rec_interpolsearch(int key, int low, int high,  int* ar){

    //! recursive implementation
    
    //! time:   average:    O(log_2(Log_2(n)))
    //!         worst:      O(n)

    //! space:  O(1)

    int pivot;

    if (low <= high && key >= ar[low] && key <= ar[high]){

        //! probes the position of the key (condition: uniform distribution of the elements of ar)

        pivot = low + (((double)(high-low) / (ar[high] - ar[low])) * (key - ar[low]));

        if (ar[pivot] == key)
            return pivot;           //! match found
        
        if(ar[pivot] < key)
            return rec_interpolsearch(key, pivot+1, high, ar);
        
        if (ar[pivot]> key)
            return rec_interpolsearch(key, low, pivot-1, ar);
        
    }

    return -1;                      //! no match found

}



//! iterative:

int interpolsearch (int key, int length, int *ar){

    int low, high, pivot;

    low = 0;
    high = length-1;

    while(low <= high && key >= ar[low] && key <= ar[high]){

        if (low == high){

            if(ar[low] == key)
                return low;         //! match found
                
            return -1;              //! no match found
        }

        //! probes the position of the key (condition: uniform distribution of the elements of ar)

        pivot = low + (((double)(high-low) / (ar[high] - ar[low])) * (key - ar[low]));

        if (ar[pivot] == key)
            return pivot;           //! match found
        
        if (ar[pivot] < key)
            low = pivot + 1;        
        else
            high = pivot - 1;
    }

    return -1;                      //! no match found

}