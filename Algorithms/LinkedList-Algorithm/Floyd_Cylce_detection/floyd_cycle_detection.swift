//  floyd_cycle_detection.swift
//
//  Swift implementation of a linked list with cycle detection functionality
//
//  How to run: type on terminal `swift floyd_cycle_detection.swift` and type enter. 
//              The test program will populate two lists, one with loop and one without
//              and will print test both for if theres a loop or not.

// A class representing one node of the list
class Node<T> {

    // Public properties
    public var value: T
    public var next: Node<T>?

    // Create a new node with a given value
    public init (value: T) {
        self.value = value
    }
}

// A class representing the list
class LinkedList<T> {

    // Current head of list
    var head: Node<T>

    // Create a new list with a given node
    public init(node: Node<T>) {
        head = node
    }

    // Insert a node at the start of the list
    public func insert(_ node: Node<T>) {
        node.next = head
        head = node
    }

    // Detects if there is a loop on the list using the Floyd`s Cycle-Finding Algorithm
    public func detectLoop() -> Bool {
        var slowPointer = head.next
        var fastPointer = head.next?.next 

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
extension LinkedList {
    public func description(maxElements: Int) -> String {
        var count = 0
        var currentNode = Optional(head)
        var listDescription = ""
        while currentNode != nil {
            listDescription += (String(describing: currentNode!.value) + " -> ")
            count += 1
            if count >= maxElements {
                return listDescription + " (list continues...) "
            }
            currentNode = currentNode?.next
        }
        return listDescription + "(End of list)"
    }
}

// Populating a list without loop
let linkedListWithoutLoop = LinkedList(node: Node(value: "1"))
linkedListWithoutLoop.insert(Node(value:"2"))
linkedListWithoutLoop.insert(Node(value:"3"))
linkedListWithoutLoop.insert(Node(value:"4"))
linkedListWithoutLoop.insert(Node(value:"5"))
linkedListWithoutLoop.insert(Node(value:"6"))
linkedListWithoutLoop.insert(Node(value:"7"))

print("List: \(linkedListWithoutLoop.description(maxElements: 20))")
print("Loop detected: \(linkedListWithoutLoop.detectLoop())")


// Populating a list with loop
let listTail = Node(value: "A")
let linkedListWithLoop = LinkedList(node: listTail)
linkedListWithLoop.insert(Node(value:"B"))
linkedListWithLoop.insert(Node(value:"C"))
linkedListWithLoop.insert(Node(value:"D"))
linkedListWithLoop.insert(Node(value:"E"))
linkedListWithLoop.insert(Node(value:"F"))
linkedListWithLoop.insert(listTail)

print("List: \(linkedListWithLoop.description(maxElements: 20))")
print("Loop detected: \(linkedListWithLoop.detectLoop())")