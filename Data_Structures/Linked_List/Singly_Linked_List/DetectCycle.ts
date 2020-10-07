// Node class 
class ListNode {
    public data;
    public next: ListNode | null;

    // Constructor to initialize
    // the node object
    constructor(data: any) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    public head: ListNode | null;

    // Constructor to initialize LinkedList
    constructor() {
        this.head = null;
    }
    
    // Function to insert a new LinedListNode at the end of the list
    // with the given value
    append(data: any) {
        const newNode = new ListNode(data)
        if(!this.head) {
            this.head = newNode;
        } else {
            let pointer: ListNode | null = this.head;
            while (pointer.next) {
                pointer = pointer.next
            }
            pointer.next = newNode;
        }
    }
    
    // Function that detects if there is a cycle in the list
    // using Floyd's cycle-finding algorithm
    hasCycle() {
        // Floyd's Tortoise and Hare
        let slowPointer: ListNode | null = this.head;
        let fastPointer: ListNode | null = this.head;
        while(slowPointer && fastPointer && fastPointer.next) {
            slowPointer = slowPointer.next;
            fastPointer = fastPointer.next.next;
            if(slowPointer == fastPointer) {
                return true;
            }
        }
        return false;
    }


}
  
  
// Create a LinkedList instance and append values
const linkedList = new LinkedList()
linkedList.append(22)
linkedList.append(4)
linkedList.append(97)
linkedList.append(1)
  
// Create a loop
// assigning the `next` of the last node to be the head of the LinkedList
linkedList.head.next.next.next.next = linkedList.head;

if(linkedList.hasCycle()) {
    console.log("Cycle is present");
} else {
    console.log("Cycle is not present");
}