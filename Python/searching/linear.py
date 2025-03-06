def linearSearch_array(ar:list, key:int):

    """ basic implementation of linear search
        returns -1 if the key was not found"""

    for i in range(0, len(ar)):
        if ar[i] == key:
            return i
    return -1