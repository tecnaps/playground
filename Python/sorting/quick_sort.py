# paradigm: divide and conquer
# pivoting strategies:  first element
#                       last element
#                       random element
#                       median

# partition:    O(n)

def quickSort_array(ar: list):

    """quick sort algorithm for arrays"""

    pivot = partition(ar,0,len(ar)-1)
    quickSort_array(ar[0:pivot])
    quickSort_array(ar[pivot:len(ar)])
    #return ar

def partition (ar: list, low: int, high: int):

    """utility function to partition a given array at the pivot element"""

    pivot = ar[high]
    i = low
    for j in range(low+1, high):
        if ar[j] <= pivot:
            if ar[j] < ar[i]:
                ar = swap(ar, i, j)
                i +=1
    ar = swap(ar,i,high)
    return i+1
    
    
def swap (ar:list, left: int, right: int):

    """utility function for swapping two elements"""

    temp = ar[left]
    ar[left] = ar[right]
    ar[right] = temp
    return ar


