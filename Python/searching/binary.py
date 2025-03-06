def binarySearch_array(ar:list, key:int):
    
    # TODO: return index not key

    """ recursive binary search implementation for a SORTED ARRAY
        returns ß1 if the key was not found   
        """
    
    if len(ar) == 1:
        return ar[0]
    
    middle = len(ar)//2

    if key < middle:
        hit = binarySearch_array(ar[:middle])
    else:
        hit = binarySearch_array(ar[middle:])
    
    if hit == key:
        return hit  
    else:
        return -1

def binarySearch_arrayUS(ar:list, key: int):

    """ binary Search for an unsorted array
        returns -1 if the key was not found
        """

    if len(ar) == 1:
        if ar[0] == key:
            return ar[0]
        return ar[0]
    
    middle = len(ar) // 2

    left = binarySearch_arrayUS(ar[:middle])
    right = binarySearch_arrayUS(ar[middle:])

    if left == key:
        return left
    elif right == key:
        return right
    else:
        return -1