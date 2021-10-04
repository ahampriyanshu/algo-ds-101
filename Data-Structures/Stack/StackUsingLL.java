import java.util.Scanner;

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
        
    public static void operation(StackUsingLL stack) {
    	 System.out.println("Enter the operation");
         System.out.println("1. "+"push");
         System.out.println("2. pop");
         System.out.println("3. peek");
         System.out.println("4. display");
         
         Scanner sc = new Scanner(System.in);
         int input = sc.nextInt();
         
         switch(input) {
         // push into stack
         case 1:
             System.out.println("Enter the number of elements to be pushed");
             int number = sc.nextInt();
             
             System.out.println("Enter the elements");
             while(number-->0) {
             	int element = sc.nextInt();
             	stack.push(element);
             }
             stack.operation(stack);
          // Delete top element of Stack
           case 2:
         	stack.pop();
         	stack.operation(stack);
             
          // print Top element of Stack  
           case 3:
         	  System.out.printf("\nTop element is %d\n", stack.peek());
         	 stack.operation(stack);
             
           //print Stack elements  
           case 4:
         	stack.display();
         	stack.operation(stack);
         	
           case 5:
        	System.out.println("EXIT");
        	System.exit(0);
         	
           default: System.exit(0);
         }
    }

    public static void main(String[] args) {
        //object of class
    	StackUsingLL stack = new StackUsingLL();
        stack.operation(stack);
    }
}
