# Zeitkomplexität:     O (n log n) 
#                      in allen 3 Fällen: worst, average, best
#                      da MERGE immer LINEAR und immer in log(n) TEILT
#                      Rekurrenzrelation: T(n) = 2T(n / 2) + Theta(n)
# Speicherkomplexität: n (Hilfsarray)
# Paradigma:           divide and conquer
# in Place:            normalerweise nicht 
# Stable:              yes
# Anwendung:           LinkedLists in n log n sortieren
# Probleme:            langsamer als...
#                      zusätzlicher Speicherbedarf

from turtle import left
from datastructures.LinkedList import LinkedList
from datastructures.node import node

def mergeSort_array(ar:list):

    """Merge sort for arrays"""

    if len(ar) > 1:
        m = len(ar) // 2            # // drops the fractional part
        l = mergeSort_array(ar[:m])
        r = mergeSort_array(ar[m:])

        i = j = k = 0

    # compares elements from left and right arrays an copies the smallest
        while i < len(l) and j < len(r):
            if l[i] < r[j]:
                ar[k] = l[i]
                i +=1
            else:
                ar[k] =r[j]
                j +=1
            k += 1
    
    # if elements in the left array are left over
        while i < len(l):
            ar[k]=l[i]
            i += 1
            k += 1
    
    # if elements in the right array are left over
        while j < len(r):
            ar[k] = r[j]
            j +=1
            k +=1
    return ar

# advantage:  little random access

# time complexity:  O(n log n)
# space complexety: O(n)

# Alternative approach with log n space: https://www.geeksforgeeks.org/merge-sort-for-linked-list/


def mergeSort_linked(start: node):

    """ Merge sort for linked lists
        returns not the sorted list, but the new head !!!
    """

    if (start is None) or (start.next is None):
        return start

    middle = findMiddle(start)
    right_start = middle.next
    middle.next = None

    left = mergeSort_linked(start)
    right = mergeSort_linked(right_start)

    sortedList = sortedMergeSort(left, right)

    return sortedList

def findMiddle(start: node):

    """utility function to find the middle of a LikedList"""

    if start is None:
        return start
    
    middle = start
    fast = start
    while (fast.next is not None) and (fast.next.next is not None):
        middle = fast.next
        fast = fast.next.next
    
    return middle

def sortedMergeSort(left: LinkedList, right: LinkedList):

    """sort function, combines split halves"""

    # if left list is exhausted
    if left is None:
        return right

    # if right list is exhausted
    if right is None:
        return left

    # if the element in left list is smaller
    if left.value <= right.value:
        sortedList = left
        left.next = sortedMergeSort(left.next, right)

    # if the element in right list is smaller
    else:
        sortedList = right
        right.next = sortedMergeSort(right.next, left)
    
    return sortedList