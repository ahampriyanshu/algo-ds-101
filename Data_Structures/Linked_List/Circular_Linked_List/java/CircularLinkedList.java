public class CircularLinkedList {
    public Node head;
    public Node tail;

    public CircularLinkedList() {
        this.head = this.tail = null;
    }

    public boolean isEmpty() {
        return this.head == null;
    }

    public void addToTail(int el) {
        if (isEmpty()) {
            this.head = new Node(el);
            this.head.next = head;
            this.head.prev = head;
            this.tail = this.head;
        } else {
            this.tail.next = new Node(el, this.tail.next, this.tail);
            this.tail = this.tail.next;
            this.head.prev = this.tail;

        }
    }

    public void printAll() {
        Node temp;
        int i = 0;
        for (temp = head; i < 5; temp = temp.next, i += 1) {
            System.out.println(temp.info + " > " + temp.next.info + " > " + temp.prev.info);
        }
        System.out.println();
    }

}

class Node {
    public int info;
    public Node next;
    public Node prev;

    public Node(int el) {
        this.info = el;
        this.next = null;
        this.prev = null;
    }

    public Node(int el, Node next, Node prev) {
        this.info = el;
        this.next = next;
        this.prev = prev;
    }
}