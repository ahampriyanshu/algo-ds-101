class Node {
    constructor(val){
        this.val = val;
        this.next = null;
    }
}

class SinglyLinkedList {
    constructor(){
        this.head = null;
        this.tail = null;
    }

    push(...values){
        for (const val of values) {
            const newNode = new Node(val);
            if (!this.head) {
                this.head = newNode;
                this.tail = newNode;
            } else {
                this.tail.next = newNode;
                this.tail = newNode;
            }
        }
    }
    
    findMiddle(){
        let slowIterator = this.head;
        let fastIterator = this.head;

        while (fastIterator && fastIterator.next) {
            slowIterator = slowIterator.next;
            fastIterator = fastIterator.next.next;
        }

        return slowIterator;
    }
}


function main() {
    const list = new SinglyLinkedList();
    list.push(1,2,3,4,5);
    const middle = list.findMiddle();
    console.log(`The middle of the list is ${middle.val}`);
}