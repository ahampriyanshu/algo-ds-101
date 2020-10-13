class PriorityQueue {
    constructor() {
        this.queue = [];
    }

    // Insert an element into the queue
    enqueue(element, priority) {
        let node = [element, priority];

        if(this.isEmpty()) {
            this.queue.push(node);
            return;
        }

        for(let i = 0; i < this.queue.length; i++) {
            if(node[1] > this.queue[i][1]) {
                this.queue.splice(i, 0, node);
                return;
            }
        }

        this.queue.push(node);
    }

    // Remove the element with the highest priority and return it
    dequeue() {
        return this.queue.shift();
    }
    
    // Return the element with the highest priority
    peek() {
        return this.queue[0];
    }

    // Check if the queue is empty 
    isEmpty() {
        return this.queue.length == 0;
    }

    // Return the number of elements in the queue
    size() {
        return this.queue.length;
    }

    // For debugging purposes
    print() {
        this.queue.forEach(element => {
            console.log(element[0] + "\t" + element[1]);
        });
    }
}

// Example
queue = new PriorityQueue();
queue.enqueue(5, 5);
queue.enqueue("Text", 7);
queue.enqueue(true, 3);
queue.print();
