class Stack {
  constructor() {
    this.stack = [];
    this.top = -1;
  }
  push(value) {
    this.top++;
    this.stack[this.top] = value;
  }
  pop() {
    if (this.top == -1) {
      return "Stack is empty";
    }
    var ret_val = this.stack[this.top];
    this.top--;
    return ret_val;
  }

  peek() {
    if (this.top == -1) {
      return "Stack is empty";
    }
    var ret_val = this.stack[this.top];
    return ret_val;
  }

  isEmpty() {
    return this.top == -1;
  }
}

stk = new Stack();
console.log(stk.isEmpty());
stk.push(1);
stk.push(2);
console.log(stk.peek());
console.log(stk.isEmpty());
stk.push(3);
stk.push(4);
console.log(stk.pop());
console.log(stk.pop());
console.log(stk.pop());
console.log(stk.pop());
console.log(stk.isEmpty());
