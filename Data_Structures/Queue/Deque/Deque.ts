// Node class 
class DequeNode {
  public data;
  public prev: DequeNode | null;
  public next: DequeNode | null;

  // Constructor to initialize
  // the node object
  constructor(data: any) {
      this.data = data;
      this.prev = null;
      this.next = null;
  }
}


class Deque {
  public head: DequeNode | null;
  public tail: DequeNode | null;

  // Constructor to initialize LinkedList
  constructor() {
      this.head = null;
      this.tail = null;
  }

  // Utility function just to see the results at a certain time
  print() {
      let a = []
      let pointer: DequeNode | null = this.head;
      while (pointer) {
          a.push(pointer.data)
          pointer = pointer.next
      }
      console.log(a)
  }

  // Function to see the beginning of the deque
  peekFront() { 
      return this.head && this.head.data;
  }


  // Function to insert a new DequeNode at the beginning of the deque
  // with the given value
  appendFront(data: any) {
      const newNode = new DequeNode(data)
      if(!this.head) {
          this.head = newNode;
          this.tail = newNode;
      } else {
          this.head.prev = newNode;
          newNode.next = this.head;
          this.head = newNode;
      }
  }

  // Function to remove a beginning at the end of the deque
  removeFront() {
      const value = this.peekFront();
      if(value) {
          if (this.head === this.tail) {
              this.head = null;
              this.tail = null;
          } else {
              this.head = this.head!.next;
              this.head!.prev = null;
          }
      }
      return value;
  }

  // Function to see the end the deque
  peekBack() { 
      return this.tail && this.tail.data;
  }

  // Function to insert a new DequeNode at the beginning of the deque
  // with the given value
  appendBack(data: any) {
      const newNode = new DequeNode(data)
      if(!this.tail) {
          this.head = newNode;
          this.tail = newNode;
      } else {
          newNode.prev = this.tail;
          this.tail.next = newNode;
          this.tail = newNode;
      }
  }

  // Function to remove a node at the end of the deque
  removeBack() {
      const value = this.peekBack();
      if(value) {
          if (this.head === this.tail) {
              this.head = null;
              this.tail = null;
          } else {
              this.tail = this.tail!.prev;
              this.tail!.next = null;
          }
      }
      return value;
  }
}

const deque = new Deque();
deque.appendFront(22);
deque.appendBack(4);
deque.appendBack(97);
deque.appendFront(1);
deque.appendBack(5);
deque.print()
deque.removeFront()
deque.removeBack()
deque.removeFront()
deque.print()
console.log('Current front:', deque.peekFront());
console.log('Current back:', deque.peekBack());
