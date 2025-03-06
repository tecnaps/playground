import linearsort
import insertion_sort
import merge_sort
import quick_sort
from datastructures.LinkedList import LinkedList
from datastructures.node import node

arr = [2,6,34,87,34,67,1,54,1]
# arr = linearsort.linear_array(ar, len(ar))
# arr = insertion_sort.insertionSort_array(arr, len(arr))
# arr = merge_sort.mergeSort_array(arr)
quick_sort.quickSort_array(arr)
print(arr)


ar = LinkedList()
ar.append(node(4))
ar.append(node(1))
ar.append(node(45))
ar.append(node(3))
ar.append(node(1))
ar.append(node(2))
ar.toString()
#linearsort.linear_list(ar)
#ar = insertion_sort.insertionSort_linked(ar)
newHead = merge_sort.mergeSort_linked(ar.head)
print("\n")
#ar.toString()

sortedList = LinkedList()

while newHead is not None:
    #print(sortedList.value, end=" ")
    sortedList.append(newHead)
    newHead = newHead.next
sortedList.toString()
