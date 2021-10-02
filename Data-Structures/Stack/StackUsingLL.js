class Node {
    constructor(data) {
      this.data = data;
      this.next = null;
    }
}

class Stack {
    constructor() {
        this.head = null;
    }

    isEmpty() {
        return this.head === null;
    }

    push(data) {
        if (this.head) {
            const newNode = new Node(data);
            newNode.next = this.head;
            this.head = newNode;
        } else {
            this.head = new Node(data);
        }
    }

    pop() {
        if (this.head) {
            const data = this.head.data;
            this.head = this.head.next;
            return data;
        } else {
            throw "Stack underflow";
        }
    }

    peek() {
        if (this.head) {
            return this.head.data;
        } else {
            throw "Stack underflow";
        }
    }
}

const stack = new Stack();
console.log(stack.isEmpty());
stack.push(5);
stack.push(9);
stack.push(6);
console.log(stack.pop());
console.log(stack.peek());
stack.push(5);
console.log(stack.isEmpty());

//OUTPUT(TEST CASE)
//true
//6
//9
//false
