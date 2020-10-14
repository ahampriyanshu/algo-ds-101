//implimentation of function that returns the data at the middle element of the linked list in JavaScript
// functions declared
//     insertFirst
//     insertLast
//     size
//     getFirst
//     getLast
//     middlePoint
//     removeFirst
//    removeLast
//    clear
//    removeAt
//    insertAt
//    getFirst
//    getLast
//    getAt
class Node {
  constructor(data, next = null) {
   this.data = data;
   this.next = next;
  }
}
class LinkedList {
  constructor() {
    this.head = null;
  }

insertFirst(data) {
    const node = new Node(data, this.head);
    this.head = node;
  }
size() {
    let counter = 0;
    let node = this.head;
    while (node) {
     counter++;
     node = node.next;
    }
    return counter;
  }
  
getFirst() {
    return this.head.data;
  }
getLast() {
    if (!this.head) {
      return null;
    }
    let node = this.head;
    while (node) {
     if (!node.next) {
      return node;
     }
     node = node.next;
    }
  }
  
clear() {
    this.head = null;
  } 
removeFirst() { 
    if (!this.head) {
     return;
    }
    this.head = this.head.next;
   }
removeLast() {
    if (!this.head) {
      return;
    }
   
    if (!this.head.next) {
     this.head = null;
    }
   
    let previous = this.head;
    let node = this.head.next;
   
    while (node.next) {
      previous = node;
      node = node.next;
    }
    
    previous.next = null;
   }   
insertLast(data) {
    const last = this.getLast();
    if (last) {
     last.next = new Node(data);
    } else {
      this.head = new Node(data);
    }
   }
getAt(index) {
    let counter = 0;
    let node = this.head;
    while (node) {
     if (counter === index) {
      return node;
     }
     counter++;
     node = node.next;
    }
   return null;
  } 
removeAt(index) {
  if (!this.head) {
    return;
  }  if (index === 0) {
    this.head = this.head.next;
    return;
  }
  
  const previous = this.getAt(index - 1);
  if (!previous || !previous.next) {
    return;
  }
  previous.next = previous.next.next;
 } 
insertAt(data, index) {
   if (!this.head) {
    this.head = new Node(data);
    return;
   }
   if (index === 0) {
    this.head = new Node(data, this.head);
    return;
   }
  const previous = this.getAt(index - 1) || this.getLast();
  const node = new Node(data, previous.next);
  previous.next = node; 
 }
}
function midpoint(list) {
  let slow = list.head;
  let fast = list.head;
  while (fast.next && fast.next.next) {
   slow = slow.next;
   fast = fast.next.next;
  }
  
  return slow.data;
 }
const l = new LinkedList();
l.insertLast("a");
l.insertLast("b");
l.insertLast("c");
l.insertLast("d");
l.insertLast("e");
console.log(midpoint(l)); // returns 'c'