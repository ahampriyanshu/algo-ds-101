import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;
 
public class Main {
    public static void main(String[] args) {
        //get dynamic inputs
        Scanner sc = new Scanner(System.in);
        String[] inputNumbers = sc.nextLine().split(" ");
        
        //define queue
        Queue<Integer> q = new ArrayDeque();
        
        // Add values to queue
        for (String n: inputNumbers)
            q.add(Integer.parseInt(n));
        // Display contents of the queue.
        System.out.println("Elements of queue "
                           + q);
        
        //To view the size of the queue
        int size = q.size();
        System.out.println("Size of queue is: "
                           + size);
                           
                           
        // To remove the head of queue.
        int removedele = q.remove();
        System.out.println("removed element is: "
                           + removedele);
        System.out.println("Elements of queue after remove "
                           + q);    
                 
        // To view the head of queue without removing.
        int head = q.peek();
        System.out.println("head of queue is: "
                           + head);
                           
        //To check if it is empty or not.
        System.out.println("Is queue empty : "
                           + q.isEmpty());
                           
        //clearing the whole queue
        q.clear();
        System.out.println("After clearing queue "
                           + q);
    }
}
