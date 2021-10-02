# Python3 program to remove duplicate
# nodes from a sorted linked list 
 
# Node class 
class Node: 
 
    # Constructor to initialize 
    # the node object 
    def __init__(self, data): 
        self.data = data 
        self.next = None
 
class LinkedList: 
 
    # Function to initialize head 
    def __init__(self): 
        self.head = None
 
    # Function to insert a new node 
    # at the beginning 
    def push(self, new_data): 
        new_node = Node(new_data) 
        new_node.next = self.head 
        self.head = new_node 
 
    # Given a reference to the head of a 
    # list and a key, delete the first 
    # occurence of key in linked list 
    def deleteNode(self, key): 
         
        # Store head node 
        temp = self.head 
 
        # If head node itself holds the 
        # key to be deleted 
        if (temp is not None): 
            if (temp.data == key): 
                self.head = temp.next
                temp = None
                return
 
        # Search for the key to be deleted, 
        # keep track of the previous node as
        # we need to change 'prev.next' 
        while(temp is not None): 
            if temp.data == key: 
                break
            prev = temp 
            temp = temp.next
 
        # if key was not present in 
        # linked list 
        if(temp == None): 
            return
 
        # Unlink the node from linked list 
        prev.next = temp.next
 
        temp = None
 
    # Utility function to print the 
    # linked LinkedList 
    def printList(self): 
        temp = self.head 
        while(temp): 
            print(temp.data , end = ' ')
            temp = temp.next
     
    # This function removes duplicates 
    # from a sorted list         
    def removeDuplicates(self):
        temp = self.head
        if temp is None:
            return
        while temp.next is not None:
            if temp.data == temp.next.data:
                new = temp.next.next
                temp.next = None
                temp.next = new
            else:
                temp = temp.next
        return self.head
 
# Driver Code 
llist = LinkedList() 
print("Enter Number of Nodes in Linked List")
N = int(input())
print("Enter Values For Linked List:")
for _ in range(N):
    llist.push(int(input())) 

print ("Created Linked List: ")
llist.printList() 
print()
print("Linked List after removing duplicate elements:")
llist.removeDuplicates()
llist.printList() 
