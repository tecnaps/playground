from datastructures.node import node

class LinkedList:
    """Implementation of a basic LinkedList
        - init()
        - append()
        - pop()
        - toString()
    """
    
    def __init__(self, *args):
        if len(args) == 0:
            self.head = None
            self.end = None
            self.length = 0
        else:
            self.head = args[0]
            self.end = args[0]
            self.length = 1
    
    def append(self, Element: node):
        if self.head == None:
            self.head = Element
            self.end = self.head
            self.length = 1
        else:
            Element.setPrevious(self.end)
            self.end.setNext(Element)
            self.end = Element
            self.length += 1
    
    def pop(self):
        if self.end == self.head:
            temp = self.head
            self.head = None
            self.length -=1
            return temp
        else:
            temp = self.end
            self.end = self.end.previous
            self.length -= 1
            return temp

    def toString(self):
        current = self.head
        while current is not None:
            print(current.value, end= " ")
            current = current.next

#    def search(self, value):
