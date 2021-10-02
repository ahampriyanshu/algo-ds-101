class Node:
    def __init__(self,data):
        self.data = data
        self.next = None
     
class Stack:

    def __init__(self):
        self.head = None
     
    def isempty(self):
        if self.head == None:
            return True
        else:
            return False
     
    def push(self,data):
         
        if self.head == None:
            self.head=Node(data)
             
        else:
            new_node = Node(data)
            new_node.next = self.head
            self.head = new_node

    def pop(self):
         
        if self.isempty():
            print("Stack Underflow!")
            return None
             
        else:
            pop_node = self.head
            self.head = self.head.next
            pop_node.next = None
            return pop_node.data
     
    def peek(self):
         
        if self.isempty():
            return None
             
        else:
            return self.head.data
        
    def display(self):
         
        iter_node = self.head
        if self.isempty():
            print("Stack Underflow!")
         
        else:
             
            while(iter_node != None):
                 
                print(iter_node.data,"->",end = " ")
                iter_node = iter_node.next
            return
         
# Driver code
MyStack = Stack()
 
MyStack.push(1)
MyStack.push(2)
MyStack.push(3)
MyStack.push(4)
 
# Display stack elements
MyStack.display()
 
# Print top element of stack
print("\nStack Top: ",MyStack.peek())
 
# Delete top elements of stack
MyStack.pop()
MyStack.pop()
 
# Display stack elements
MyStack.display()
 
print("\nStack Top: ", MyStack.peek())

# Output:
#     4 -> 3 -> 2 -> 1 -> 
#     Stack Top:  4
#     2 -> 1 ->
#     Stack Top:  2
