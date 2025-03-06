# plain import produces: TypeError: 'module' object is not callable, see
# https://www.stechies.com/typeerror-module-object-is-not-callable/

#from re import S
from datastructures.LinkedList import LinkedList 

def linear_array(ar: list, n: int):
    """linear sort for int Array"""
    elem = ar[0]
    for i in range(0, n):
        for j in range(i+1,n):
            if ar[j] < ar[i]:
                elem = ar[j]
                ar[j] = ar[i]
                ar[i] = elem
    return ar

def linear_list(ar:LinkedList):
    """linear sort for custom LinkedList"""
    outer_iterator = ar.head
    inner_iterator = None
    comparator = None
    switch = False

    while outer_iterator is not None:
        
        inner_iterator = outer_iterator.next
        comparator = outer_iterator
        while inner_iterator is not None:
            if inner_iterator.value < comparator.value:
                comparator = inner_iterator
                switch = True
            inner_iterator = inner_iterator.next
        
        # sort 
        if switch == True:

            # removes comparator from the list and closes the gap
            if comparator.next is None:
                comparator.previous.setNext(None)
            else:
                comparator.previous.setNext(comparator.next)
                comparator.next.setPrevious(comparator.previous)

            # inserts comparator before the outer_iterator, changes head
            if outer_iterator.previous is None:
                outer_iterator.setPrevious(comparator)
                comparator.setPrevious(None)
                comparator.setNext(outer_iterator)
                ar.head = comparator
            else:
                comparator.setPrevious(outer_iterator.previous)
                outer_iterator.previous.setNext(comparator)
                comparator.setNext(outer_iterator)
                outer_iterator.setPrevious(comparator)
            switch = False

        else:

            # current outer_iterator is where it belongs 
            # and moves to the next node
            outer_iterator = outer_iterator.next