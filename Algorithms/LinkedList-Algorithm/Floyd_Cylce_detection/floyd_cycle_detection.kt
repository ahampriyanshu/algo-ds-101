class LinkedList<T> {
    class Node<T>(val value: T, var next: Node<T>? = null)

    var head: Node<T>? = null
    private lateinit var tail: Node<T>

    fun insert(item: T) {
        if (head == null) {
            tail = Node(item)
            head = tail
        } else {
            tail.next = Node(item)
            tail = tail.next!!
        }
    }

    fun detectLoop(): Boolean {
        var slowPointer = head?.next
        var fastPointer = head?.next?.next

        while (slowPointer != null && fastPointer != null) {
            if (slowPointer == fastPointer) return true
            slowPointer = slowPointer.next
            fastPointer = fastPointer.next?.next
        }

        return false
    }

    fun forceLoop() {
        tail.next = head
    }
}

fun main() {
    val linkedList = LinkedList<Int>()
    linkedList.apply {
        insert(1)
    }
    println("linkedList has loop: " + linkedList.detectLoop())

    linkedList.forceLoop()
    println("linkedList has loop: " + linkedList.detectLoop())
}