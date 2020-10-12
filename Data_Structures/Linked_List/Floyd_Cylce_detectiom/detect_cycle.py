#Linked List Class
class Linked_List: 
  
    def __init__(self): 
        self.head = None
  
    def push(self, new_data): 
        node = Node(new_data) 
        node.next = self.head 
        self.head = node 
  
    def print_list(self):
        head = self.head
        pointer = self.head
        while(pointer):
            print(pointer.data)
            pointer = pointer.next
            if(pointer == head):
                print(pointer.data)
                break
    
    def detectLoop(self): 
        first_pointer = self.head 
        second_pointer = self.head 
        while(first_pointer and second_pointer and second_pointer.next): 
            first_pointer = first_pointer.next
            second_pointer = second_pointer.next.next
            if first_pointer == second_pointer: 
                return True
        return False

class Node: 
    def __init__(self, data): 
        self.data = data 
        self.next = None

def check_result(result):
    if result:
            print("Loop Founded")
    else: 
            print("No Loop Present")

#First Test Case
linked_list = Linked_List()
linked_list.push(2) 
linked_list.push(4) 
linked_list.push(29) 
linked_list.push(5) 
linked_list.push(14) 
   
#Creating loop so can test
linked_list.head.next.next.next.next.next = linked_list.head; 
linked_list.print_list()
check_result(linked_list.detectLoop())

#Second Test Case
linked_list = Linked_List()
linked_list.push(2) 
linked_list.push(4) 
linked_list.push(29) 
linked_list.push(53) 
linked_list.print_list()
check_result(linked_list.detectLoop())