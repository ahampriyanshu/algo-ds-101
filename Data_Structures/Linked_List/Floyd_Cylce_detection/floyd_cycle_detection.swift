//  floyd_cycle_detection.swift
//
//  Swift implementation of a linked list with cycle detection functionality
//
//  How to run: type on terminal `swift floyd_cycle_detection.swift` and type enter. 
//              The test program will populate two lists, one with loop and one without
//              and will print test both for if theres a loop or not.

// A class representing one node of the list
class Node<T> {

    // public properties
    public var value: T
    public var next: Node<T>?

    // Create a new node with a given value
    public init (value: T) {
        self.value = value
    }

    // Insert an element at the end of the list recursively
    public func insert(_ node: Node<T>) {
        if next == nil {
            next = node
        } else {
            next!.insert(node)
        }
    }

    // Detects if there is a loop on the list using the Floyd`s Cycle-Finding Algorithm
    public func detectLoop() -> Bool {
        var slowPointer = next
        var fastPointer = next?.next 

        // Transverse the list with two pointers going on different speeds.
        // If there is a loop on the list, eventually the fastest pointer will catch up the slower, and they will be equal.
        // If not, eventually they will reach the end of the list.
        while slowPointer != nil && fastPointer != nil {
            if fastPointer! === slowPointer! {
                return true
            }
            slowPointer = slowPointer!.next
            fastPointer = fastPointer!.next?.next
        }
        return false
    }
}

/*********** Testing the detect loop method ***********/

// Adding a print funcionality just so we can see the list elements
extension Node {
    public func description(maxElements n: Int) -> String {
        let string = String(describing: value) + " -> " + (n > 0 ? (next?.description(maxElements: n-1) ?? "(End of list)") : " (list continues...) ")
        return string
    }
}

// Populating a list without loop
let linkedListWithoutLoop = Node(value: "1")
linkedListWithoutLoop.insert(Node(value:"2"))
linkedListWithoutLoop.insert(Node(value:"3"))
linkedListWithoutLoop.insert(Node(value:"4"))
linkedListWithoutLoop.insert(Node(value:"5"))
linkedListWithoutLoop.insert(Node(value:"6"))
linkedListWithoutLoop.insert(Node(value:"7"))

print("List: \(linkedListWithoutLoop.description(maxElements: 20))")
print("Loop detected: \(linkedListWithoutLoop.detectLoop())")


// Populating a list with loop
let linkedListWithLoop = Node(value: "A")
linkedListWithLoop.insert(Node(value:"B"))
linkedListWithLoop.insert(Node(value:"C"))
linkedListWithLoop.insert(Node(value:"D"))
linkedListWithLoop.insert(Node(value:"E"))
linkedListWithLoop.insert(Node(value:"F"))
linkedListWithLoop.insert(linkedListWithLoop)

print("List: \(linkedListWithLoop.description(maxElements: 20))")
print("Loop detected: \(linkedListWithLoop.detectLoop())")