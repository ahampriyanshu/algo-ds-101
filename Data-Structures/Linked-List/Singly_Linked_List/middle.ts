function main() {
    const input: string = window.prompt("Insert the values separated by commas. (I.e.: 1,2,3)");

    const list = new SinglyLinkedList();
    list.push(...input.split(','));
    const middle: NodeCell = list.findMiddle();

    console.log(`The middle of the list is ${middle.val}`);
}

class NodeCell {
    val: string;
    next: NodeCell;

    /**
      * Constructs a NodeCell.
      * @param {string} val - The value of the NodeCell.
      */
    constructor(val: string){
        this.val = val;
        this.next = null;
    }
}

class SinglyLinkedList {
    head: NodeCell;
    tail: NodeCell;

    /**
      * Constructs a SinglyLinkedList.
      */
    constructor(){
        this.head = null;
        this.tail = null;
    }

    /**
      * Push values into the SinglyLinkedList converting them into NodeCells.
      * @param {string[]} values - One or more values to be pushed into the List.
      */
    push(...values: string[]){
        for (const val of values) {
            const newNode = new NodeCell(val);
            if (!this.head) {
                this.head = newNode;
                this.tail = newNode;
            } else {
                this.tail.next = newNode;
                this.tail = newNode;
            }
        }
    }

    /**
      * Find the middle NodeCell of the SinglyLinkedList.
      * @returns {NodeCell} - The NodeCell currently in the middle of the List.
      */
    findMiddle(): NodeCell{
        let slowIterator: NodeCell = this.head;
        let fastIterator: NodeCell = this.head;

        while (fastIterator && fastIterator.next) {
            slowIterator = slowIterator.next;
            fastIterator = fastIterator.next.next;
        }

        return slowIterator;
    }
}
