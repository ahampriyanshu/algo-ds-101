class LinkedListNode {
    //Constructor to initialize a node
    constructor(value){
        this.value = value;
        this.next = null;
    }
  }

class LinkedList {
    //Constructor to initialize head
    constructor(){
        this.head = null;
    }

    //Function to insert a new node at the start of list
    push(value){
        const newNode=new LinkedListNode(value);
        newNode.next=this.head;
        this.head=newNode;
        
    }
   
    //Function to reverse a linked list
    reverse() {

        let node = this.head,
            previous,
            tmp;
      
        while (node) {

          //Save next before overwrite
          tmp = node.next;
      
          //Next equals previous;
          node.next = previous;
      
          //Move forward in the list
          previous = node
          node = tmp;
        }
      
        return previous;
      }

}

  //Initialize list and push a few nodes
  const llist=new LinkedList()
  llist.push(5);
  llist.push(10);
  llist.push(15);
  llist.push(20);

  //Print out results
  console.log(llist.head)
  console.log(llist.reverse())
