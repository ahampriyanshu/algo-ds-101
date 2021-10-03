public class StackUsingLL {
    Node head;
    class Node {
        int val;
        Node next;
        int min;

    public Node(int val, int min) {
        this.val = val;
        this.min = min;
        next = null;
        }
    }

    public void push(int x) { // O(1)
        if(head == null){
            head = new Node(x, x);
        }
        else {
            Node node = new Node(x, Math.min(head.min,x));
            node.next = head;
            head = node;
            }
        }

        public void pop() {
        if(head!=null){
            head = head.next;
            }
        }

        public int peek() {
        if(head!=null) {
            return head.val;
            }
        return -1;
        }

        public int getMin() {
        if(head!=null){
            return head.min;
        }
        return -1;
        }

        public void display() {

            // check for stack underflow
            if (head == null) {
                System.out.printf("\nStack Underflow");
            }
            else {
                Node temp = head;
                while (temp != null) {
                    System.out.print(temp.val+" ");
                    temp = temp.next;
                }
                System.out.println("");
            }
        }

    public static void main(String[] args) {
        //object of class
        StackUsingLL stack = new StackUsingLL();

        // insert Stack value
        stack.push(11);
        stack.push(22);
        stack.push(33);
        stack.push(44);

        //print Stack elements
        stack.display();

        // print Top element of Stack
        System.out.printf("\nTop element is %d\n", stack.peek());

        // Delete top element of Stack
        stack.pop();
        stack.pop();

        //print Stack elements after popping elements
        stack.display();

        // print Top element of Stack
        System.out.printf("\nTop element is %d\n", stack.peek());
    }
}