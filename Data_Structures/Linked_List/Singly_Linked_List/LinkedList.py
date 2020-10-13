class Node:
    def __init__(self, dataval=None):
        self.dataval = dataval
        self.nextval = None


class SLinkedList:
    def __init__(self):
        self.headval = None


list1 = SLinkedList()
list1.headval = Node("Mon")
a2 = Node("Tue")
a3 = Node("Wed")

# Link first Node to second node
list1.headval.nextval = a2

# Link second Node to third node
a2.nextval = a3
