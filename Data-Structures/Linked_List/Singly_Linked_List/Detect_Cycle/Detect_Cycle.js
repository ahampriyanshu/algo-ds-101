class ListNode {
    constructor(data) {
        this.data = data
        this.next = null                
    }
}

class LinkedList {
    constructor(head = null) {
        this.head = head
    }


  add(element) 
  { 
      // creates a new node 
      let  node = new ListNode(element); 
    
      // to store current node 
      let  current; 
    
      // if list is Empty add the 
      // element and make it head 
      if (this.head == null) 
          this.head = node; 
      else { 
          current = this.head; 
    
          // iterate to the end of the 
          // list 
          while (current.next) { 
              current = current.next; 
          } 
    
          // add node 
          current.next = node; 
      } 
    
} 

hasCycle (head) {
 if(!head) return false;
    
 let slow=head;
 let fast=head.next;
 while(slow!=fast)
 {
  if(!fast || !fast.next)
    return false;
     
  slow=slow.next;
  fast=fast.next.next;
 }
 
 return true;
};

}
const myList = new LinkedList(); 
myList.add(20);
myList.add(30);
myList.add(50);

myList.head.next.next.next= myList.head;
let ans=myList.hasCycle(myList.head);

if(ans == true){
  console.log(" The list contains cycle");
}
else{
   console.log(" The list does not contain cycle");
}