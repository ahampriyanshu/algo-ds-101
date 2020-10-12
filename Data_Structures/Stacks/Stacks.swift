import Foundation

struct Stack<T> {
    private var items: [T] = []
    
    mutating func push(element: T) {
        items.append(element)
    }
    
    mutating func pop() -> T? {
        items.popLast()
    }
    
    func peek() -> T? {
        return items.last
    }
    
    var isEmpty: Bool {
        return items.isEmpty
    }
}

extension Stack: CustomStringConvertible {
    var description: String {
        return items.description
    }
}

var intStack = Stack<Int>()

print(intStack.isEmpty)

intStack.push(element: 1)
intStack.push(element: 2)
intStack.push(element: 3)

print(intStack.description)
print(intStack.isEmpty)

intStack.pop()
print(intStack.peek())

print(intStack.description)

var stringStack = Stack<String>()

print(intStack.isEmpty)

stringStack.push(element: "Hi")
stringStack.push(element: "Person")

print(intStack.isEmpty)
print(stringStack.description)

stringStack.pop()
print(stringStack.peek())

print(stringStack.description)
