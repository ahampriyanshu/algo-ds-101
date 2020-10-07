class Queue {
    int front, rear, size;
    int capacity;
    int array[];

    public Queue(int capacity)
    {
        this.capacity = capacity;
        front = this.size = 0;
        rear = capacity - 1;
        array = new int[this.capacity];
    }

    boolean isFull(Queue queue)
    {
        return (queue.size == queue.capacity);
    }

    boolean isEmpty(Queue queue)
    {
        return (queue.size == 0);
    }

    void enqueue(int item)
    {
        if (isFull(this))
            return;
        this.rear = (this.rear + 1)
                % this.capacity;
        this.array[this.rear] = item;
        this.size = this.size + 1;
        System.out.println(item
                + " enqueued to queue");
    }

    int dequeue()
    {
        if (isEmpty(this))
            return Integer.MIN_VALUE;

        int item = this.array[this.front];
        this.front = (this.front + 1)
                % this.capacity;
        this.size = this.size - 1;
        return item;
    }

    int front()
    {
        if (isEmpty(this))
            return Integer.MIN_VALUE;

        return this.array[this.front];
    }

    int rear()
    {
        if (isEmpty(this))
            return Integer.MIN_VALUE;

        return this.array[this.rear];
    }

    public static void main(String[] args)
    {
        Queue myQueue = new Queue(50);

        myQueue.enqueue(12);
        myQueue.enqueue(13);
        myQueue.enqueue(14);
        myQueue.enqueue(15);

        System.out.println(myQueue.dequeue()
                + " dequeued from queue\n");

        System.out.println("Front item is "
                + myQueue.front());

        System.out.println("Rear item is "
                + myQueue.rear());
    }
}
