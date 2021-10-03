public class SinglyLinkedList {
    Node head, tail;

    public SinglyLinkedList(){
        head = tail = null;
    }

    public boolean isEmpty(){
        return this.tail == null;
    }

    public void addToHead(int info){
        this.head = new Node(info, this.head);
        if(isEmpty()) this.tail = this.head;
    }

    public void addToTail(int info){
        if(isEmpty()){
            this.head = this.tail = new Node(info, null)
        }
        else {
            this.tail.next = new Node(info, null);
            this.tail = this.tail.next;
        }
    }

    public void printList(){
        for(Node temp = this.head; temp != null; temp = temp.next){
            System.out.print(temp.info + " ");
        }
    }
}
