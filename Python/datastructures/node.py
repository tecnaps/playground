class node:
    """basic node class
    - init
    - setnext
    - setprevious
    """
    def __init__(self, value):
        self.value = value
        self.next = None
        self.previous = None
    
    def setNext(self, next):
        self.next= next

    def setPrevious(self, previous):
        self.previous = previous