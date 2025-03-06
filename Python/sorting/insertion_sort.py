# Use Cases:    for small Arrays 
#               Arrays that are almost sorted

# works with partially ordered data

# maximum time: sorted in reverse order
# minimum time: already sorted

# in place
# incremental sorting
# stable

from datastructures.LinkedList import LinkedList
from datastructures.node import node

def insertionSort_array (ar:list, n:int):

    """
    simple insertion sort algorithm
    
    time:   O(n^2)
    space:  O(1)
    """

    key = 0
    for i in range(0,n):
        key = ar[i]
        j = i-1

        # we shift all Elements greater than the key to the right
        # finally we insert the key

        while (j >= 0) and (key < ar[j]):
            ar[j+1] = ar[j]
            j -= 1
        ar[j+1] = key
    
    return ar

def insertionSort_linked(ar:LinkedList):
    current = ar.head.next
    sorted_list = LinkedList(node(ar.head.value))
    while current is not None:
        key = node(current.value)
        comparator = sorted_list.head
        
        # compares key against the sorted list to find a bigger entry
        while key.value >= comparator.value:
            if comparator.next is not None:
                comparator = comparator.next
            
            # if key is the tallest entry: inserts key at the end 
            else:
                comparator.setNext(key)
                key.setPrevious(comparator)
                break
        
        # if key is the smallest entry: inserts key in front and adjust head
        if comparator.previous is None:
            comparator.setPrevious(key)
            key.setNext(comparator)
            sorted_list.head = key

        # if key is neither the smallest nor the tallest element: insert in the middle
        elif comparator.next is not key:
            comparator.previous.setNext(key)
            key.setPrevious(comparator.previous)
            key.setNext(comparator)
            comparator.setPrevious(key)

        current = current.next

    return sorted_list
        