class Deque {
  constructor() {
    this.front = this.back = undefined;
  }
//   Adds a node to front of linked list
  addFront(value) {
    if (!this.front) this.front = this.back = { value };
    else this.front = this.front.next = { value, prev: this.front };
  }
//   Remove a node from the front of linked list
  removeFront() {
    let value = this.peekFront();
    if (this.front === this.back) this.front = this.back = undefined;
    else (this.front = this.front.prev).next = undefined;
    return value;
  }
//   Get the value from the first node 
  peekFront() {
    return this.front && this.front.value;
  }
//   Adds a node to end of linked list
  addBack(value) {
    if (!this.front) this.front = this.back = { value };
    else this.back = this.back.prev = { value, next: this.back };
  }
//   Removes a node from the back of linked list
  removeBack() {
    let value = this.peekBack();
    if (this.front === this.back) this.front = this.back = undefined;
    else (this.back = this.back.next).back = undefined;
    return value;
  }
  //   Get the value from the first node 
  peekBack() {
    return this.back && this.back.value;
  }
}

// demo
let deque = new Deque;
console.log(deque.peekFront()); // undefined
deque.addFront(1);
console.log(deque.peekBack()); // 1
deque.addFront(2);
console.log(deque.removeBack()); // 1
deque.addFront(3);
deque.addFront(4);
console.log(deque.peekBack()); // 2
deque.addBack(5);
deque.addBack(6);
console.log(deque.peekBack()); // 6
console.log(deque.removeFront()); // 4
console.log(deque.removeFront()); // 3
console.log(deque.removeFront()); // 2
console.log(deque.removeFront()); // 5
console.log(deque.removeFront()); // 6
console.log(deque.removeFront()); // undefined
