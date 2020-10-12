class Queue {

  constructor(initial=[]) {
    if (!Array.isArray(initial))
      throw Error('You can only initialize with an array')
    this.q = initial
  }

  put(element) {
    this.q.push(element)
  }

  get() {
    return this.q.shift()
  }

  print() {
    console.log(this.q)
  }

}

// Example work with Queue
const queue = new Queue([5, 8, 3])

queue.print()
console.log(queue.get())
queue.print()
queue.put(8)
queue.put(0)
queue.print()
queue.get()
queue.get()
queue.print()
