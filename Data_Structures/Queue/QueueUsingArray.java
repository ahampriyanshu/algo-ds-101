package queueusingarray;
public class QueueUsingArray {
   public static void main(String[] args) {
        /* Create a queue of size 5 */
        Queue q = new Queue(5);
        /* Inserting elements in the queue */
        q.queueEnque(1);
        q.queueEnque(2);
        q.queueEnque(3);
        q.queueEnque(4);
        q.queueEnque(5);
        /* Print queue elements */
        q.queueDisplay();
        /* Delete elements */
        q.queueDeque();
        q.queueDeque();
        /* Print queue elements */
        q.queueDisplay();
    }  
}
class Queue{
    private static int front,rear,size;
    private static int queue[];
    Queue(int c){
        front=rear=0;
        size=c;
        queue = new int[size];
    }
    /* Function to insert an element at the rear of the queue */
    static void queueEnque(int data){
        /* Check whether queue is full or not */
        if(size==rear){
            System.out.println("Queue is Full");
        }
        /* Insert an element at the rear */
        else{
            queue[rear]=data;
            rear++;
        }
    }
    /* Function to delete an element from the front of the queue */
    static void queueDeque(){
        /* Check if queue is empty */
        if(front==rear){
            System.out.println("Queue is Empty");
        }
        /* Shift all the elements from index 2 till rear to the right by one */
        else{
            for(int i=0;i<rear-1;i++){
                queue[i]=queue[i+1];
            }
        }
        /* Decrement Rear */
        rear--;
    }
    /* Print Queue elements */
    static void queueDisplay(){
        if(front==rear){
            System.out.println("Queue is Empty");
        }
        /* Traverse front to rear and print elements */
        System.out.println ();
        for(int i=front;i<rear;i++){
            System.out.print(queue[i]+" ");
        }
    }
    /* Print front of the queue */
    static void queuefront(){
        if(front==rear){
            System.out.println("Queue is Empty");
        }
        System.out.println("Front Element"+" "+queue[front]);
        
   }
    
}

Output: -
1 2 3 4 5
3 4 5
