import Foundation

// Generic Algorithm
struct Queue<Element> {
    var array = [Element]()
    
    // ENQUEUE: Add an element at the end of the queue
    mutating func enqueue(_ element: Element) {
        array.append(element)
    }
   
    // DEQUEUE: Remove the element from the beginning of the queue
    mutating func dequeue() -> Element? {
        return isEmpty ? nil : array.removeFirst()
    }
    
    // PEEK: Returns the first element in the queue
    func peek() -> Element? {
        return array.first
    }
    
    // Is queue empty?
    var isEmpty: Bool {
        return array.isEmpty
    }
    
    // Number of elements in queue
    var count: Int {
        return array.count
    }
}

// Use case - any type
var queue = Queue<String>()
queue.enqueue("Maria")
queue.enqueue("Jim")
queue.enqueue("Gloria")

queue.peek()
queue.count
